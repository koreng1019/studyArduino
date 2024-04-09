/*
어떤 값이 계속 증가하는 프로그램.
*/
int a = 0;
void setup() {
  Serial.begin(115200);
}

void loop() {
  a = a + 1;
  Serial.println(a);
  delay(500);
}
