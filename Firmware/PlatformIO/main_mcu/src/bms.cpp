#include "bms.h"

#include <algorithm>

// Consts for SoE calculation
const float kDischargeCurrent = 45;
const float kRegenCurrent = 4.2;
const float kCellUndervoltage = 2.5;
const float kCellOvervoltage = 4.2;
const float kInternalResistance = 0.016;
const int kNumCellsParallel = 4; // Is this already defined somewhere else?

int BMS::faultPin{-1};

void BMS::Tick(std::chrono::milliseconds elapsed_time)
{
    // check fault status
    if (fault != BMSFault::kNone && current_state_ != BMSState::kFault)
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
void BMS::GetStateOfEnergy()
{
    // Update min voltage (max already set(?))
    minVoltage = *std::min_element(voltages.begin(), voltages.end());

    float currentPerCell = current[0] / kNumCellsParallel;
    float invResistancePerCell = kNumCellsParallel / kInternalResistance;

    // Find highest and lowest open cell voltage
    float minOpenCircuitVoltage = minVoltage + (currentPerCell * kInternalResistance);
    float maxOpenCircuitVoltage = maxVoltage + (currentPerCell * kInternalResistance);

    // Limit at V_open + I * (R_internal / numCellsParallel) = V_boundary
    //  => I = (numCellsParallel / R_internal) * (V_boundary - V_open)
    minDischargeCurrent = std::min(
        invResistancePerCell * (kCellUndervoltage - minOpenCircuitVoltage),
        kDischargeCurrent
    );
    maxRegenCurrent = std::min(
        invResistancePerCell * (kCellOvervoltage - maxOpenCircuitVoltage),
        kRegenCurrent
    );
}

void BMS::ProcessCooling()
{
    // check temperatures
    bq_.GetTemps(temperatures);
    maxTemp = *std::max_element(temperatures.begin(), temperatures.end());
    analogWrite(
        coolant_ctrl,
        clamp<uint8_t>(map(maxTemp, 20, 50, 0, 255), 0, 255));  // Current pin is NOT pwm capable - rev board or
                                                                // use softpwm, also map ranges may be suboptimal
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
            ProcessCooling();
            // check current
            bq_.GetCurrent(current);

            // check voltages
            bq_.GetVoltages(voltages);
            maxVoltage = *std::max_element(voltages.begin(), voltages.end());
            // send CAN messages with SOE (state of energy)
            break;
        case BMSState::kCharging:
            // cell balancing if charging
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
            shutdownCar();
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
            shutdownCar();
            current_state_ = BMSState::kFault;
            break;
    }
}