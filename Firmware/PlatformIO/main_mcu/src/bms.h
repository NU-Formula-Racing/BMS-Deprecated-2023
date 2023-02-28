#pragma once
#include <Arduino.h>

#include <algorithm>
#include <chrono>

#include "bms_interface.h"
#include "bms_telemetry.h"
#include "bq_comm.h"
#include "teensy_can.h"
#include "teensy_pin_defs.h"

template <typename T>
T clamp(const T& n, const T& lower, const T& upper)
{
    return std::max(lower, std::min(n, upper));
}

class BMS : IBMS
{
public:
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

    // Consts for SoE calculation + Fault Detection
    const int kNumCellsParallel{4};
    const float kDischargeCurrent{45.0f};
    const float kRegenCurrent{45.0f};
    const float kMaxPowerOutput{80000.0f};
    const float kCellUndervoltage{2.5f};
    const float kCellOvervoltage{4.2f};
    const float kInternalResistance{0.016f};
    const float kOvercurrent{180.0f};
    const float kOvertemp{60.0f};
    const float kUndertemp{-40.0f};

    // CAN Bus Numbers
    static const int kHPBusNumber{1};
    static const int kVBBusNumber{2};
    static const int kLPBusNumber{3};

    std::vector<float> voltages_;
    std::vector<float> temperatures_;
    std::vector<float> current_;

    float max_cell_voltage_;
    float min_cell_voltage_;
    float pack_voltage_;
    float max_cell_temperature_;
    float min_cell_temperature_;
    float max_allowed_discharge_current_;
    float max_allowed_regen_current_;

    bool undervoltage_fault_{false};
    bool overvoltage_fault_{false};
    bool undertemperature_fault_{false};
    bool overtemperature_fault_{false};
    bool overcurrent_fault_{false};
    bool external_kill_fault_{false};

    static int fault_pin_;
    BMSFault fault_{BMSFault::kNotFaulted};

    BMSState current_state_{BMSState::kShutdown};

    TeensyCAN<kHPBusNumber> hp_bus_{};
    TeensyCAN<kVBBusNumber> vb_bus_{};
    TeensyCAN<kLPBusNumber> lp_bus_{};

    VirtualTimerGroup timer_group{};
    BMSTelemetry telemetry{hp_bus_,
                           vb_bus_,
                           lp_bus_,
                           timer_group,
                           voltages_,
                           temperatures_,
                           max_allowed_discharge_current_,
                           max_allowed_regen_current_,
                           pack_voltage_,
                           current_,
                           undervoltage_fault_,
                           overvoltage_fault_,
                           undertemperature_fault_,
                           overtemperature_fault_,
                           overcurrent_fault_,
                           external_kill_fault_,
                           current_state_,
                           max_cell_temperature_,
                           min_cell_temperature_,
                           max_cell_voltage_,
                           min_cell_voltage_};

    void ProcessState();
    void ChangeState(BMSState new_state);

    void ProcessCooling();

    void CheckFaults();

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
