void setup() {
  Serial.begin(115200);
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  delay(2);
  digitalWrite(8, HIGH);
  delay(15);
  Serial2.begin(1000000);
  //delay(10000000);
}

void loop() {
  uint8_t msg[] = {0x80, 0x00, 0x05, 0x01, 0x00, 0x34, 0x4F};//{0x80,0x00,0x20,0x05,0x00,0x27,0x44};//{0x01,0x00,0x04,0xA0,0x00,0xE4,0x22};//{0x80,0x00,0x20,0x05,0x00,0x27,0x44};
  for (int i = 0; i < 7; i++) {
    Serial2.write(msg[i]);
    Serial.print(msg[i], HEX);
  }
  Serial.println();
  //Serial2.print(0x80002005002744);
  while(1) {
    if(Serial2.available()) {
      Serial.print(Serial2.read(), HEX);
    }
  }
}
