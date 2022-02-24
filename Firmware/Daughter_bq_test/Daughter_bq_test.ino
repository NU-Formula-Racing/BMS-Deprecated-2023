#include "bq_comm.h"
#include "teensy_pin_defs.h"
#define serialdebug 1

extern uint8_t bqRespBufs[num_segments+1][176];

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  Serial2.begin(1000000, SERIAL_8N2);
  bqInitializeSPI();
}

void loop() {
  //bqGetReg(byte req_type, byte data_size, byte dev_addr, uint16_t reg_addr, byte resp_size)
  uint8_t* bqResponse = bqReadReg(BQ_SINGLE_READ, 0, STACK_DIE_ID1, 1);
  Serial.println("Response:");
  for (int i = 0; i < 7; i++) {
    Serial.print(((uint8_t[][176])bqResponse)[0][i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);
  
  //Stack test
  /*Serial.println("Stack test");
  bqAutoAddressing(1);
  //byte byteArr[] = {0b00100000};
  //bqComm(BQ_SINGLE_WRITE, 1, 0, BRIDGE_CONTROL1, byteArr);
  //bqSetStackSize(1);

  /*while (1) {
    byte byteArr[] = {0};
    bqComm(BQ_BROAD_READ, 0, 0, 0x032F, byteArr);
    bqCommClear();
    delay(1);
  }*/
  /*
  bqReadReg(BQ_BROAD_READ, 0, 0x032F, 1);
  for (int i = 0; i < 7; i++) {
    Serial.print(((uint8_t[][176])bqResponse)[0][i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  for (int i = 0; i < 7; i++) {
    Serial.print(((uint8_t[][176])bqResponse)[1][i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  delay(10000);*/
}
