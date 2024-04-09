#include "DHT.h"

#define r 26 //빨강
#define g 25 //초록
#define b 27 //파랑
#define t 13 //터치 센서
#define l 4 //조도 센서
#define s 36 //사운드 센서

#define DHTPIN 32
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

int d = 0; // 1 = 중복
int c = 0; //카운트
int m = 7; //기능 갯수

void rgbLed(int R, int G, int B) {
  analogWrite(r, R);
  analogWrite(g, G);
  analogWrite(b, B);
  delay(50);
}

void touchControl() {
  int touch = digitalRead(t);
  if(touch == 1) {
    if(d == 0) {
      d = 1;
      c = c + 1;

      if(c > m) c = 0;

      Serial.println(c);
    }
  }
  else {
    d = 0;
  }
}

void cdsControl() {
  int cds = analogRead(l);
  if(cds == 0) rgbLed(0, 255, 0);
  else rgbLed(255, 255, 255);
}

void soundControl() {
  int sound = analogRead(s);
  if(sound > 3520) rgbLed(255, 0, 0);
  else rgbLed(255, 255, 255);
}

void dhtControl() {
  delay(2000); //샘플링 시간 (DHT11은 최소 1000)

  Serial.print("Temperature: ");
  Serial.print(dht.readTemperature()); //온도 출력
  Serial.print("˚c / humidity: ");
  Serial.print(dht.readHumidity()); //습도 출력
  Serial.println("%");

  if(dht.readTemperature() >= 24) rgbLed(0, 0, 0);
  else rgbLed(255, 255, 255); 
}

void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(t, INPUT);
  pinMode(l, INPUT);
  pinMode(s, INPUT);

  Serial.begin(115200);
  dht.begin(); //DHT센서 초기화

  rgbLed(255, 255, 255);
}

void loop() {
  touchControl();

  if(c == 0) rgbLed(255, 255, 255);
  else if(c == 1) rgbLed(0, 255, 255);
  else if(c == 2) rgbLed(255, 0, 255);
  else if(c == 3) rgbLed(255, 255, 0);
  else if(c == 4) rgbLed(0, 0, 255);
  else if(c == 5) cdsControl();
  else if(c == 6) soundControl();
  else if(c == 7) dhtControl();
}


