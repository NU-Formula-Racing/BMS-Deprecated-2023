#include <SPI.h>
#include "Crc16.h"

//byte frame[] = {0x80, 0x00, 0x20, 0x05, 0x00, 0x27, 0x44}; //read COMM_TIMEOUT (0x2005), should return 0x34

//pin assignments for main board
const int dataReadyPin = 17;
const int chipSelectPin = 38;
#define SPI_FREQ 6000000

Crc16 crc;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Starting test");
  SPI.begin();
  pinMode(dataReadyPin, INPUT);
  pinMode(chipSelectPin, OUTPUT);
  digitalWrite(chipSelectPin, HIGH);
  
  Serial.println("Waking chip");
  wakeChip();
  delay(3000);
}

void loop() {
  Serial.println("Waiting for SPI_rdy...");
  while (!digitalRead(dataReadyPin)) {
   Serial.print(".");
   delay(1);
  }
  Serial.println("\nSPI_rdy high!");
  byte frame[] = {0x80, 0x00, 0x20, 0x05, 0x00, 0x0, 0x0};//0x27, 0x44}; //read COMM_TIMEOUT (0x2005), should return 0x34
  uint16_t calc_crc = crc.Modbus(frame, 0, 5);
  frame[5] = calc_crc & 0xFF;
  Serial.println(frame[5], HEX);
  frame[6] = calc_crc >> 8;
  Serial.println(frame[6], HEX);
  Serial.println(crc.Modbus(frame, 0, 5), HEX);
  Serial.println(frame[0], HEX);
  SPI.beginTransaction(SPISettings(SPI_FREQ, MSBFIRST, SPI_MODE0));
  Serial.println("Sending frame:");
  digitalWrite(chipSelectPin, LOW);
  delayMicroseconds(1);
  /*for(int i = 0; i < 7; i++) {
    //Serial.print(frame[i], HEX);
    SPI.transfer(frame[i]);
  }*/
  SPI.transfer(frame, 7);
  delayMicroseconds(1);
  digitalWrite(chipSelectPin, HIGH);
  SPI.endTransaction();
  //Serial.println();
  Serial.println("Waiting for data ready.");
  while (!digitalRead(dataReadyPin)) {
   Serial.print(".");
   delay(1);
  }
  Serial.println();
  SPI.beginTransaction(SPISettings(SPI_FREQ, MSBFIRST, SPI_MODE0));
  digitalWrite(chipSelectPin, LOW);
  delayMicroseconds(1);
  //byte result[7];
  //for (int i = 0; i < 7; i++) {
  //  result[i] = SPI.transfer(0xFF);
  //}
  SPI.transfer(frame, 7);
  delayMicroseconds(1);
  digitalWrite(chipSelectPin, HIGH);
  for (int i = 0; i < 7; i++) {
    Serial.print(frame[i], HEX, 2);
    Serial.print(" ");
  }
  Serial.println();
  //digitalWrite(chipSelectPin, HIGH);
  SPI.endTransaction();
  delay(1000);
}

void wakeChip() {
  digitalWrite(chipSelectPin, LOW);
  SPI.beginTransaction(SPISettings(SPI_FREQ, LSBFIRST, SPI_MODE0));
  int wakeBytes = ((SPI_FREQ/8)*(2.5/1000));
  byte wakeBuf[wakeBytes] = {0};
  SPI.transfer(wakeBuf, wakeBytes);
  SPI.endTransaction();
  digitalWrite(chipSelectPin, HIGH);
}

void commClear() {
  digitalWrite(chipSelectPin, LOW);
  SPI.beginTransaction(SPISettings(SPI_FREQ, LSBFIRST, SPI_MODE0));
  SPI.transfer(0x00);
  SPI.endTransaction();
  digitalWrite(chipSelectPin, HIGH);
}
