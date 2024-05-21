#include <Servo.h>
#include "esp32-hal.h" //micros()
#include "BluetoothSerial.h"
BluetoothSerial bt;
Servo sg1;
Servo sg2;

#define L1 33
#define L2 17
#define echo 23
#define trig 32
#define ir1 36
#define ir2 39
#define ir3 34
#define ir4 35
#define cds 25
#define servo1 16
#define servo2 18
#define n1d 2
#define n1r 4
#define n2d 13
#define n2r 27
#define echo 23
#define trig 32

void rtPinMode()
{
  Serial.begin(115200);
  pinMode(L1, OUTPUT); pinMode(L2, OUTPUT);
  pinMode(echo, INPUT); pinMode(trig, OUTPUT);
  pinMode(ir1, INPUT); pinMode(ir2, INPUT); pinMode(ir3, INPUT); pinMode(ir4, INPUT);
  pinMode(cds, INPUT);
  pinMode(n1d, OUTPUT); pinMode(n1r, OUTPUT); pinMode(n2d, OUTPUT); pinMode(n2r, OUTPUT);
  sg1.attach(servo1); sg2.attach(servo2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  bt.begin("ESP32_hym"); //블루투스 시리얼통신 초기화
}