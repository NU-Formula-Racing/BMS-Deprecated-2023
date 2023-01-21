#pragma once

#include "teensy_can.h"
#include "virtualTimer.h"

const int kHPCANBus = 1;
const int kVerboseCANBus = 2;
const int kLPCANBus = 3;

class BMSTelemetry
{
public:
  BMSTelemetry(
    TeensyCAN<kHPCANBus> hp_can_bus,
    TeensyCAN<kVerboseCANBus> verbose_can_bus,
    TeensyCAN<kLPCANBus> lp_can_bus
  )
    : hp_can_bus_{hp_can_bus},
      verbose_can_bus_{verbose_can_bus},
      lp_can_bus_{lp_can_bus}
  {
  }
private:
  TeensyCAN<kHPCANBus> hp_can_bus_;
  TeensyCAN<kVerboseCANBus> verbose_can_bus_;
  TeensyCAN<kLPCANBus> lp_can_bus_;

  VirtualTimerGroup timer_group_{};
};
