#define rx_esp 0
#define tx_esp 1
#define can_rx 30
#define can_tx 31
#define cs_esp 39 //cs1
#define miso_esp 41
#define mosi_esp 26
#define sck_esp 27
#define coolant_ctrl 20
#define contactorprecharge_ctrl 21
#define contactorp_ctrl 22
#define contactorn_ctrl 23
#define LEDPIN 13
#define temp_pin 14

float target = 0;
float anneal_time = 0;
unsigned long end_millis;

void startAnneal();
void serialFlush();
float getTemp();

void setup() {
  Serial.begin(115200);
  pinMode(contactorn_ctrl, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(temp_pin, INPUT);
  pinMode(15, OUTPUT);
  digitalWrite(15, LOW); //generate gnd for thermistor
  pinMode(40, OUTPUT);
  digitalWrite(40, HIGH); //generate vcc for thermistor resistor divider
  startAnneal();
}

void loop() {
  // put your main code here, to run repeatedly:
  //read temp
  float temp = getTemp();
  digitalWrite(LEDPIN, HIGH);
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print("/");
  Serial.print(target);
  Serial.print("C. Heater is ");
  if (temp < target) { //if temp < target
    digitalWrite(contactorn_ctrl, HIGH);
    Serial.println("on.");
  } else {
    digitalWrite(contactorn_ctrl, LOW);
    Serial.println("off.");
  }
  float time_left = (float)(end_millis - millis())/(float)(1000*60*60);
  String toPrint = "Time left: ";
  toPrint += time_left;
  toPrint += " hours.";
  Serial.println(toPrint);
  delay(100);
  digitalWrite(LEDPIN, LOW);
  if (millis() >= end_millis) {
    digitalWrite(contactorn_ctrl, LOW);
    while(1) {
      digitalWrite(LEDPIN, HIGH);
      delay(1000);
      digitalWrite(LEDPIN, LOW);
      delay(1000);
      Serial.println("Anneal finished.");
      if(Serial.available() != 0) {
        serialFlush();
        startAnneal();
        break;
      }
    }
  }
}

void startAnneal() {
  Serial.print("Starting. Please enter temperature in C: ");
  while (Serial.available() == 0){}
  target = Serial.parseFloat();
  serialFlush();
  Serial.print("\nPlease enter time for anneal in hours: ");
  while (Serial.available() == 0){}
  anneal_time = Serial.parseFloat();
  serialFlush();
  String toPrint = "\nAnnealing at ";
  toPrint += target;
  toPrint += "C for ";
  toPrint += anneal_time;
  toPrint += " hours.";
  Serial.println(toPrint);
  unsigned long start_millis = millis();
  end_millis = start_millis + (anneal_time * 60 * 60 * 1000);
}

void serialFlush() {
  while(Serial.available() != 0) {
    char c = Serial.read();
  }
}

#define adc_acc 1023
#define r0 100
#define alpha .00385
float getTemp() {
  float r = analogRead(temp_pin);
  r = (100*r)/(adc_acc-r);
  float temp = (r - r0)/(r0 * alpha);
  return temp;
}
