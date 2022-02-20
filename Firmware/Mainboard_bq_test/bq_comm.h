#include "bq79600_reg_defs.h"
#include "bq79656_reg_defs.h"
#include "bq_pin_defs.h"
#include <stdbool.h>
#include <Arduino.h>
#include <SPI.h>

#define BQ_SPI_FREQ 6000000
#define BQ_SINGLE_READ 0b00000000 //single device read
#define BQ_SINGLE_WRITE 0b00010000 //single device write
#define BQ_STACK_READ 0b00100000 //stack read
#define BQ_STACK_WRITE 0b00110000 //stack write
#define BQ_BROAD_READ 0b01000000 //broadcast read
#define BQ_BROAD_WRITE 0b01010000 //broadcast write
#define BQ_BROAD_WRITE_REV 0b01100000 //broadcast write reverse


void bqInitializeSPI();
uint8_t* bqComm(byte req_type, byte data_size, byte dev_addr, uint16_t reg_addr, byte data);
uint8_t* bqReadReg(byte req_type, byte dev_addr, uint16_t reg_addr, byte resp_size);

//uint16_t calculateCRC();
//bool verifyCRC();

uint8_t* bqGetBuf();
int* bqGetDataLen();
void bqGetVoltages(float* voltages);
void bqGetTemps(float* temps);
void bqGetCurrent(float* current);
void bqWakeChip();
void bqCommClear();
