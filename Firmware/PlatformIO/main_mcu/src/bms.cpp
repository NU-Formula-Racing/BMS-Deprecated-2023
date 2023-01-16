#include "bms.h"

#include <algorithm>

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

void BMS::ProcessCooling()
{
    // check temperatures
    bq_.GetTemps(temperatures_);
    max_temperature_ = *std::max_element(temperatures_.begin(), temperatures_.end());
    analogWrite(coolant_ctrl,
                clamp<uint8_t>(
                    map(max_temperature_, 20, 50, 0, 255), 0, 255));  // Current pin is NOT pwm capable - rev board or
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
            bq_.GetCurrent(current_);

            // check voltages
            bq_.GetVoltages(voltages_);
            max_voltage_ = *std::max_element(voltages_.begin(), voltages_.end());
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