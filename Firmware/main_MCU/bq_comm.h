#include "bq79600_reg_defs.h"
#include "bq79656_reg_defs.h"
#include <stdbool.h>
#include <Arduino.h>
#include <FastCRC.hpp>

#define BQ_FAULT_PIN 2

uint16_t calculateCRC();
bool verifyCRC();

uint8_t* getTxBuf();
uint8_t* getRxBuf();
int* getTxDataLen();
int* getRxDataLen();
