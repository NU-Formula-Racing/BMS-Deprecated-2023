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
    enum class BMSFault : bool
    {
        kNotFaulted = 0,
        kFaulted = 1,
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
            attachInterrupt(digitalPinToInterrupt(kill_pins[i]), faultInterrupt, FALLING);
        }

        // initialize the BQ chip driver
        bq_.Initialize();
    }

    void Tick(std::chrono::milliseconds elapsed_time);

private:
    BQ79656 bq_;

    const int kNumCellsSeries;
    const int kNumThermistors;

    const float kUndertemperatureThreshold = -40;      //-40C min temp
    const float kOvertemperatureThreshold = 60;        // 60C max temp
    const float kUndertemperatureThresholdCharge = 0;  // 0 min temp while charging

    std::vector<float> voltages_;
    std::vector<float> temperatures_;
    std::vector<float> current_;

    float max_voltage_;
    float min_voltage_;
    float max_temp_;
    float min_temp_;

    bool undervoltage_fault_{false};
    bool overvoltage_fault_{false};
    bool undertemperature_fault_{false};
    bool overtemperature_fault_{false};
    bool overcurrent_fault_{false};
    bool external_kill_fault_{false};

    static int fault_pin_;
    BMSFault fault_{BMSFault::kNotFaulted};

    BMSState current_state_{BMSState::kShutdown};

    void ProcessState();
    void ChangeState(BMSState new_state);

    void ProcessCooling();

    void CheckFaults();

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
                fault_pin_ = kill_pins[i];
                break;
            }
        }
        if (!foundFault)
        {
            fault_pin_ = -1;
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
