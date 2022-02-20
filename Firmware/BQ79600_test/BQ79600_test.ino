#include <SPI.h>

byte frame[] = {0x80, 0x00, 0x20, 0x05, 0x00, 0x27, 0x44}; //read COMM_TIMEOUT (0x2005), should return 0x34
const int dataReadyPin = 6;
const int chipSelectPin = 10;
#define SPI_FREQ 6000000

void setup() {
  Serial.begin(115200);
  delay(10000);
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
  SPI.beginTransaction(SPISettings(SPI_FREQ, LSBFIRST, SPI_MODE0));
  Serial.println("Sending frame:");
  digitalWrite(chipSelectPin, LOW);
  /*for(int i = 0; i < 7; i++) {
    //Serial.print(frame[i], HEX);
    SPI.transfer(frame[i]);
  }*/
  SPI.transfer(frame, 7);
  digitalWrite(chipSelectPin, HIGH);
  SPI.endTransaction();
  //Serial.println();
  //Serial.println("Waiting for data ready.");
  while (!digitalRead(dataReadyPin)) {
   Serial.print(".");
   delay(1);
  }
  SPI.beginTransaction(SPISettings(SPI_FREQ, LSBFIRST, SPI_MODE0));
  digitalWrite(chipSelectPin, LOW);
  byte result[7];
  for (int i = 0; i < 7; i++) {
    result[i] = SPI.transfer(0xFF);
  }
  digitalWrite(chipSelectPin, HIGH);
  for (int i = 0; i < 7; i++) {
    Serial.print(result[i], HEX);
  }
  Serial.println();
  digitalWrite(chipSelectPin, HIGH);
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
