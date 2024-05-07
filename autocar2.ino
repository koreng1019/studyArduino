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

#define G 120
#define S 70
#define B 0

int i1, i2, i3, i4; //IR

int mid = 90; //Servo angle
int ang = 30;

int sensorState = 0;

unsigned long before = 0;
unsigned long now = 0;

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

}

void loop() {
  IR();
  SensorState();
  Serial.println(sensorState);

  switch(sensorState)
  {
    case 0: //0000
      DC(G,G,B,B);
      sv.write(mid);
      break;
    case 1: //0001
      DC(G,G,B,B);
      sv.write(mid+ang);
      break;
    case 2: //0010
      break;
    case 3: //0011
      DC(G,S,B,B);
      sv.write(mid+ang);
      break;
    case 7: //0111
      DC(G,B,B,B);
      sv.write(mid+ang);
      break;
    case 8: //1000
      DC(G,G,B,B);
      sv.write(mid-ang);
      break;
    case 12: //1100
      DC(S,G,B,B);
      sv.write(mid-ang);
      break;
    case 13: //1101
      break;
    case 14: //1110
      DC(B,G,B,B);
      sv.write(mid-ang);
      break;
    case 15: //1111
      DC(B,B,B,B);
      sv.write(mid);
      break;
  }
}

void IR()
{
  i1 = analogRead(ir1);
  i2 = analogRead(ir2);
  i3 = analogRead(ir3);
  i4 = analogRead(ir4);
}

void SensorState()
{
  if(i1 > 500 && i2 > 500 && i3 > 500 && i4 > 500) sensorState = 0; //0000
  if(i1 > 500 && i2 > 500 && i3 > 500 && i4 < 500) sensorState = 1; //0001
  if(i1 > 500 && i2 > 500 && i3 < 500 && i4 > 500) sensorState = 2; //0010
  if(i1 > 500 && i2 > 500 && i3 < 500 && i4 < 500) sensorState = 3; //0011
  if(i1 > 500 && i2 < 500 && i3 > 500 && i4 > 500) sensorState = 4; //0100
  if(i1 > 500 && i2 < 500 && i3 > 500 && i4 < 500) sensorState = 5; //0101
  if(i1 > 500 && i2 < 500 && i3 < 500 && i4 > 500) sensorState = 6; //0110
  if(i1 > 500 && i2 < 500 && i3 < 500 && i4 < 500) sensorState = 7; //0111
  if(i1 < 500 && i2 > 500 && i3 > 500 && i4 > 500) sensorState = 8; //1000
  if(i1 < 500 && i2 > 500 && i3 > 500 && i4 < 500) sensorState = 9; //1001
  if(i1 < 500 && i2 > 500 && i3 < 500 && i4 > 500) sensorState = 10; //1010
  if(i1 < 500 && i2 > 500 && i3 < 500 && i4 < 500) sensorState = 11; //1011
  if(i1 < 500 && i2 < 500 && i3 > 500 && i4 > 500) sensorState = 12; //1100
  if(i1 < 500 && i2 < 500 && i3 > 500 && i4 < 500) sensorState = 13; //1101
  if(i1 < 500 && i2 < 500 && i3 < 500 && i4 > 500) sensorState = 14; //1110
  if(i1 < 500 && i2 < 500 && i3 < 500 && i4 < 500) sensorState = 15; //1111
}

void DC(int a, int b, int c, int d)
{
  analogWrite(dc2, a); 
  analogWrite(dc4, b);
  analogWrite(dc1, c); 
  analogWrite(dc3, d);
  delay(10);
}