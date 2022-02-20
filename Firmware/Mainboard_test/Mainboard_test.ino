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

void setup() {
  pinMode(contactorp_ctrl, OUTPUT);
  pinMode(contactorn_ctrl, OUTPUT);
  pinMode(contactorprecharge_ctrl, OUTPUT);
  pinMode(coolant_ctrl, OUTPUT);
  pinMode(LEDPIN, OUTPUT);

}

void loop() {
  digitalWrite(contactorn_ctrl, HIGH);
  delay(200);
  digitalWrite(contactorp_ctrl, HIGH);
  delay(200);
  digitalWrite(contactorprecharge_ctrl, HIGH);
  delay(200);
  digitalWrite(coolant_ctrl, HIGH);
  delay(200);
  digitalWrite(LEDPIN, HIGH);
  delay(200);
  digitalWrite(contactorn_ctrl, LOW);
  delay(200);
  digitalWrite(contactorp_ctrl, LOW);
  delay(200);
  digitalWrite(contactorprecharge_ctrl, LOW);
  delay(200);
  digitalWrite(coolant_ctrl, LOW);
  delay(200);
  digitalWrite(LEDPIN, LOW);
  delay(1000);
  digitalWrite(contactorp_ctrl, HIGH);
  digitalWrite(contactorn_ctrl, HIGH);
  digitalWrite(contactorprecharge_ctrl, HIGH);
  digitalWrite(coolant_ctrl, HIGH);
  digitalWrite(LEDPIN, HIGH);
  delay(1000);
  digitalWrite(contactorp_ctrl, LOW);
  digitalWrite(contactorn_ctrl, LOW);
  digitalWrite(contactorprecharge_ctrl, LOW);
  digitalWrite(coolant_ctrl, LOW);
  digitalWrite(LEDPIN, LOW);
  delay(1000);
}
