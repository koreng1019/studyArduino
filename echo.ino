int e = 23;
int t = 32;

void setup() {
  Serial.begin(115200);
  pinMode(t, OUTPUT);
  pinMode(e, INPUT);

}

void loop() {
  digitalWrite(t, HIGH);
  delayMicroseconds(10);
  digitalWrite(t, LOW);
  float duration = pulseIn(e, HIGH);
  float distance = duration / 29 / 2;
  Serial.print(distance);
  Serial.println("cm");
  delay(100); 

}
