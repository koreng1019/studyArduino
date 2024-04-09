/*
값이 255까지 증가했다가 0깍지 감소하기를 반복하는 프로그램.
추가, LED에 적용.
터치 시 LED 색상 변경.
중복 터치 불가.
*/
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int i = 0;
void setup() {
  pinMode(4, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  //기준값에 따라서 증감 판단.
  if(a >= 255) {
    b = 1;
  }
  else if(a <= 0) {
    b = 0;
  }

  if(b == 0) {
    a = a + 1;
  }
  else {
    a = a - 1;
  }

  if(digitalRead(4) == 1) {
    if(i == 0) {
      if(f < 2) {
        f = f + 1;
      }
      else {
        f = 0;
      }
      i = 1;
    }
  }
  else {
    i = 0;
  }

  if(f == 0) {
    c = 10;
    d = 11;
    e = 12;
  }
  else if(f == 1) {
    c = 11;
    d = 12;
    e = 10;
  }
  else if(f == 2) {
    c = 12;
    d = 10;
    e = 11;
  }
  analogWrite(c, a);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  Serial.println(a);
  delay(10);
}
