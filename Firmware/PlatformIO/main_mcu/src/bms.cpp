#include "bms.h"

#include <algorithm>

bool BMS::carActive{false};
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
            // open contactors
            current_state_ = BMSState::kShutdown;
            break;
        case BMSState::kPrecharge:
            // close negative and precharge contactors
            current_state_ = BMSState::kPrecharge;
            break;
        case BMSState::kActive:
            // close main contactor, open precharge contactor
            current_state_ = BMSState::kActive;
            break;
        case BMSState::kCharging:
            // enable charger?
            current_state_ = BMSState::kCharging;
            break;
        case BMSState::kFault:
            // open contactors
            current_state_ = BMSState::kFault;
            break;
    }
}