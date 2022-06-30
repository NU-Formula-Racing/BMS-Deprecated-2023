#include <Arduino.h>

#define BQTEST
#define serialdebug

#include "bq_comm.h"
#include "teensy_pin_defs.h"

extern uint8_t bqRespBufs[num_segments + 1][176];
BQ79656 bq(Serial8, 35);

void setup()
{
    Serial.begin(115200);
    Serial.println("Starting");
    bq.Initialize();
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
    byte byteArr[] = {0b0010010};
    // bq.Comm(BQ79656::request_type::SINGLE_WRITE, 1, 0, BRIDGE_COMM_TIMEOUT, byteArr);

    // Stack test
    Serial.println("Stack test");
    Serial.println("Test auto-addressing");
    byteArr[0] = 0x00;
    bq.Comm(BQ79656::RequestType::BROAD_WRITE, 1, 0, BQ79656::RegisterAddress::OTP_ECC_TEST, byteArr);
    byteArr[0] = 0x01;
    bq.Comm(BQ79656::RequestType::BROAD_WRITE, 1, 0, BQ79656::RegisterAddress::CONTROL1, byteArr);
    byteArr[0] = 0x00;
    bq.Comm(BQ79656::RequestType::BROAD_WRITE, 1, 0, BQ79656::RegisterAddress::DIR0_ADDR, byteArr);
    byteArr[0] = 0x01;
    bq.Comm(BQ79656::RequestType::BROAD_WRITE, 1, 0, BQ79656::RegisterAddress::DIR0_ADDR, byteArr);
    byteArr[0] = 0x00;
    // bqComm(BQ_SINGLE_WRITE, 1, 0, BRIDGE_COMM_CTRL, byteArr);
    byteArr[0] = 0x02;
    bq.Comm(BQ79656::RequestType::BROAD_WRITE, 1, 0, BQ79656::RegisterAddress::COMM_CTRL, byteArr);
    byteArr[0] = 0x03;
    bq.Comm(BQ79656::RequestType::SINGLE_WRITE, 1, 1, BQ79656::RegisterAddress::COMM_CTRL, byteArr);
    bq.DummyReadReg(BQ79656::RequestType::BROAD_READ, 0, BQ79656::RegisterAddress::OTP_ECC_TEST, 1);
    Serial.println("Auto-addressing finished. Testing single read:");
    // bqReadReg(BQ_SINGLE_READ, 0, BRIDGE_COMM_TIMEOUT, 1);
    bq.ReadReg(BQ79656::RequestType::SINGLE_READ, 1, BQ79656::RegisterAddress::COMM_CTRL, 1);

    Serial.println("Enabling balance with 300s timer");

    // bqWakeChip();
    // send wake

    // byteArr[0] = 0b00100000;
    // bqComm(BQ_SINGLE_WRITE, 1, 0, BRIDGE_CONTROL1, byteArr);
    delay(5);

    // sync DLL
    for (byte i = 0; i < 8; i++)
    {
        byteArr[0] = 0x00;
        bq.Comm(BQ79656::RequestType::STACK_WRITE, 1, 0, static_cast<BQ79656::RegisterAddress>(0x343 + i), byteArr);
    }

    int seriesPerSegment = num_series / num_segments;
    // set up balancing time control registers to 300s (0x04)
    byte balTimes[seriesPerSegment] = {0x04};
    bq.Comm(BQ79656::RequestType::STACK_WRITE,
            seriesPerSegment,
            0,
            static_cast<BQ79656::RegisterAddress>(static_cast<uint16_t>(BQ79656::RegisterAddress::CB_CELL1_CTRL) + 1
                                                  - seriesPerSegment),
            balTimes);

    // start balancing with AUTO_BAL to automatically cycle between even/odd
    byte startBal[] = {0b00000011};
    bq.Comm(BQ79656::RequestType::STACK_WRITE, 1, 0, BQ79656::RegisterAddress::BAL_CTRL2, startBal);
    delay(50000);

    // bqAutoAddressing(1);
    // byte byteArr[] = {0b00100000};
    // bqComm(BQ_SINGLE_WRITE, 1, 0, BRIDGE_CONTROL1, byteArr);
    // bqSetStackSize(1);

    /*while (1) {
      byte byteArr[] = {0};
      bqComm(BQ_BROAD_READ, 0, 0, 0x032F, byteArr);
      bqCommClear();
      delay(1);
    }*/

    /*bqReadReg(BQ_BROAD_READ, 0, 0x032F, 1);
    for (int i = 0; i < 7; i++) {
      Serial.print(((uint8_t[][176])bqResponse)[0][i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    for (int i = 0; i < 7; i++) {
      Serial.print(((uint8_t[][176])bqResponse)[1][i], HEX);
      Serial.print(" ");
    }
    Serial.println();*/
    delay(10000);
}
