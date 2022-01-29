#include "bq_comm.h"
#include "pin_defs.h"
//#include "Crc16.h"

bool carActive = false;
bool isCharging = false;
int fault = 0; //error codes: 0=none, 1=UV, 2=OV, 3=UT, 4=OT, 5=OC, 6=external kill

#define num_series 140
#define num_thermo 112
#define num_segments 14 //logical segments (BQ79656-Q1 chips)
float voltages[num_series]; //should be 0 because global? maybe should be initialized in setup
float temps[num_thermo]; //16 per segment * 7 segments
float current;

void faultInterrupt() {
  
}

void setup() {
  // put your setup code here, to run once:
  /* CRC test code
  pinMode(BQ_FAULT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BQ_FAULT_PIN), shutdownCar, LOW);
  uint8_t *txBuf = getTxBuf();
  txBuf[0] = 0x80;
  txBuf[1] = 0x00;
  txBuf[2] = 0x02;
  txBuf[3] = 0x0F;
  txBuf[4] = 0x0B;
  uint8_t buf[5] = {0x80, 0x00, 0x02, 0x0F, 0x0B};

  int *txDataLen = getTxDataLen();
  *txDataLen = 5;

  Serial.begin(9600);
  Serial.println(calculateCRC(), HEX);*/
  //Serial.println(CRC16.x25(buf, sizeof(buf)));
  //Serial.println(sizeof(buf));
  //Serial.println(crc.Modbus(buf, 0, 5), HEX);
}

void loop() {
  //check current
  //todo
  getCurrent(&current);

  //check voltages
  //todo
  getVoltages(voltages);

  //check temps
  //todo
  getTemps(temps);

  //cell balancing if charging
  //todo

  //log to SD, send to ESP, send to CAN
  //todo
}

void shutdownCar() {
  //kill the car
  digitalWrite(contactorn_ctrl, LOW);
  digitalWrite(contactorp_ctrl, LOW);
  digitalWrite(contactorprecharge_ctrl, LOW);
  carActive = false;
  return;
}

void startCar() {
  //precharge, then start the car
  digitalWrite(contactorn_ctrl, HIGH);
  digitalWrite(contactorprecharge_ctrl, HIGH); //precharge, but don't turn on car yet
  //monitor current going from battery, wait until below threshold to confirm precharge finished
  //todo
  delay(1000); //overkill (I hope)
  digitalWrite(contactorp_ctrl, HIGH); //turn on car
  digitalWrite(contactorprecharge_ctrl, LOW); //disable precharge when car is running
  carActive = true;
}
