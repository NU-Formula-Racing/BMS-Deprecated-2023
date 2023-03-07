#include <Arduino.h>

#include <chrono>

#include "GWP-Charger.h"
#include "bms.h"
#include "bms_telemetry.h"
#include "bq_comm.h"
#include "teensy_can.h"
#include "thermistor.h"
#include "virtualTimer.h"

#define serialdebug 1

TeensyCAN<1> hp_can{};
TeensyCAN<2> lp_can{};
TeensyCAN<3> vb_can{};

GWPCharger charger{vb_can};

VirtualTimerGroup timer_group{};

NXFT15XH103FA2B050 thermistor{};
BMS bms{BQ79656{Serial8, 35, thermistor, 20, 16, 2}, 20, 16, charger, timer_group, hp_can, lp_can, vb_can};

void setup()
{
#if serialdebug
    delay(2000);
    Serial.begin(9600);
    Serial.println("Starting...");

#endif
    // put your setup code here, to run once:
    bms.Initialize();
    hp_can.Initialize(ICAN::BaudRate::kBaud1M);
    lp_can.Initialize(ICAN::BaudRate::kBaud1M);
    vb_can.Initialize(ICAN::BaudRate::kBaud1M);
    timer_group.AddTimer(100, []() { bms.Tick(); });
    // delay(1000);
}

void loop() { timer_group.Tick(millis()); }