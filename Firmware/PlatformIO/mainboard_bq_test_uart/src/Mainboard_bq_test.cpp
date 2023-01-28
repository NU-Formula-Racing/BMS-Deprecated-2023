#include <Arduino.h>

#define BQTEST
// #define serialdebug 1

#include "bq_comm.h"
#include "teensy_pin_defs.h"
#include "thermistor.h"

NXFT15XH103FA2B050 bq_thermistor{};
BQ79656 bq(Serial2, 8, bq_thermistor);
std::vector<float> voltages(20, 0);
std::vector<float> temperatures(16, 0);
std::vector<float> current(1, 0);

void setup()
{
    Serial.begin(9600);
    delay(5000);
    Serial.println("Starting");
    /* Serial2.begin(1000000, SERIAL_8N1_HALF_DUPLEX);
    while (1)
    {
        Serial2.println("Test");
        delay(100);
    } */
    // delay(5);
    bq.SetStackSize(2);
    bq.Initialize();
    bq.SetProtectors(4.20f, 2.50f, 60.0f, -40.0f);
    delay(1000);
}

void loop()
{
    // bqGetReg(byte req_type, byte data_size, byte dev_addr, uint16_t reg_addr, byte resp_size)
    /* uint8_t* bqResponse = bqReadReg(BQ_SINGLE_READ, 0, BRIDGE_COMM_TIMEOUT, 1);
     Serial.println("Response:");
     for (int i = 0; i < 7; i++) {
       Serial.print(((uint8_t[][176])bqResponse)[0][i], HEX);
       Serial.print(" ");
     }
     Serial.println();
     delay(1000);*/
    std::vector<byte> byteArr{0b0010010};
    // bq.Comm(BQ79656::request_type::SINGLE_WRITE, 1, 0, BRIDGE_COMM_TIMEOUT, byteArr);

    // Stack test
    Serial.println("Stack test");
    // Serial.println("Test auto-addressing");
    // bq.AutoAddressing(1);

    Serial.println("Test read voltages");
    bq.GetVoltages(voltages);
    Serial.print(voltages[0]);
    for (size_t i = 1; i < voltages.size(); i++)
    {
        Serial.print(", ");
        Serial.print(voltages[i]);
    }
    Serial.println("\nDone");
    delay(1000);
    Serial.println("Test read current" /*and temperatures*/);
    while (1)
    {
        Serial.print("Current: ");
        bq.GetCurrent(current);
        Serial.print(current[0]);
        Serial.println("A");
        delay(500);
        bq.GetTemps(temperatures);
        Serial.println("Temperatures: ");
        Serial.print(temperatures[0]);
        Serial.print("C");
        for (size_t i = 1; i < temperatures.size(); i++)
        {
            Serial.print(", ");
            Serial.print(temperatures[i]);
            Serial.print("C");
        }
    }
    delay(1000);
    // run simple balancing to test LEDs (only works with cell voltage > 4V)
    bq.StartBalancingSimple();
    delay(10000);

    // force first 5 evens and odds to alternate balancing
    /* for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            voltages[2 * j + i % 2] = 4.3f;
            voltages[2 * j + (i + 1) % 2] = 3.0f;
        }
        bq.ProcessBalancing(voltages);
        delay(500);
    } */

    delay(10000);
}
