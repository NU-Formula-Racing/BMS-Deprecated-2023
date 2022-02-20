#include "bq_comm.h"
#include "Crc16.h"

uint8_t bqBuf[176];
int bqBufDataLen = 0;

Crc16 crc;

void bqInitializeSPI() {
  SPI.begin();

  /*
    MOSI: pin 11
    MISO: pin 12
    SCK: pin 13
   */

  //initialize data ready and chip select pins
  pinMode(spi_rdy_pin_bq, INPUT);
  pinMode(cs_bq, OUTPUT);

  //send commands to start/configure stack
  //todo
  
}

uint16_t calculateCRC() {
  return crc.Modbus(txBuf, 0, txDataLen);
}

bool verifyCRC() {
  return crc.Modbus(rxBuf, 0, rxDataLen) == 0;
}

uint8_t* bqGetTxBuf() {
  return txBuf;
}

uint8_t* bqGetRxBuf() {
  return rxBuf;
}

int* bqGetTxDataLen() {
  return &txDataLen;
}

int* bqGetRxDataLen() {
  return &rxDataLen;
}

void bqGetVoltages(double* voltages) {
  //read voltages from battery

  //fill in num_series voltages to array
  return;
}

void bqGetTemps(double* temps) {
  //read temps from battery

  //fill in num_thermo temps to array
  return;
}

void bqGetCurrent(double* current) {
  //read current from battery

  return;
}

void bqWakeChip() {
  //Output a pulse of low MOSI for ~2.5ms to wake chip
  digitalWrite(cs_bq, LOW);
  SPI.beginTransaction(SPISettings(bq_spi_freq, MSBFIRST, SPI_MODE0));
  int wakeBytes = ((bq_spi_freq/8)*(2.5/1000));
  byte wakeBuf[wakeBytes] = {0};
  SPI.transfer(wakeBuf, wakeBytes);
  SPI.endTransaction();
  digitalWrite(cs_bq, HIGH);
}

void bqCommClear() {
  //Output one byte of 0 to reset comm interface
  digitalWrite(cs_bq, LOW);
  SPI.beginTransaction(SPISettings(bq_spi_freq, MSBFIRST, SPI_MODE0));
  SPI.transfer(0x00);
  SPI.endTransaction();
  digitalWrite(cs_bq, HIGH);
}
