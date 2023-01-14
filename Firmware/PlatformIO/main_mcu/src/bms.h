#pragma once
#include <Arduino.h>

#include <algorithm>
#include <chrono>

#include "bq_comm.h"
#include "teensy_pin_defs.h"

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
          voltages{std::vector<float>(kNumCellsSeries)},
          temperatures{std::vector<float>(kNumThermistors)},
          current{std::vector<float>(1)}
    {
    }

    void Initialize()
    {
        // attach fault interrupts
        for (int i = 0; i < num_kill_pins; i++)
        {
            pinMode(kill_pins[i], INPUT);
            attachInterrupt(digitalPinToInterrupt(kill_pins[i]), faultInterrupt, FALLING);
        }

        // initialize the BQ chip driver
        bq_.Initialize();
    }

    void Tick(std::chrono::milliseconds elapsed_time);
    
    void GetStateOfEnergy();

private:
    BQ79656 bq_;

    const int kNumCellsSeries;
    const int kNumThermistors;

    std::vector<float> voltages;
    std::vector<float> temperatures;
    std::vector<float> current;

    float maxVoltage;
    float minVoltage;
    float maxTemp;
    float minDischargeCurrent;
    float maxRegenCurrent;
    static int faultPin;
    BMSFault fault{BMSFault::kNone};  // error codes: 0=none, 1=UV, 2=OV, 3=UT, 4=OT, 5=OC, 6=external kill

    BMSState current_state_{BMSState::kShutdown};

    void ProcessState();
    void ChangeState(BMSState new_state);

    void ProcessCooling();

#define OT_THRESH 60        // 60C max temp
#define UT_THRESH -40       //-40C min temp
#define UT_THRESH_CHARGE 0  // 0 min temp while charging

    static void shutdownCar()
    {
        // kill the car
        digitalWrite(contactorn_ctrl, LOW);
        digitalWrite(contactorp_ctrl, LOW);
        digitalWrite(contactorprecharge_ctrl, LOW);
        return;
    }

    static void faultInterrupt()
    {
        shutdownCar();

        bool foundFault = 0;
        for (int i = 0; i < num_kill_pins; i++)
        {
            if (!digitalRead(kill_pins[i]))
            {
                faultPin = kill_pins[i];
                break;
            }
        }
        if (!foundFault)
        {
            faultPin = -1;
        }
    }

    void getMaxMinAvgTot(double* arr, int arrSize, double* res)
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
