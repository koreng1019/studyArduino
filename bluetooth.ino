#include "BluetoothSerial.h"
BluetoothSerial bt;

void setup()
{
  pinMode(26, OUTPUT);
  Serial.begin(115200);
  bt.begin("ESP32_hym"); //블루투스 시리얼통신 초기화
  digitalWrite(26, 1);
}

char a;
char b;

void loop()
{
  if(Serial.available()) 
  {
    a = Serial.read();
    Serial.write(a);
    bt.write(a); //시리얼 모니터에서 입력된 값이 있으면 실행
  }

  if(bt.available()) 
  {
    b = bt.read();
    Serial.write(b); 
    bt. write(b); //블루투스터미널에서 입력된 값이 있으면 실행
  }

  if(a == 'r' || b == 'r')
  {
    digitalWrite(26, 0);
  }
  
  if(a == 'c' || b == 'c')
  {
    digitalWrite(26, 1);
  }
}
