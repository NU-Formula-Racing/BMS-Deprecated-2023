#include "bms.h"

#include <algorithm>

int BMS::faultPin{-1};

void BMS::CheckFaults()
{
    const float kMaxVoltage = 0;
    const float kMinVoltage = 0;
    const float kMaxCurrent = 0;
    const float kMaxTemp = 0;
    const float kMinTemp = 0;

    overvoltage_fault_ = (max_voltage_ >= kMaxVoltage);
    undervoltage_fault_ = (min_voltage_ <= kMinVoltage);
    overcurrent_fault_ = (current[0] >= kMaxCurrent);
    overtemperature_fault_ = (max_temp_ >= kMaxTemp);
    undertemperature_fault_ = (min_temp_ <= kMinTemp);

    fault = static_cast<BMSFault>(
        overvoltage_fault_ ||
        undervoltage_fault_ ||
        overcurrent_fault_ ||
        overtemperature_fault_ ||
        undertemperature_fault_
    );
}

void BMS::Tick(std::chrono::milliseconds elapsed_time)
{
    // check fault status
    if (fault != BMSFault::kNotFaulted && current_state_ != BMSState::kFault)
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
    max_temp_ = *std::max_element(temperatures.begin(), temperatures.end());
    min_temp_ = *std::min_element(temperatures.begin(), temperatures.end());
    analogWrite(
        coolant_ctrl,
        clamp<uint8_t>(map(max_temp_, 20, 50, 0, 255), 0, 255));  // Current pin is NOT pwm capable - rev board or
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
            max_voltage_ = *std::max_element(voltages.begin(), voltages.end());
            min_voltage_ = *std::min_element(voltages.begin(), voltages.end());
            // send CAN messages with SOE (state of energy)

            // check faults
            CheckFaults();
            break;
        case BMSState::kCharging:
            ProcessCooling();
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
            current_state_ = BMSState::kFault;
            break;
    }
}
