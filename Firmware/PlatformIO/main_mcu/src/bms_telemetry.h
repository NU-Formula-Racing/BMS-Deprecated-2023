#pragma once

#include "teensy_can.h"
#include "virtualTimer.h"

const uint16_t kSignalsPerMessage = 7;
const uint16_t kNumVoltageMessages = 20;
const uint16_t kNumTemperatureMessages = 16;
const int kHPTransmitPeriod = 10;
const int kVBTransmitPeriod = 10;
const int kLPTransmitPeriod = 100;

class BMSTelemetry
{
public:
  BMSTelemetry(
    ICAN &hp_can_bus,
    ICAN &vb_can_bus,
    ICAN &lp_can_bus,
    VirtualTimerGroup &timer_group,
    std::vector<float> &voltages,
    std::vector<float> &temperatures,
    std::vector<float> &current,
    float &max_discharge_current,
    float &max_regen_current
  )
    : hp_can_bus_{hp_can_bus},
      vb_can_bus_{vb_can_bus},
      lp_can_bus_{lp_can_bus},
      timer_group_{timer_group},
      voltages_{voltages},
      temperatures_{temperatures},
      current_{current},
      max_discharge_current_{max_discharge_current},
      max_regen_current_{max_regen_current}
  {
  }

  void InitializeCAN();
private:
  ICAN &hp_can_bus_;
  ICAN &vb_can_bus_;
  ICAN &lp_can_bus_;

  VirtualTimerGroup &timer_group_;

  std::vector<float> &voltages_;
  std::vector<float> &temperatures_;
  std::vector<float> &current_;
  float &max_discharge_current_;
  float &max_regen_current_;

  std::array<ITypedCANSignal<float>*, kNumVoltageMessages * kSignalsPerMessage> voltage_signals_;
  std::array<ITypedCANSignal<float>*, kNumTemperatureMessages * kSignalsPerMessage> temperature_signals_;
  std::array<ITypedCANSignal<float>*, 1> current_signal_;
  ITypedCANSignal<float>* max_discharge_signal_;
  ITypedCANSignal<float>* max_regen_signal_;

  std::array<CANTXMessage<kSignalsPerMessage> *, kNumVoltageMessages> voltage_messages_;
  std::array<CANTXMessage<kSignalsPerMessage> *, kNumTemperatureMessages> temperature_messages_;
  std::array<CANTXMessage<1> *, 1> current_message_;
  CANTXMessage<2>* SOE_message_;
  
  void TickHPCAN();
  void TickVBCAN();
  void CreateHPMessages();
  void CreateVBMessages();
};

// std array for messages
// 
