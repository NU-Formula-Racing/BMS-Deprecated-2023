#pragma once
#include <Arduino.h>

#include <algorithm>
#include <chrono>

#include "bq_comm.h"
#include "bms_telemetry.h"
#include "teensy_can.h"
#include "teensy_pin_defs.h"

// Consts for SoE calculation
const float kDischargeCurrent = 45;
const float kRegenCurrent = 45;
const float kMaxPowerOutput = 80000;
const float kCellUndervoltage = 2.5;
const float kCellOvervoltage = 4.2;
const float kInternalResistance = 0.016;
const int kNumCellsParallel = 4;

// CAN Bus Numbers
const int kHPBusNumber = 1;
const int kVBBusNumber = 2;
const int kLPBusNumber = 3;

template <typename T>
T clamp(const T& n, const T& lower, const T& upper)
{
    return std::max(lower, std::min(n, upper));
}

class BMS
{
public:
    enum class BMSFault
    {
        kNone = 0,
        kUndervoltage = 1,
        kOvervoltage = 2,
        kUnderTemperature = 3,
        kOverTemperature = 4,
        kOverCurrent = 5,
        kExternalKill = 6
    };

    enum class BMSState
    {
        kShutdown = 0,
        kPrecharge = 1,
        kActive = 2,
        kCharging = 3,
        kFault = 4
    };

    BMS(BQ79656 bq /*  = BQ79656{Serial8, 35} */, int num_cells_series, int num_thermistors)
        : bq_{bq},
          kNumCellsSeries{num_cells_series},
          kNumThermistors{num_thermistors},
          voltages_{std::vector<float>(kNumCellsSeries)},
          temperatures_{std::vector<float>(kNumThermistors)},
          current_{std::vector<float>(1)}
    {
    }

    void Initialize()
    {
        // attach fault interrupts
        for (int i = 0; i < num_kill_pins; i++)
        {
            pinMode(kill_pins[i], INPUT);
            attachInterrupt(digitalPinToInterrupt(kill_pins[i]), FaultInterrupt, FALLING);
        }

        // initialize the BQ chip driver
        bq_.Initialize();

        // initialize BMS telemetry
        telemetry.InitializeCAN();
    }

    void Tick(std::chrono::milliseconds elapsed_time);

    void CalculateSOE();

private:
    BQ79656 bq_;

    const int kNumCellsSeries;
    const int kNumThermistors;

    std::vector<float> voltages_;
    std::vector<float> temperatures_;
    std::vector<float> current_;

    float max_cell_voltage_;
    float min_cell_voltage_;
    float max_cell_temperature_;
    float max_allowed_discharge_current_;
    float max_allowed_regen_current_;
    static int fault_pin_;
    BMSFault fault_{BMSFault::kNone};  // error codes: 0=none, 1=UV, 2=OV, 3=UT, 4=OT, 5=OC, 6=external kill

    BMSState current_state_{BMSState::kShutdown};
    
    TeensyCAN<kHPBusNumber> hp_bus_{};
    TeensyCAN<kVBBusNumber> vb_bus_{};
    TeensyCAN<kLPBusNumber> lp_bus_{};

    VirtualTimerGroup timer_group{};
    BMSTelemetry telemetry{hp_bus_, vb_bus_, lp_bus_, timer_group, voltages_, temperatures_};

    void ProcessState();
    void ChangeState(BMSState new_state);

    void ProcessCooling();

#define OT_THRESH 60        // 60C max temp
#define UT_THRESH -40       //-40C min temp
#define UT_THRESH_CHARGE 0  // 0 min temp while charging

    static void ShutdownCar()
    {
        // kill the car
        digitalWrite(contactorn_ctrl, LOW);
        digitalWrite(contactorp_ctrl, LOW);
        digitalWrite(contactorprecharge_ctrl, LOW);
        return;
    }

    static void FaultInterrupt()
    {
        ShutdownCar();

        bool foundFault = 0;
        for (int i = 0; i < num_kill_pins; i++)
        {
            if (!digitalRead(kill_pins[i]))
            {
                fault_pin_ = kill_pins[i];
                break;
            }
        }
        if (!foundFault)
        {
            fault_pin_ = -1;
        }
    }

    void GetMaxMinAvgTot(double* arr,
                         int arrSize,
                         double* res)  // may be unused/deleted or replaced with a different function/implementation
    {
        double currMax = arr[0];
        double currMin = arr[0];
        double currTot = arr[0];
        for (int i = 1; i < arrSize; i++)
        {
            currMax = max(currMax, arr[i]);
            currMin = min(currMin, arr[i]);
            currTot += arr[i];
        }
        res[0] = currMax;
        res[1] = currMin;
        res[2] = currTot / arrSize;
        res[3] = currTot;
    }
};
