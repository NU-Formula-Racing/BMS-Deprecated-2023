#include "bq_comm.h"
#include "Crc16.h"
#define serialdebug 1

uint8_t bqBuf[176];
int bqBufDataLen = 0;

Crc16 crc;

/*
 * Initializes communication with the BQ796XX stack
 */
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
  digitalWrite(cs_bq, HIGH);
  bqWakeChip();

  //send commands to start/configure stack
  //todo
  
}

/*
 * Communicates (reads/writes a register) with the BQBQ796XX daisychain
 * req_type is the request type, as defined in bq_comm.h
 * data_size is the size of the data being sent, which is 1 for a read
 * dev_addr is the address of the device being communicated with
 * reg_addr is the address of the register being accessed
 * data is the 1-8 byte payload, which for a read is one less than the number of bytes being read
 */
uint8_t* bqComm(byte req_type, byte data_size, byte dev_addr, uint16_t reg_addr, byte* data) {
  data_size -= 1; //0 means 1 byte
  bqBuf[0] = 0b10000000 | req_type | (data_size & 0b00000111); //command | req_type | data_size
  bqBuf[1] = dev_addr;
  bqBuf[2] = reg_addr >> 8;
  bqBuf[3] = reg_addr & 0xFF;
  for (int i = 0; i <= data_size; i++) {
    bqBuf[4 + i] = data[i];
  }
  uint16_t command_crc = crc.Modbus(bqBuf, 0, 5); //calculates the CRC, but the bytes are backwards
  bqBuf[5 + data_size] = command_crc & 0xFF;
  bqBuf[6 + data_size] = command_crc >> 8;

  #if serialdebug
    Serial.println("Command: ");
    for (int i = 0; i < 7; i++) {
      Serial.print(bqBuf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  #endif

  #if serialdebug
    Serial.println("Waiting for SPI_rdy");
  #endif
  
  while (!digitalRead(spi_rdy_pin_bq)) {
    #if serialdebug
      Serial.print(".");
    #endif
    delay(1);
  }
  #if serialdebug
    Serial.println("\nSPI_rdy high!");
  #endif

  SPI.beginTransaction(SPISettings(BQ_SPI_FREQ, MSBFIRST, SPI_MODE0));
  #if serialdebug
    Serial.println("Sending frame:");
  #endif
  
  digitalWrite(cs_bq, LOW);
  delayMicroseconds(1);
  SPI.transfer(bqBuf, 7);
  delayMicroseconds(1);
  digitalWrite(cs_bq, HIGH);
  SPI.endTransaction();

}

/*
 * Reads a register from the BQBQ796XX daisychain
 * req_type is the request type, as defined in bq_comm.h
 * dev_addr is the address of the device being communicated with
 * reg_addr is the address of the register being accessed
 * resp_size is the number of bytes being read
 */
uint8_t* bqReadReg(byte req_type, byte dev_addr, uint16_t reg_addr, byte resp_size) {
  resp_size -= 1; //0 means 1 byte
  byte data[] = {resp_size};
  bqComm(req_type, 1, dev_addr, reg_addr, data);
  
  int expectedDataLen = resp_size + 7;
  for (int i = 0; i < expectedDataLen; i++) {
    bqBuf[i] = 0xFF;
  }

  #if serialdebug
    Serial.println("Waiting for data");
  #endif
  
  while (!digitalRead(spi_rdy_pin_bq)) {
    #if serialdebug
      Serial.print(".");
    #endif
    delay(1);
  }
  #if serialdebug
    Serial.println("Reading data");
  #endif

  SPI.beginTransaction(SPISettings(BQ_SPI_FREQ, MSBFIRST, SPI_MODE0));
  digitalWrite(cs_bq, LOW);
  delayMicroseconds(1);
  SPI.transfer(bqBuf, expectedDataLen);
  delayMicroseconds(1);
  digitalWrite(cs_bq, HIGH);
  SPI.endTransaction();

  #if serialdebug
    for (int i = 0; i < expectedDataLen; i++) {
      Serial.print(bqBuf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  #endif
  return bqBuf;
}

/*uint16_t calculateCRC() {
  return crc.Modbus(txBuf, 0, txDataLen);
}*/

/*bool verifyCRC() {
  return crc.Modbus(rxBuf, 0, rxDataLen) == 0;
}*/

uint8_t* bqGetBuf() {
  return bqBuf;
}

int* bqGetDataLen() {
  return &bqBufDataLen;
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
  SPI.beginTransaction(SPISettings(BQ_SPI_FREQ, MSBFIRST, SPI_MODE0));
  int wakeBytes = ((BQ_SPI_FREQ/8)*(2.5/1000));
  byte wakeBuf[wakeBytes] = {0};
  SPI.transfer(wakeBuf, wakeBytes);
  SPI.endTransaction();
  digitalWrite(cs_bq, HIGH);
  delay(5);
}

void bqCommClear() {
  //Output one byte of 0 to reset comm interface
  digitalWrite(cs_bq, LOW);
  SPI.beginTransaction(SPISettings(BQ_SPI_FREQ, MSBFIRST, SPI_MODE0));
  SPI.transfer(0x00);
  SPI.endTransaction();
  digitalWrite(cs_bq, HIGH);
}
