void setup() {
  pinMode(9, OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  ledblink(5);
}

void rgbled(int R, int G, int B) {
  analogWrite(10, R);
  analogWrite(9, G);
  analogWrite(11, B);
}

void ledblink(int count) {
  for(int i = 0; i < count; i++) {
    rgbled(0, 0, 0);
    delay(1000);
    rgbled(255, 255, 255);
    delay(1000);
  }
}