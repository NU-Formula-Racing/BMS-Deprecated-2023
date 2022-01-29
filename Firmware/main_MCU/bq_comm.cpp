#include "bq_comm.h"
#include "Crc16.h"

uint8_t txBuf[176];
int txDataLen = 0;
uint8_t rxBuf[176];
int rxDataLen = 0;

Crc16 crc;

uint16_t calculateCRC() {
  return crc.Modbus(txBuf, 0, txDataLen);
}

bool verifyCRC() {
  return crc.Modbus(rxBuf, 0, rxDataLen) == 0;
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

void getVoltages(float* voltages) {
  //read voltages from battery

  //fill in num_series voltages to array
  return;
}

void getTemps(float* temps) {
  //read temps from battery

  //fill in num_thermo temps to array
  return;
}
