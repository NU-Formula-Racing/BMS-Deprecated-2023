#include <Arduino.h>

#include <chrono>

#include "bms.h"
#include "bq_comm.h"
#include "thermistor.h"
#include "bms_telemetry.h"

#define serialdebug 1

NXFT15XH103FA2B050 thermistor{};
BMS bms{BQ79656{Serial8, 35, thermistor}, 140, 112};

const std::chrono::milliseconds kTickPeriod{std::chrono::milliseconds{10}};
static std::chrono::milliseconds next_tick_time{millis()};

void setup()
{
// put your setup code here, to run once:
#if serialdebug
    Serial.begin(115200);
    Serial.println("Starting...");
#endif

    bms.Initialize();
}

void loop()
{
    while (std::chrono::milliseconds(millis()) < next_tick_time)
    {
    }
    bms.Tick(kTickPeriod);
    next_tick_time =
        std::chrono::milliseconds(millis()) + kTickPeriod - (std::chrono::milliseconds(millis()) - next_tick_time);
}