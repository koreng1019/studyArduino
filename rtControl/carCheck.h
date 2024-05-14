void sCheck(int a)
{
  handle(hCenter);
  accel(250, 250, 250, 250);
    //LED 표시
    if(a > 10)
    {
      digitalWrite(L2, HIGH);
      a -= 10;
    }
    for(int w = 0; w < a; w++)
    {
      digitalWrite(L1, HIGH);
      delay(300);
      digitalWrite(L1, LOW);
      delay(300);
    }
    digitalWrite(L2, LOW);
    delay(1000);
}