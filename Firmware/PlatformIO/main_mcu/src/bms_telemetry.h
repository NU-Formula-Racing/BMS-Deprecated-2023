#pragma once

#include "bms_interface.h"
#include "teensy_can.h"
#include "virtualTimer.h"

class BMSTelemetry
{
public:
    BMSTelemetry(ICAN &hp_can_bus,
                 ICAN &vb_can_bus,
                 ICAN &lp_can_bus,
                 VirtualTimerGroup &timer_group,
                 std::vector<float> &voltages,
                 std::vector<float> &temperatures,
                 float &max_discharge_current,
                 float &max_regen_current,
                 float &battery_voltage,
                 std::vector<float> &current,
                 bool &undervoltage_fault,
                 bool &overvoltage_fault,
                 bool &undertemperature_fault,
                 bool &overtemperature_fault,
                 bool &overcurrent_fault,
                 bool &external_kill_fault,
                 IBMS::BMSState &current_state,
                 float &max_cell_temperature,
                 float &min_cell_temperature,
                 float &max_cell_voltage,
                 float &min_cell_voltage)
        : hp_can_bus_{hp_can_bus},
          vb_can_bus_{vb_can_bus},
          lp_can_bus_{lp_can_bus},
          timer_group_{timer_group},
          voltage_values_{voltages},
          temperature_values_{temperatures},
          max_discharge_current_value_{max_discharge_current},
          max_regen_current_value_{max_regen_current},
          battery_voltage_value_{battery_voltage},
          current_value_{current},
          undervoltage_fault_value_{undervoltage_fault},
          overvoltage_fault_value_{overvoltage_fault},
          undertemperature_fault_value_{undertemperature_fault},
          overtemperature_fault_value_{overtemperature_fault},
          overcurrent_fault_value_{overcurrent_fault},
          external_kill_fault_value_{external_kill_fault},
          current_state_{current_state},
          max_cell_temperature_value_{max_cell_temperature},
          min_cell_temperature_value_{min_cell_temperature},
          max_cell_voltage_value_{max_cell_voltage},
          min_cell_voltage_value_{min_cell_voltage}
    {
    }

    void InitializeCAN();

private:
    static const uint16_t kSignalsPerMessage = 7;
    static const uint16_t kNumVoltageMessages = 20;
    static const uint16_t kNumTemperatureMessages = 16;
    static const int kHPTransmitPeriod = 10;
    static const int kVBTransmitPeriod = 10;
    static const int kLPTransmitPeriod = 100;

    ICAN &hp_can_bus_;
    ICAN &vb_can_bus_;
    ICAN &lp_can_bus_;

    VirtualTimerGroup &timer_group_;

    std::vector<float> &voltage_values_;
    std::vector<float> &temperature_values_;
    float &max_discharge_current_value_;
    float &max_regen_current_value_;
    float &battery_voltage_value_;
    std::vector<float> &current_value_;
    bool &undervoltage_fault_value_;
    bool &overvoltage_fault_value_;
    bool &undertemperature_fault_value_;
    bool &overtemperature_fault_value_;
    bool &overcurrent_fault_value_;
    bool &external_kill_fault_value_;
    IBMS::BMSState &current_state_;
    float &max_cell_temperature_value_;
    float &min_cell_temperature_value_;
    float &max_cell_voltage_value_;
    float &min_cell_voltage_value_;

    std::array<ITypedCANSignal<float> *, kNumVoltageMessages * kSignalsPerMessage> voltage_signals_;
    std::array<ITypedCANSignal<float> *, kNumTemperatureMessages * kSignalsPerMessage> temperature_signals_;
    ITypedCANSignal<float> *max_discharge_signal_;
    ITypedCANSignal<float> *max_regen_signal_;
    ITypedCANSignal<float> *battery_voltage_signal_;
    ITypedCANSignal<float> *battery_temperature_signal_;
    ITypedCANSignal<float> *battery_current_signal_;
    ITypedCANSignal<bool> *summary_signal_;
    ITypedCANSignal<bool> *undervoltage_signal_;
    ITypedCANSignal<bool> *overvoltage_signal_;
    ITypedCANSignal<bool> *undertemperature_signal_;
    ITypedCANSignal<bool> *overtemperature_signal_;
    ITypedCANSignal<bool> *overcurrent_signal_;
    ITypedCANSignal<bool> *external_kill_signal_;
    ITypedCANSignal<uint8_t> *state_signal_;
    ITypedCANSignal<float> *max_cell_temperature_signal_;
    ITypedCANSignal<float> *min_cell_temperature_signal_;
    ITypedCANSignal<float> *max_cell_voltage_signal_;
    ITypedCANSignal<float> *min_cell_voltage_signal_;
    ITypedCANSignal<float> *soc_signal_;

    std::array<CANTXMessage<kSignalsPerMessage> *, kNumVoltageMessages> voltage_messages_;
    std::array<CANTXMessage<kSignalsPerMessage> *, kNumTemperatureMessages> temperature_messages_;
    CANTXMessage<5> *hp_soe_message_;
    CANTXMessage<5> *vb_soe_message_;
    CANTXMessage<7> *vb_fault_message_;
    CANTXMessage<7> *lp_fault_message_;
    CANTXMessage<6> *hp_status_message_;
    CANTXMessage<6> *vb_status_message_;

    void AttachVoltageMessages(ICAN &bus,
                               std::array<CANTXMessage<7> *, kNumVoltageMessages> message_ptr_array,
                               uint32_t transmit_period);

    void AttachTemperatureMessages(ICAN &bus,
                                   std::array<CANTXMessage<7> *, kNumTemperatureMessages> message_ptr_array,
                                   uint32_t transmit_period);

    void AttachSOEMessage(ICAN &bus, CANTXMessage<5> *message_ptr, uint32_t transmit_period);

    void AttachFaultMessage(ICAN &bus, CANTXMessage<7> *message_ptr, uint32_t transmit_period);

    void AttachStatusMessage(ICAN &bus, CANTXMessage<6> *message_ptr, uint32_t transmit_period);

    void UpdateSOESignals();
    void UpdateFaultSignals();
    void UpdateStatusSignals();

    void InitializeHPMessages();
    void InitializeVBMessages();
    void InitializeLPMessages();

    void TickHPCAN();
    void TickVBCAN();
    void TickLPCAN();
};

// std array for messages
//
