/********************************************************************************************

  자율주행 자동차 만들기

  IR센서 4개, 초음파센서 1개, 조도센서 1개
  Servo모터 2개, DC모터 2개, LED 2개


  IR센서에 차선이 감지되면
    Servo모터를 튼다
  아니면
    중앙에 고정한다

  초음파센서에 물체가 감지되면
    DC모터를 끈다
  아니면
    주행한다

  어두우면
    LED를 켠다
  아니면
    끈다

********************************************************************************************/

#include <Servo.h>
Servo sv;

int T = 32; //Echo
int E = 23;

int i1; //IR
int i2;
int i3;
int i4;

float duration;
float distance;

int l; //조도센서

long pre = 0;
long interval = 1000;//딜레이 시간

void setup() {
  Serial.begin(115200);

  pinMode(33, OUTPUT); //LED
  pinMode(17, OUTPUT);

  pinMode(36, INPUT); //IR
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);

  pinMode(T, OUTPUT); //Echo
  pinMode(E, INPUT);

  pinMode(2, OUTPUT); //DC
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(27, OUTPUT);

  pinMode(25, INPUT); //조도센서

  sv.attach(16); //DC reset
  sv.write(90);
}

void loop() {

  i1 = analogRead(36); //IR
  i2 = analogRead(39);
  i3 = analogRead(34);
  i4 = analogRead(35);

  if(i1 >= 1800 && i2 >= 1800 && i3 >= 1800 && i4 >= 1800)
  {
    sv.write(90);
  }
  else if(i1 <= 700 && i4 >= 1800)
  {
    sv.write(75);
  }
  else if(i4 <= 700 && i1 >= 1800)
  {
    sv.write(115);
  }
  else
  {
    sv.write(90);
  }

  Echo();

  if(distance <= 20)
  {
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(13, LOW);
    digitalWrite(27, LOW);

  }
  else
  {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(13, LOW);
    digitalWrite(27, HIGH);
  }

  l = analogRead(25);

  if(l <= 1000)
  {
    digitalWrite(33, HIGH);
    digitalWrite(17, HIGH);
  }
  else
  {
    digitalWrite(33, LOW);
    digitalWrite(17, LOW);
  }
}

void Echo()
{
  digitalWrite(T, HIGH);
  delayMicroseconds(10);
  digitalWrite(T, LOW);
  duration = pulseIn(E, HIGH);
  distance = duration / 29 / 2;
  delay(100); 
}
