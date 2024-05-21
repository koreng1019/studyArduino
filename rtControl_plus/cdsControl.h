int light;

void cdsCheck()
{
  light = analogRead(cds);
  if(light <= 700)
  {
    led(1, 1);
  }
  else
  {
    led(0, 0);
  }
}