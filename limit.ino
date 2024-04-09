/*
어떤 값이 지정된 값까지 증가하는 프로그램.
*/
int a = 0;
void setup() {
  Serial.begin(115200);
}

void loop() {
  if(a < 10) {
    a = a + 1;
    Serial.println(a);
  }
  delay(500);
}
