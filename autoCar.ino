/************************************************************

  주어진 트랙을 3바퀴 완주
  ( 단, 아래의조건에 따라서 코딩이 진행 돼야 한다 )

  조건 1. 엑셀, 브레이크, 핸들 제어 등을 함수로 분리
  조건 2. delay() 함수를 사용하지 말고 millis() 함수를 사용

  **********************************************************

  위 조건에 성공 시 "정지선 인식 후 3초 정지" ( 정지선 인식 필요 )

  **********************************************************

  위 조건에 성공 시 3바퀴 주행 후 완전 정지 ( 주행 횟수 카운트 필요 )

  **********************************************************

  위 조건에 성공 시 전방 장애물과의 거리를 5cm 거리로 유지 ( 장애물과의 거리가 가까우면 후진 필요 )

************************************************************/

#include <Servo.h>
Servo sv;

#define ir1 36 //IR
#define ir2 39
#define ir3 34
#define ir4 35

#define dc1 2 //DC
#define dc2 4
#define dc3 13
#define dc4 27

int i1, i2, i3, i4; //IR

int mid = 90; //Servo angle
int ang = 20;

int count = 0; //1바퀴 카운트
int dubble = 0; //중복 카운트 방지

int e = 23; //초음파 센서
int t = 32;

float duration = 0; //초음파 거리
float distance = 0;

unsigned long beforeStopline = 0; // 정지선 감지 millis
unsigned long nowStopline = 0;

unsigned long beforeEcho = 0; // 초음파 센서 millis
unsigned long nowEcho = 0;

void setup() 
{
  pinMode(ir1, INPUT); //IR
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);

  pinMode(dc1, OUTPUT); //DC
  pinMode(dc2, OUTPUT);
  pinMode(dc3, OUTPUT);
  pinMode(dc4, OUTPUT);

  pinMode(t, OUTPUT);
  pinMode(e, INPUT);

  Serial.begin(115200);

  sv.attach(16); //DC reset
  sv.write(mid);  
}

void loop() {
  IRsensor();
  Servo();
  Echo();
  Stop();
  Break();
  Drive();

  Serial.print(i1);
  Serial.print(" ");
  Serial.print(i2);
  Serial.print(" ");
  Serial.print(i3);
  Serial.print(" ");
  Serial.print(i4);
  Serial.print(" ");
  Serial.print(distance);
  Serial.print(" ");
  Serial.println(count);
}

void IRsensor()
{
  i1 = analogRead(ir1);
  i2 = analogRead(ir2);
  i3 = analogRead(ir3);
  i4 = analogRead(ir4);
}

void Servo()
{
  if(i1 <= 500 && i4 <= 500) sv.write(mid);
  else if(i1 <= 500 || i4 <= 500)
  {
    if(i4 <= 500) sv.write(mid + ang);
    if(i1 <= 500) sv.write(mid - ang);
  }
  else sv.write(mid);
}

void Echo()
{
  nowEcho = millis(); //정지 후 시스템 시간 3초 후 다시 주행
  if(nowEcho - beforeEcho >= 100)
  {
    beforeEcho = nowEcho;
    digitalWrite(t, HIGH);
    delayMicroseconds(10);
    digitalWrite(t, LOW);
    duration = pulseIn(e, HIGH);
    distance = duration / 29 / 2;
  }

  if(5 < distance && distance <= 30)
  {
    analogWrite(dc2, (int)distance*3); 
    analogWrite(dc4, (int)distance*3);
    analogWrite(dc1, 0); 
    analogWrite(dc3, 0);
  }
  if(distance <= 5)
  {
    analogWrite(dc2, 255); 
    analogWrite(dc4, 255);
    analogWrite(dc1, 255); 
    analogWrite(dc3, 255);
    analogWrite(dc2, 0); 
    analogWrite(dc4, 0);
    analogWrite(dc1, 0); 
    analogWrite(dc3, 0);
  }
}

void Drive()
{
  nowStopline = millis(); //정지 후 시스템 시간 3초 후 다시 주행
  if(nowStopline - beforeStopline >= 3000)
  {
    beforeStopline = nowStopline;
    if(i2 >= 500 && i3 >= 500) 
    {
      analogWrite(dc2, 150); 
      analogWrite(dc4, 150);
      analogWrite(dc1, 0); 
      analogWrite(dc3, 0);

      if(dubble == 1)
      {
        dubble = 0;
      }
    }
  }
}

void Stop()
{
  if(count >= 3)
  {
    analogWrite(dc2, 0); 
    analogWrite(dc4, 0);
    analogWrite(dc1, 0); 
    analogWrite(dc3, 0);
  }
}

void Break()
{
  if(i2 <= 500 && i3 <= 500) 
  {
    analogWrite(dc2, 0); 
    analogWrite(dc4, 0);
    analogWrite(dc1, 0); 
    analogWrite(dc3, 0);

    nowStopline = 0;
    beforeStopline = 0;
    
    if(dubble == 0)
    {
      count += 1;
      dubble = 1;
    }
  }
}