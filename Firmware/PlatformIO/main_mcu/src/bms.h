#pragma once
#include <Arduino.h>

#include <algorithm>
#include <chrono>

#include "bq_comm.h"
#include "can_interface.h"
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

    enum class Command : uint8_t
    {
        kNoAction = 0,
        kPrechargeAndCloseContactors = 1,
        kShutdown = 2,
        kClearFaults = 3
    };

    BMS(BQ79656 bq /*  = BQ79656{Serial8, 35} */,
        int num_cells_series,
        int num_thermistors,
        ICAN& hp_can,
        ICAN& lp_can,
        ICAN& vb_can)
        : bq_{bq},
          kNumCellsSeries{num_cells_series},
          kNumThermistors{num_thermistors},
          hp_can_{hp_can},
          lp_can_{lp_can},
          vb_can_{vb_can},
          voltages_{std::vector<float>(kNumCellsSeries)},
          temperatures_{std::vector<float>(kNumThermistors)},
          current_{std::vector<float>(1)}
    {
        command_signal_ = Command::kNoAction;
        hp_can_.RegisterRXMessage(command_message_hp_);
        vb_can_.RegisterRXMessage(command_message_vb_);
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
    }

    void Tick(std::chrono::milliseconds elapsed_time);

    void CalculateSOE();

private:
    BQ79656 bq_;
    ICAN& hp_can_;
    ICAN& lp_can_;
    ICAN& vb_can_;

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

    MakeUnsignedCANSignal(Command, 0, 8, 1, 0) command_signal_{};
    CANRXMessage<1> command_message_hp_{hp_can_, 0x242, command_signal_};
    CANRXMessage<1> command_message_vb_{vb_can_, 0x242, command_signal_};

    std::vector<float> voltages_;
    std::vector<float> temperatures_;
    std::vector<float> current_;

    float max_cell_voltage_;
    float min_cell_voltage_;
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
    uint32_t state_entry_time_{0};

    void ProcessState();
    void ChangeState(BMSState new_state);

    void UpdateValues();

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
