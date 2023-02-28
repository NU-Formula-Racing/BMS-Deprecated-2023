#include <Arduino.h>

#include <chrono>

#include "bms.cpp"
#include "bms.h"
#include "bq_comm.h"
#include "teensy_can.h"
#include "thermistor.h"
#include "virtualTimer.h"

#define serialdebug 1

TeensyCAN<1> hp_can{};
TeensyCAN<2> lp_can{};
TeensyCAN<3> vb_can{};

NXFT15XH103FA2B050 thermistor{};
BMS bms{BQ79656{Serial8, 35, thermistor}, 140, 112, hp_can, lp_can, vb_can};

VirtualTimerGroup timer_group{};

void setup()
{
    // put your setup code here, to run once:
    bms.Initialize();
    can_bus.Initialize(ICAN::BaudRate::kBaud1M);
    timer_group.AddTimer(100, []() { bms.Tick(); });
    delay(1000);
#if serialdebug
    Serial.begin(9600);
    Serial.println("Starting...");

#endif
}

void loop() { timer_group.Tick(millis()); }