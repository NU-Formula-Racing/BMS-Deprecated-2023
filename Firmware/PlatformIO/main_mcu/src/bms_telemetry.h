#pragma once

#include "teensy_can.h"
#include "virtualTimer.h"

const uint16_t kSignalsPerMessage = 7;
const uint16_t kNumVoltageMessages = 20;
const uint16_t kNumTemperatureMessages = 16;
const int kTransmitPeriod = 10;

class BMSTelemetry
{
public:
  BMSTelemetry(
    ICAN &hp_can_bus,
    ICAN &vb_can_bus,
    ICAN &lp_can_bus,
    VirtualTimerGroup &timer_group
  )
    : hp_can_bus_{hp_can_bus},
      vb_can_bus_{vb_can_bus},
      lp_can_bus_{lp_can_bus},
      timer_group_{timer_group}
  {
  }

  void InitializeCAN();
private:
  ICAN &hp_can_bus_;
  ICAN &vb_can_bus_;
  ICAN &lp_can_bus_;

  VirtualTimerGroup timer_group_;

  std::array<ICANSignal *, kSignalsPerMessage * kNumVoltageMessages> voltage_signals_;
  std::array<ICANSignal *, kSignalsPerMessage * kNumTemperatureMessages> temperature_signals_;

  std::array<CANTXMessage<kSignalsPerMessage> *, kNumVoltageMessages> voltage_messages_;
  std::array<CANTXMessage<kSignalsPerMessage> *, kNumTemperatureMessages> temperature_messages_;
  // single current message
  
  void CreateVerboseMessages();
};

// std array for messages
// 
