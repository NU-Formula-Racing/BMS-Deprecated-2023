#include "bq_comm.h"
#include "teensy_pin_defs.h"
#define serialdebug 1

void setup() {
  Serial.begin(115200);
  Serial.println("Starting");
  bqInitializeSPI();
}

void loop() {
  //bqGetReg(byte req_type, byte data_size, byte dev_addr, uint16_t reg_addr, byte resp_size)
  uint8_t* bqResponse = bqReadReg(BQ_SINGLE_READ, 0, BRIDGE_COMM_TIMEOUT, 1);
  Serial.println("Response:");
  for (int i = 0; i < 7; i++) {
    Serial.print(bqResponse[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);
}
