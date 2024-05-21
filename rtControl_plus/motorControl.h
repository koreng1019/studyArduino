int hCenter = 90;
int hMax = 30;

void handle(int a)
{
  sg1.write(a);
}

void accel(int a, int b, int c, int d)
{
  analogWrite(n1d, a);
  analogWrite(n1r, b);
  analogWrite(n2d, c);
  analogWrite(n2r, d);
  delay(10);
}