#include "bq_comm.h"
#include "Crc16.h"
#define serialdebug 1

uint8_t bqBuf[176];
uint8_t bqRespBufs[num_segments+1][176];
int bqBufDataLen = 0;
int stackSize = 0;

Crc16 crc;
#define CONTROL1_SEND_WAKE 0b00100000

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
  //pinMode(spi_rdy_pin_bq, INPUT);
  //pinMode(cs_bq, OUTPUT);
  //digitalWrite(cs_bq, HIGH);

  //send commands to start/configure stack
  //todo
  bqWakeChip();
  byte byteArr[] = {CONTROL1_SEND_WAKE};
  bqComm(BQ_SINGLE_WRITE, 1, 0, BRIDGE_CONTROL1, byteArr);
  byteArr[0] = 0x00;
  bqComm(BQ_BROAD_WRITE, 1, 0, STACK_COMM_TIMEOUT_CONF, byteArr);
  //bqAutoAddressing(num_segments);

  /*//enable NFAULT and FCOMM, is enabled by default
  byte[] byteArr = {0b00010100};
  bqComm(BQ_SINGLE_WRITE, 1, 0, BRIDGE_DEV_CONF1, byteArr);*/

  //enable FCOMM_EN of stack devices, unnecessary because enabled by default
  
}

/*
 * Communicates (reads/writes a register) with the BQBQ796XX daisychain
 * req_type is the request type, as defined in bq_comm.h
 * data_size is the size of the data being sent, which is 1 for a read
 * dev_addr is the address of the device being communicated with, ignored for stack or broadcast
 * reg_addr is the address of the register being accessed
 * data is the 1-8 byte payload, which for a read is one less than the number of bytes being read
 * Returns an array of response buffers
 */
