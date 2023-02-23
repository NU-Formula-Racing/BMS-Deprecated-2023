#include "bms.h"

#include <algorithm>
#include <numeric>

int BMS::fault_pin_{-1};

void BMS::Tick(std::chrono::milliseconds elapsed_time)
{
    // check fault status
    if (fault_ != BMSFault::kNone && current_state_ != BMSState::kFault)
    {
#if serialdebug
        Serial.println("Fault:" + fault);
#endif
        ChangeState(BMSState::kFault);
    }

    // log to SD, send to ESP, send to CAN
    // todo
}

// Find maximum discharge and regen current
void BMS::CalculateSOE()
{
    float current_per_cell = current_[0] / kNumCellsParallel;
    float internal_resistance_per_series_element = kInternalResistance / kNumCellsParallel;

    // Find highest and lowest open circuit voltage
    float min_open_circuit_voltage = min_cell_voltage_ + (current_per_cell * kInternalResistance);
    float max_open_circuit_voltage = max_cell_voltage_ + (current_per_cell * kInternalResistance);

    // Limit at V_open + I * (R_internal / numCellsParallel) = V_boundary
    //  => I = (numCellsParallel / R_internal) * (V_boundary - V_open)
    float max_discharge_voltage_delta = min_open_circuit_voltage - kCellUndervoltage;
    float max_regen_voltage_delta = kCellOvervoltage - max_open_circuit_voltage;
    float uncapped_discharge_current = max_discharge_voltage_delta / internal_resistance_per_series_element;
    float uncapped_regen_current = max_regen_voltage_delta / internal_resistance_per_series_element;

    // I = P / V
    float pack_voltage = std::accumulate(voltages_.begin(), voltages_.end(), 0);
    float power_capped_current = kMaxPowerOutput / pack_voltage;

    max_allowed_discharge_current_ = std::min({uncapped_discharge_current, power_capped_current, kDischargeCurrent});
    max_allowed_regen_current_ = std::min(uncapped_regen_current, kRegenCurrent);
}

void BMS::ProcessCooling()
{
    // check temperatures
    bq_.GetTemps(temperatures_);
    max_cell_temperature_ = *std::max_element(temperatures_.begin(), temperatures_.end());
    min_cell_temperature_ = *std::min_element(temperatures_.begin(), temperatures_.end());
    analogWrite(
        coolant_ctrl,
        clamp<uint8_t>(
            map(max_cell_temperature_, 20, 50, 0, 255), 0, 255));  // Current pin is NOT pwm capable - rev board or
                                                                   // use softpwm, also map ranges may be suboptimal
}

void BMS::UpdateValues()
{
    ProcessCooling();
    bq_.GetCurrent(current_);
            // check voltages
    bq_.GetVoltages(voltages_);
    max_cell_voltage_ = *std::max_element(voltages_.begin(), voltages_.end());
    min_cell_voltage_ = *std::min_element(voltages_.begin(), voltages_.end());
}

void BMS::ProcessState()
{
    switch (current_state_)
    {
        case BMSState::kShutdown:
            // check for command to go to active
            break;
        case BMSState::kPrecharge:
            // check precharge voltage, go to fault if timeout
            break;
        case BMSState::kActive:
            UpdateValues();
            if (max_cell_temperature_ > OT_THRESH)
            {
                ChangeState(BMSState::kShutdown);
            }

            else if (min_cell_temperature_ < UT_THRESH)
            {
                ChangeState(BMSState::kShutdown);
            }
            // check current
            if (max_cell_voltage_ > kCellOvervoltage)
            {
                ChangeState(BMSState::kShutdown);
            }
            if (min_cell_voltage_ < kCellUndervoltage)
            {
                ChangeState(BMSState::kShutdown);
            }

            // send CAN messages with SOE (state of energy)
            break;
        case BMSState::kCharging:
            // cell balancing if charging
            bq_.ProcessBalancing(voltages_);
            UpdateValues();
            if (max_cell_temperature_ > OT_THRESH)
            {
                ChangeState(BMSState::kShutdown);
            }

            if (min_cell_temperature_ < UT_THRESH_CHARGE)
            {
                ChangeState(BMSState::kCharging);
            }
            
            if (max_cell_voltage_ > kCellOvervoltage)
            {
                ChangeState(BMSState::kShutdown);
            }

            if (min_cell_voltage_ < kCellUndervoltage)
            {
                ChangeState(BMSState::kCharging);
            }
            // todo
            break;
        case BMSState::kFault:
            // check for clear faults command
            break;
    }
}

void BMS::ChangeState(BMSState new_state)
{
    switch (new_state)
    {
        case BMSState::kShutdown:
            ShutdownCar();
            current_state_ = BMSState::kShutdown;
            break;
        case BMSState::kPrecharge:
            digitalWrite(contactorn_ctrl, HIGH);
            digitalWrite(contactorprecharge_ctrl, HIGH);  // precharge, but don't turn on car yet
            current_state_ = BMSState::kPrecharge;
            break;
        case BMSState::kActive:
            digitalWrite(contactorp_ctrl, HIGH);         // turn on car
            digitalWrite(contactorprecharge_ctrl, LOW);  // disable precharge when car is running
            current_state_ = BMSState::kActive;
            break;
        case BMSState::kCharging:
            // enable charger?
            current_state_ = BMSState::kCharging;
            break;
        case BMSState::kFault:
            // open contactors
            ShutdownCar();
            current_state_ = BMSState::kFault;
            break;
    }
}