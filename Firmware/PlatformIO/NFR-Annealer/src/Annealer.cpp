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
#define LEDPIN 2
#define temp_pin 32

#include <Arduino.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include <WiFi.h>

const char* ssid = "Annealer";
const char* password = "AnnealerPasswd";

WebServer server(80);

float target = 0;
float anneal_time = 0;
unsigned long end_millis;

void startAnneal();
void serialFlush();
float getTemp();

String getPage() {
  String page = "<html><head>";//lang=fr-FR
  page += "<title>NFR Annealer</title>";
  page += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style>";
  if(end_millis > millis()){
    //js timer
    page += "<script>function CountDownTimer(duration, granularity) {  this.duration = duration;  this.granularity = granularity || 1000;  this.tickFtns = [];  this.running = false;}CountDownTimer.prototype.start = function() {  if (this.running) {    return;  }  this.running = true;  var start = Date.now(),      that = this,      diff, obj;  (function timer() {    diff = that.duration - (((Date.now() - start) / 1000) | 0);        if (diff > 0) {      setTimeout(timer, that.granularity);    } else {      diff = 0;      that.running = false;    }    obj = CountDownTimer.parse(diff);    that.tickFtns.forEach(function(ftn) {      ftn.call(this, obj.minutes, obj.seconds);    }, that);  }());};CountDownTimer.prototype.onTick = function(ftn) {  if (typeof ftn === 'function') {    this.tickFtns.push(ftn);  }  return this;};CountDownTimer.prototype.expired = function() {  return !this.running;};CountDownTimer.parse = function(seconds) {  return {    'minutes': (seconds / 60) | 0,    'seconds': (seconds % 60) | 0  };};</script>";
    page += "<script>window.onload = function () {var display = document.querySelector('#time'),timer = new CountDownTimer(";
    page += (end_millis - millis())/1000;
    page += ");timer.onTick(format(display)).start();function format(display) {return function (minutes, seconds) {minutes = minutes < 10 ? '0' + minutes : minutes;seconds = seconds < 10 ? '0' + seconds : seconds;display.textContent = minutes + ':' + seconds;};}};</script>";
    //end js
  }
  page += "</head><body><h1>NFR Annealer</h1>";
  page += "<h3>Control Interface</h3>";
  page += "<div>Temperature: ";
  page += getTemp();
  page += "&deg;C</div>";
  page += "<div>Target Temperature: ";
  page += target;
  page += "&deg;C</div>";
  page += "<div>Timer: ";
  page += (((end_millis - millis())/1000)/60.00);
  page += " minutes</div>";
  if(end_millis > millis()) {
    page += "<div>Time left: <span id='time'></span>";
    page += " minutes</div>";
  }
  page += "<form action='/submitTemp' method='POST'>"; 
  page += "<div><INPUT type='number' name='Target Temperature' min='0' max='700'>";//id='targetTemp' value='24' min='15' max='400'
  page += "<INPUT type='submit' value='Submit Target Temp (C)'></div></form>";
  page += "<form action='/submitTime' method='POST'>"; 
  page += "<div><INPUT type='number' step = '0.01' name='Time (hr)'>";
  page += "<INPUT type='submit' value='Submit Time (hr)'></div></form>";
  page += "<form action='/toggleTimer' method='POST'>"; 
  page += "<div><INPUT type='submit' value='";
  page += end_millis > millis()?"Stop Timer":"Start Timer";
  page += "'></div></form>";
  page += "</body></html>";
  return page;
}

String getPageRedirect() {
  String page = "<html><head>";
  page += "<meta http-equiv='refresh' content='0; URL=/' /></head><body>";
  page += "If you are not redirected, please click ";
  page += "<a href='/'>here.</a></body></html>";
  return page;
}

void handleSubmitTemp(){
  String newT = server.arg(0);
  target = newT.toInt();
  server.send ( 200, "text/html", getPageRedirect() );
}

void handleSubmitTime(){
  String newTime = server.arg(0);
  end_millis = millis() + (newTime.toFloat() * 60 * 60 * 1000);
  server.send ( 200, "text/html", getPageRedirect() );
}

void setup() {
  WiFi.persistent(false);
  Serial.begin(9600);
  Serial.println("Beginning");
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  pinMode(contactorn_ctrl, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(temp_pin, INPUT);
  pinMode(15, OUTPUT);
  digitalWrite(15, LOW); //generate gnd for thermistor
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH); //generate vcc for thermistor resistor divider
  server.on("/", []() {
    server.send(200, "text/html", getPage());
  });
  server.on("/submitTemp", handleSubmitTemp);
  server.on("/submitTime", handleSubmitTime);
  server.begin();
  Serial.println(WiFi.softAPIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  /*Serial.print("Temp: ");
  Serial.print(getTemp());
  Serial.print("C.\n"); */
  if (end_millis > millis())
  {
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
  }
  /* if (millis() >= end_millis) {
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
  } */
}

/* void startAnneal() {
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
} */

#define adc_acc 4094
#define r0 100
#define alpha .00385
float getTemp() {
  float r = analogRead(temp_pin);
  r += 467; //calibration for esp32
  r = (100*r)/(adc_acc-r);
  float temp = (r - r0)/(r0 * alpha);
  return temp;
}
