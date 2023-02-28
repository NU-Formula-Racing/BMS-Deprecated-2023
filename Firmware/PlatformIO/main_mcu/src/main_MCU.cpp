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

const std::chrono::milliseconds kTickPeriod{std::chrono::milliseconds{10}};
static std::chrono::milliseconds next_tick_time{millis()};
void ten_ms_task()
{
    /**
     * You can use and set the CANSignals as if they were SignalType
     *
     */

    // The CANRXMessage automatically gets updated on message reception from the interrupt. Not: in order for this to
    // work, you must periodically call Tick() on the can_bus
    charger.Tick(millis());
    can_bus.Tick();
    Serial.print("Received output voltage: ");
    Serial.println(charger.GetOutputVoltage());
    Serial.print("Received output current: ");
    Serial.println(charger.GetOutputCurrent());
    Serial.print("Received primary temperature: ");
    Serial.println(charger.GetPrimaryTemperature());
    Serial.print("Received secondary temperature: ");
    Serial.println(charger.GetSecondaryTemperature());
    Serial.print("Received input voltage: ");
    Serial.println(charger.GetInputVoltage());
    Serial.print("Received input current: ");
    Serial.println(charger.GetInputCurrent());
    Serial.print("Received power reference: ");
    Serial.println(charger.GetPowerReference());
    Serial.print("Received available power: ");
    Serial.println(charger.GetAvailablePower());
}
void setup()
{
    // put your setup code here, to run once:
    bms.Initialize();
    can_bus.Initialize(ICAN::BaudRate::kBaud1M);
    timer_group.AddTimer(100, ten_ms_task);
    delay(1000);
#if serialdebug
    Serial.begin(115200);
    Serial.println("Starting...");

#endif
}

void loop()
{
    while (std::chrono::milliseconds(millis()) < next_tick_time)
    {
    }
    bms.Tick(kTickPeriod);
    next_tick_time =
        std::chrono::milliseconds(millis()) + kTickPeriod - (std::chrono::milliseconds(millis()) - next_tick_time);
    timer_group.Tick(millis());
}