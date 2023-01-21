#pragma once

#include "teensy_can.h"
#include "virtualTimer.h"

const int kHPCANBus = 1;
const int kVerboseCANBus = 2;
const int kLPCANBus = 3;

class BMSTelemetry
{
public:
  BMSTelemetry(TeensyCAN<kVerboseCANBus> verbose_can_bus)
    : verbose_can_bus_{verbose_can_bus}
  {
  }
  void Test();

private:
  TeensyCAN<kVerboseCANBus> verbose_can_bus_;

  VirtualTimerGroup timer_group_{};
};
