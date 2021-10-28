#include "bq_comm.h"
#include "CRC16.h"
#include "CRC.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(BQ_FAULT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BQ_FAULT_PIN), shutdownCar, LOW);
  uint8_t *txBuf = getTxBuf();
  txBuf[0] = 0x80;
  txBuf[1] = 0x00;
  txBuf[2] = 0x02;
  txBuf[3] = 0x0F;
  txBuf[4] = 0x0B;
  uint8_t buf[5] = {0x01, 0x00, 0x40, 0xF0, 0xD0};

  int *txDataLen = getTxDataLen();
  txDataLen = 5;

  Serial.begin(115200);
  CRC16 crc;
  //Serial.println(calculateCRC());
  //Serial.println(CRC16.x25(buf, sizeof(buf)));
  //Serial.println(sizeof(buf));
  Serial.println(crc16(buf, 5, 0xC002, 0x0000), HEX);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void shutdownCar() {
  //kill the car
  return;
}
