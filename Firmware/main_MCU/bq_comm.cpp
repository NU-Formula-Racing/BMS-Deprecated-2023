#include "bq_comm.h"

uint8_t txBuf[176];
int txDataLen = 0;
uint8_t rxBuf[176];
int rxDataLen = 0;

FastCRC16 CRC16;

uint16_t calculateCRC() {
  return CRC16.modbus(txBuf, txDataLen);
}

bool verifyCRC() {
  return CRC16.modbus(rxBuf, rxDataLen) == 0;
}

uint8_t* getTxBuf() {
  return txBuf;
}

uint8_t* getRxBuf() {
  return rxBuf;
}

int* getTxDataLen() {
  return &txDataLen;
}

int* getRxDataLen() {
  return &rxDataLen;
}
