#include <Arduino.h>
#include "bq_comm.h"
#include "teensy_pin_defs.h"
//#include "Crc16.h"

#include <algorithm>

#define serialdebug 1

bool carActive = false;
bool isCharging = false;
int faultPin = 0;
int fault = 0; // error codes: 0=none, 1=UV, 2=OV, 3=UT, 4=OT, 5=OC, 6=external kill

BQ79656 bq(Serial8, 35);

std::vector<float> voltages(num_series);
std::vector<float> temps(num_thermo);
std::vector<float> current(1);
float maxVoltage;
float maxTemp;

#define OT_THRESH 60       // 60C max temp
#define UT_THRESH -40      //-40C min temp
#define UT_THRESH_CHARGE 0 // 0 min temp while charging

void faultInterrupt()
{
  shutdownCar();

  bool foundFault = 0;
  for (int i = 0; i < num_kill_pins; i++)
  {
    if (!digitalRead(kill_pins[i]))
    {
      faultPin = kill_pins[i];
      break;
    }
  }
  if (!foundFault)
  {
    faultPin = -1;
  }
}

void setup()
{
// put your setup code here, to run once:
#if serialdebug
  Serial.begin(115200);
  Serial.println("Starting...");
#endif

  // attach fault interrupts
  for (int i = 0; i < num_kill_pins; i++)
  {
    pinMode(kill_pins[i], INPUT);
    attachInterrupt(digitalPinToInterrupt(kill_pins[i]), faultInterrupt, FALLING);
  }

  // initialize SPI communication with the BQ chips
  bq.Initialize();

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
  // Serial.println(CRC16.x25(buf, sizeof(buf)));
  // Serial.println(sizeof(buf));
  // Serial.println(crc.Modbus(buf, 0, 5), HEX);
}

void loop()
{
  // check fault status
  if (fault)
  {
#if serialdebug
    Serial.println("Fault:" + fault);
#endif
  }

  // check current
  bq.GetCurrent(current);

  // check voltages
  bq.GetVoltages(voltages);
  maxVoltage = *std::max_element(voltages.begin(), voltages.end());

  // check temps
  bq.GetTemps(temps);
  maxTemp = *std::max_element(temps.begin(), temps.end());
  analogWrite(coolant_ctrl, map(maxTemp, 20, 50, 0, 255)); // Current pin is NOT pwm capable - rev board or use softpwm, also map ranges may be suboptimal

  // cell balancing if charging
  // todo

  // log to SD, send to ESP, send to CAN
  // todo
}

void shutdownCar()
{
  // kill the car
  digitalWrite(contactorn_ctrl, LOW);
  digitalWrite(contactorp_ctrl, LOW);
  digitalWrite(contactorprecharge_ctrl, LOW);
  carActive = false;
  return;
}

void startCar()
{
  // precharge, then start the car
  digitalWrite(contactorn_ctrl, HIGH);
  digitalWrite(contactorprecharge_ctrl, HIGH); // precharge, but don't turn on car yet
  // monitor current going from battery, wait until below threshold to confirm precharge finished
  // todo
  delay(1000);                                // overkill (I hope)
  digitalWrite(contactorp_ctrl, HIGH);        // turn on car
  digitalWrite(contactorprecharge_ctrl, LOW); // disable precharge when car is running
  carActive = true;
}

void getMaxMinAvgTot(double *arr, int arrSize, double *res)
{
  double currMax = arr[0];
  double currMin = arr[0];
  double currTot = arr[0];
  for (int i = 1; i < arrSize; i++)
  {
    currMax = max(currMax, arr[i]);
    currMin = min(currMin, arr[i]);
    currTot += arr[i];
  }
  res[0] = currMax;
  res[1] = currMin;
  res[2] = currTot / arrSize;
  res[3] = currTot;
}
