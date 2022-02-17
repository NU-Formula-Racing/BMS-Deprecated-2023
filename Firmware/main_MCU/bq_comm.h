#include "bq79600_reg_defs.h"
#include "bq79656_reg_defs.h"
#include "bq_pin_defs.h"
#include <stdbool.h>
#include <Arduino.h>
#include <SPI.h>


void bqInitializeSPI();

uint16_t calculateCRC();
bool verifyCRC();

uint8_t* bqGetTxBuf();
uint8_t* bqGetRxBuf();
int* bqGetTxDataLen();
int* bqGetRxDataLen();
void bqGetVoltages(float* voltages);
void bqGetTemps(float* temps);
void bqGetCurrent(float* current);
void bqWakeChip();
void bqCommClear();
