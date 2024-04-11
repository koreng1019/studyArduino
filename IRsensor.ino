void setup() {
  pinMode(36, INPUT);
  pinMode(39, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  Serial.begin(115200);

}

void loop() {
  int i1 = analogRead(36);
  int i2 = analogRead(39);
  int i3 = analogRead(34);
  int i4 = analogRead(35);

  Serial.print(i1);
  Serial.print(" , ");
  Serial.print(i2);
  Serial.print(" , ");
  Serial.print(i3);
  Serial.print(" , ");
  Serial.println(i4);
  delay(100);
}
