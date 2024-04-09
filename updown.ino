/*
값이 255까지 증가했다가 0까지 감소하기를 반복하는 프로그램.
*/
int a = 0;
int b = 0;
void setup() {
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
  Serial.println(a);
  delay(50);
}
