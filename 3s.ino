/********************************************************************************************

  자율주행 자동차 만들기

  IR센서 4개, 초음파센서 1개, 조도센서 1개
  Servo모터 1개, DC모터 2개, LED 2개


  만약에 (차선이 감지되면)
  {
    만약에 (왼쪽 감지)
    {
      핸들 오른쪽
    }
    만약에 (오른쪽 감지)
    {
      핸들 왼쪽
    }
  }
  아니면
  {
    핸들 중앙
  }

  만약에 (IR센서 2 또는 3번에 차선이 감지되면)
  {
    3초간 정지
  }
  아니면
  {
    주행
  }
  

********************************************************************************************/

#include <Servo.h>
Servo sv;

#define ir1 36
#define ir2 39
#define ir3 34
#define ir4 35

#define dc1 2
#define dc2 4
#define dc3 13
#define dc4 27

int m = 0;

int i1, i2, i3, i4; //IR

int mid = 90;
int ang = 30;

void setup() {
  pinMode(ir1, INPUT); //IR
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);

  pinMode(dc1, OUTPUT); //DC
  pinMode(dc2, OUTPUT);
  pinMode(dc3, OUTPUT);
  pinMode(dc4, OUTPUT);

  Serial.begin(115200);

  sv.attach(16); //DC reset
  sv.write(mid);  
}

void loop() {
  Serial.print(i1);
  Serial.print(" ");
  Serial.print(i2);
  Serial.print(" ");
  Serial.print(i3);
  Serial.print(" ");
  Serial.println(i4);
  
  IRsensor();
  Servo();
  DCcontrol();

  if(m == 1)
  {
    analogWrite(dc2, 255);
    analogWrite(dc4, 255);
    analogWrite(dc1, 255);
    analogWrite(dc3, 255);
    analogWrite(dc2, 0);
    analogWrite(dc4, 0);
    analogWrite(dc1, 0);
    analogWrite(dc3, 0);
    delay(3000);
    m = 0;
  }
  if(m == 0)
  {
    analogWrite(dc2, 150);
    analogWrite(dc4, 150);
    analogWrite(dc1, 0);
    analogWrite(dc3, 0);
  }
}

void IRsensor() // 차선감지
{
  i1 = analogRead(ir1);
  i2 = analogRead(ir2);
  i3 = analogRead(ir3);
  i4 = analogRead(ir4);
}

void Servo() //핸들 제어
{
  if(i1 <= 1400 && i4 <= 1400) sv.write(mid);
  else if(i1 <= 1400 || i4 <= 1400)
  {
    if(i4 <= 1400) sv.write(mid + ang);
    if(i1 <= 1400) sv.write(mid - ang);
  }
  else sv.write(mid);
}

void DCcontrol()
{
  if(i2 <= 1400 || i3 <= 1400)
  {
    m = 1;
  }
}