void bqComm(byte req_type, byte data_size, byte dev_addr, uint16_t reg_addr, byte* data) {
  data_size -= 1; //0 means 1 byte
  bqBuf[0] = 0b10000000 | req_type | (data_size & 0b00000111); //command | req_type | data_size
  bool isStackOrBroad = (req_type == BQ_STACK_READ) || (req_type == BQ_STACK_WRITE) || (req_type == BQ_BROAD_READ) || (req_type == BQ_BROAD_WRITE) || (req_type == BQ_BROAD_WRITE_REV);
  if (!isStackOrBroad) {
    bqBuf[1] = dev_addr;
  }
  bqBuf[1 + (!isStackOrBroad)] = reg_addr >> 8;
  bqBuf[2 + (!isStackOrBroad)] = reg_addr & 0xFF;
  for (int i = 0; i <= data_size; i++) {
    bqBuf[3 + i + (!isStackOrBroad)] = data[i];
  }
  uint16_t command_crc = crc.Modbus(bqBuf, 0, isStackOrBroad?4:5); //calculates the CRC, but the bytes are backwards
  bqBuf[4 + data_size + (!isStackOrBroad)] = command_crc & 0xFF;
  bqBuf[5 + data_size + (!isStackOrBroad)] = command_crc >> 8;

  #if serialdebug
    Serial.println("Command: ");
    for (int i = 0; i < (isStackOrBroad?6:7); i++) {
      Serial.print(bqBuf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  #endif

  #if serialdebug
    Serial.println("Waiting for SPI_rdy");
  #endif

  unsigned long startTime = micros();
  /*while (!digitalRead(spi_rdy_pin_bq)) {
    #if serialdebug
      if (millis() % 10 == 0) {
        //Serial.print(".");
      }
    #endif
    delay(0.1);
    /*if (micros() - startTime >= 250  && digitalRead(spi_rdy_pin_bq)) {
      bqCommClear();
    }*/
  //}*/
  #if serialdebug
    Serial.println("\nSPI_rdy high!");
  #endif

  //SPI.beginTransaction(SPISettings(BQ_SPI_FREQ, MSBFIRST, SPI_MODE0));
  #if serialdebug
    Serial.println("Sending frame:");
  #endif
  
  //digitalWrite(cs_bq, LOW);
  delayMicroseconds(1);
  for (int i = 0; i < (isStackOrBroad?6:7); i++) {
    Serial2.print(bqBuf[i]);
  }
  //SPI.transfer(bqBuf, (isStackOrBroad?6:7));
  delayMicroseconds(1);
  //digitalWrite(cs_bq, HIGH);
  //SPI.endTransaction();
}

void bqDummyReadReg(byte req_type, byte dev_addr, uint16_t reg_addr, byte resp_size) {
  byte data[] = {0xFF};
  //bqComm(BQ_SINGLE_WRITE, 1, 0, BRIDGE_FAULT_RST, data);
  resp_size -= 1; //0 means 1 byte
  data[0] = resp_size;
  bqComm(req_type, 1, dev_addr, reg_addr, data);
  delay(10);
  if (digitalRead(spi_rdy_pin_bq)) {
    data[0] = 0xFF;
    SPI.transfer(data, 1);
  } else {
    Serial.println("Comm clear");
    bqCommClear();
  }
  /*bqCommClear();
  //data[0] = {0};
  Serial.println("Fault summary");
  bqReadReg(BQ_SINGLE_READ, 0, BRIDGE_FAULT_SUMMARY, 1);
  Serial.println("Fault comm1");
  bqReadReg(BQ_SINGLE_READ, 0, BRIDGE_FAULT_COMM1, 1);
  Serial.println("Fault comm2");
  bqReadReg(BQ_SINGLE_READ, 0, BRIDGE_FAULT_COMM2, 1);
  Serial.println("Fault reg");
  bqReadReg(BQ_SINGLE_READ, 0, BRIDGE_FAULT_REG, 1);
  Serial.println("Fault sys");
  bqReadReg(BQ_SINGLE_READ, 0, BRIDGE_FAULT_SYS, 1);*/
}

/*
 * Reads a register from the BQBQ796XX daisychain
 * req_type is the request type, as defined in bq_comm.h
 * dev_addr is the address of the device being communicated with
 * reg_addr is the address of the register being accessed
 * resp_size is the number of bytes being read
 * Returns an array of response buffers
 */
uint8_t* bqReadReg(byte req_type, byte dev_addr, uint16_t reg_addr, byte resp_size) {
  resp_size -= 1; //0 means 1 byte
  byte data[] = {resp_size};
  bqComm(req_type, 1, dev_addr, reg_addr, data);
  
  bqBufDataLen = resp_size + 7;

  int numExpectedResponses = 1;
  if (req_type == BQ_STACK_READ) {
    numExpectedResponses = stackSize;
  }
  if (req_type == BQ_BROAD_READ) {
    numExpectedResponses = stackSize + 1;
  }

  for (int i = 0; i < numExpectedResponses; i++) {
    for (int j = 0; j < bqBufDataLen; j++) {
      bqRespBufs[i][j] = 0xFF;
    }
    #if serialdebug
      Serial.println("Waiting for data");
    #endif

    unsigned long t_wait_read_max = ((stackSize-1)*6) + (resp_size*10) + 100;
    /*while (!digitalRead(spi_rdy_pin_bq)) {
      #if serialdebug
        //Serial.print(".");
      #endif
      delay(0.5);
      unsigned long startTime = micros();
      /*if (micros() - startTime >= t_wait_read_max && digitalRead(spi_rdy_pin_bq)) {
        bqCommClear();
        data[0] = resp_size;
        bqComm(req_type, 1, dev_addr, reg_addr, data);
      }*/
    //}*/
    #if serialdebug
      Serial.println("Reading data");
    #endif
  
    //SPI.beginTransaction(SPISettings(BQ_SPI_FREQ, MSBFIRST, SPI_MODE0));
    //digitalWrite(cs_bq, LOW);
    delayMicroseconds(1);
    while(!Serial2.available()) {
      delay(1);
    }
    while(Serial2.available()) {
      byte incomingByte = Serial2.read();
      Serial.println(incomingByte, HEX);
    }
    //for (int j = 0; j < bqBufDataLen; j++) {
    //  Serial2.print(bqRespBufs[i][j]);
    //}
    //SPI.transfer(bqRespBufs[i], bqBufDataLen);
    delayMicroseconds(1);
    //digitalWrite(cs_bq, HIGH);
    //SPI.endTransaction();
  
    #if serialdebug
      for (int j = 0; j < bqBufDataLen; j++) {
        Serial.print(bqRespBufs[i][j], HEX);
        Serial.print(" ");
      }
      Serial.println();
    #endif
  }
  return (uint8_t*)bqRespBufs;//(uint8_t**)bqRespBufs;
}

/*
 * Starts the BQ chips and auto-addresses the stack, as defined in table 7-9 of the BQ79600-Q1 datasheet
 */
void bqAutoAddressing(byte numDevices) {
  stackSize = numDevices;
  //Step 1: send WAKE ping
  bqWakeChip();
  byte byteArr[] = {0x00};

  //Step 2: Single device write to BQ79600-Q1 CONTROL1 [SEND_WAKE]=1
  //#define CONTROL1_SEND_WAKE 0b00100000
  byteArr[0] = CONTROL1_SEND_WAKE;
  bqComm(BQ_SINGLE_WRITE, 1, 0, BRIDGE_CONTROL1, byteArr);

  //Step 3: dummy stack write 0x00 to registers 0x343 to 0x34A (sync up internal DLL)
  for (byte i = 0; i < 8; i++) {
    byteArr[0] = 0x00;
    bqComm(BQ_STACK_WRITE, 1, 0, 0x343 + i, byteArr);
  }

  //for testing
  //Serial.println("Uart debug");
  //bqEnableUartDebug();

  //Step 4: broadcast write 0x01 to address 0x309 to enable auto addressing
  byteArr[0] = 0x01;
  bqComm(BQ_BROAD_WRITE, 1, 0, 0x309, byteArr);

  //Step 5: broadcast write consecutively to 0x306 = 0, 1, 2, 3, ...
  for (byte i = 0; i <= numDevices; i++) {
    byteArr[0] = i;
    bqComm(BQ_BROAD_WRITE, 1, 0, 0x306, byteArr);
  }

  //Step 6: broadcast write 0x02 to address 0x308 to set stack device
  byteArr[0] = 0x02;
  bqComm(BQ_BROAD_WRITE, 1, 0, 0x308, byteArr);

  //Step 7: single device write to set top of stack
  byteArr[0] = 0x03;
  bqComm(BQ_SINGLE_WRITE, 1, numDevices, 0x308, byteArr);

  /*Serial.println("Testing single read to device 1 STACK_DIE_ID1");
  bqReadReg(BQ_SINGLE_READ, 1, STACK_DIE_ID1, 1);*/

  //Step 8: dummy stack read registers 0x343 to 0x34A (sync up internal DLL)
  for (byte i = 0; i < 8; i++) {
    bqDummyReadReg(BQ_STACK_READ, 0, 0x343 + i, 1);
  }

  //Step 9: stack read address 0x306 to verify addresses
  bqReadReg(BQ_STACK_READ, 0, 0x306, 1);

  //Step 10: single device read to base, verify 0x2001 = 0x14
  bqReadReg(BQ_SINGLE_READ, 0, 0x2001, 1);
}



//Starts balancing with timers set at 300 seconds and stop voltage at 4V
//Only works with cells per segment <= 14! (due to single stack write limitations)
void bqStartBalancingSimple() {
  int seriesPerSegment = num_series / num_segments;
  //set up balancing time control registers to 300s (0x04)
  byte balTimes[seriesPerSegment] = {0x04};
  bqComm(BQ_STACK_WRITE, seriesPerSegment, 0, STACK_CB_CELL1_CTRL + 1 - seriesPerSegment, balTimes);

  //set balancing end voltage
  byte vcbDone[] = {0x3F};
  bqComm(BQ_STACK_WRITE, 1, 0, STACK_VCB_DONE_THRESH, vcbDone);

  //start balancing with FLTSTOP_EN to stop on fault, OTCB_EN to pause on overtemp, AUTO_BAL to automatically cycle between even/odd
  byte startBal[] = {0b00110011};
  bqComm(BQ_STACK_WRITE, 1, 0, STACK_BAL_CTRL2, startBal);
}

void bqRunBalanceRound(double* voltages) {
  int seriesPerSegment = num_series / num_segments;
  

  for (int i = 1; i <= stackSize; i++) {
    
  }
}

void bqSetStackSize(int newSize) {
  stackSize = newSize;
}

/*uint16_t calculateCRC() {
  return crc.Modbus(txBuf, 0, txDataLen);
}*/

bool verifyCRC(uint8_t* buf) {
  return crc.Modbus(buf, 0, bqBufDataLen) == 0;
}

uint8_t* bqGetBuf() {
  return bqBuf;
}

uint8_t** bqGetRespBufs() {
  return (uint8_t**)bqRespBufs;
}

int* bqGetDataLen() {
  return &bqBufDataLen;
}

void bqGetVoltages(double* voltages) {
  //read voltages from battery
  int seriesPerSegment = num_series / num_segments;
  bqReadReg(BQ_STACK_READ, 0, (STACK_VCELL1_LO + 1) - (seriesPerSegment * 2), seriesPerSegment * 2);

  //fill in num_series voltages to array
  for (int i = 1; i <= stackSize; i++) {
    for (int j = 0; j < seriesPerSegment; j++) {
      int16_t voltage[1];
      ((uint8_t*)voltage)[0] = bqRespBufs[i][(2*j) + 4];
      ((uint8_t*)voltage)[1] = bqRespBufs[i][(2*j) + 5];
      voltages[((i-1)*seriesPerSegment)+j] = voltage[0] * (190.73 * 0.000001); //Result * V_LSB_ADC
    }
  }
  return;
}

void bqGetTemps(double* temps) {
  //read temps from battery
  int thermoPerSegment = num_series / num_segments;
  bqReadReg(BQ_STACK_READ, 0, STACK_GPIO1_HI - 1, thermoPerSegment * 2);

  //fill in num_thermo temps to array
  for (int i = 1; i <= stackSize; i++) {
    for (int j = 0; j < thermoPerSegment; j++) {
      int16_t temp[1];
      ((uint8_t*)temp)[0] = bqRespBufs[i][(2*j) + 4];
      ((uint8_t*)temp)[1] = bqRespBufs[i][(2*j) + 5];
      temps[((i-1)*thermoPerSegment)+j] = temp[0] * (152.59 * 0.000001); //Result * V_LSB_GPIO to get voltage
      //TODO: calculate temp from voltage
    }
  }
  return;
}

void bqEnableUartDebug() {
  //void bqComm(byte req_type, byte data_size, byte dev_addr, uint16_t reg_addr, byte* data);
  byte byteArr[] = {0b00001110};
  bqComm(BQ_BROAD_WRITE, 1, 0, STACK_DEBUG_COMM_CTRL1, byteArr);
}

void bqGetCurrent(double* current) {
  //read current from battery

  return;
}

void bqWakeChip() {
  //Output a pulse of low MOSI for ~2.5ms to wake chip
  /*digitalWrite(cs_bq, LOW);
  SPI.beginTransaction(SPISettings(BQ_SPI_FREQ, MSBFIRST, SPI_MODE0));
  int wakeBytes = ((BQ_SPI_FREQ/8)*(2.5/1000));
  byte wakeBuf[wakeBytes] = {0};
  SPI.transfer(wakeBuf, wakeBytes);
  SPI.endTransaction();
  digitalWrite(cs_bq, HIGH);
  delay(5);*/
  digitalWrite(8, LOW);
  delay(2);
  digitalWrite(8, HIGH);
}

void bqCommClear() {
  //Output one byte of 0 to reset comm interface
  digitalWrite(cs_bq, LOW);
  SPI.beginTransaction(SPISettings(BQ_SPI_FREQ, MSBFIRST, SPI_MODE0));
  SPI.transfer(0x00);
  SPI.endTransaction();
  digitalWrite(cs_bq, HIGH);
}
