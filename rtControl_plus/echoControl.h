int distance = 0;
int duration = 0;

int check = 0;

int nowEcho = 0;
int beforeEcho = 0;
int MnowEcho = 0;
int MbeforeEcho = 0;

void echoControl()
{
  nowEcho = millis();
  if(nowEcho - beforeEcho >= 100)
  {
    beforeEcho = nowEcho;
    digitalWrite(trig, HIGH);
    MnowEcho = micros();
    if(MnowEcho - MbeforeEcho >= 10)
    {
      MbeforeEcho = MnowEcho;
      digitalWrite(trig, LOW);
      duration = pulseIn(echo, HIGH);
      distance = duration / 29 / 2;
    }
  }
}

void echoDetect()
{
  if(5 < distance && distance <= 30)
  {
    accel(0, (int)distance*3, 0, (int)distance*3);
    check = 1;
  }
  if(distance <= 5)
  {
    accel(255, 255, 255, 255);
    check = 1;
  }
  else
  {
    check = 0;
  }
}