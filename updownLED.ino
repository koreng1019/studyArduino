/*
값이 255까지 증가했다가 0깍지 감소하기를 반복하는 프로그램.
추가, LED에 적용.
터치 시 LED 색상 변경.
*/
int a = 0;
int b = 0;
int c = 0;
int d = 0;
void setup() {
  pinMode(4, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
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
    c = 11;
    d = 10;
  }
  else {
    c = 10;
    d = 11;
  }
  analogWrite(c, a);
  digitalWrite(d, HIGH);
  Serial.println(a);
  delay(10);
}
