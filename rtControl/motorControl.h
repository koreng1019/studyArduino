int hCenter = 90;
int hMax = 30;

void handle(int a)
{
  sg1.write(a);
  Serial.print("handle = ");
  Serial.println(a);
}

void accel(int a, int b, int c, int d)
{
  analogWrite(n1d, a);
  analogWrite(n1r, b);
  analogWrite(n2d, c);
  analogWrite(n2r, d);
  delay(10);

  Serial.print("accel = ");
  Serial.print(a);
  Serial.print(" | ");
  Serial.print(b);
  Serial.print(" | ");
  Serial.print(c);
  Serial.print(" | ");
  Serial.println(d);
}