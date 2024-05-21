char bt1;
char bt2;

int btCheck = 0;

void btRead()
{
  if(Serial.available())
  {
    bt1 = Serial.read();
    Serial.write(bt1);
    bt.write(bt1);
  }

  if(bt.available())
  {
    bt2 = bt.read();
    Serial.write(bt2);
    bt.write(bt2);
  }

  if(bt1 == 'M' || bt2 == 'M')
  {
    btCheck = 1;
  }
  if(bt1 == 'm' || bt2 == 'm')
  {
    btCheck = 0;
    accel(0, 0, 0, 0);
    handle(hCenter);
  }
}

void passive()
{
  if(bt1 == 'F' || bt2 == 'F')
  {
    accel(0, 120, 0 ,120);
    handle(hCenter);
  }
  if(bt1 == 'B' || bt2 == 'B')
  {
    accel(120, 0 ,120, 0);
    handle(hCenter);
  }
  if(bt1 == 'S' || bt2 == 'S')
  {
    accel(0, 0, 0, 0);
    handle(hCenter);
  }
  if(bt1 == 'L' || bt2 == 'L')
  {
    accel(0, 120, 0 ,120);
    handle(hCenter-hMax);
  }
  if(bt1 == 'R' || bt2 == 'R')
  {
    accel(0, 120, 0 ,120);
    handle(hCenter+hMax);
  }
  if(bt1 == 'Q' || bt2 == 'Q')
  {
    accel(0, 120, 0 ,120);
    handle(hCenter-10);
  }
  if(bt1 == 'E' || bt2 == 'E')
  {
    accel(0, 120, 0 ,120);
    handle(hCenter+10);
  }
  if(bt1 == 'Z' || bt2 == 'Z')
  {
    accel(120, 0 ,120, 0);
    handle(hCenter-hMax);
  }
  if(bt1 == 'C' || bt2 == 'C')
  {
    accel(120, 0 ,120, 0);
    handle(hCenter+hMax);
  }
  if(bt1 == 'X' || bt2 == 'X')
  {
    accel(0, 0, 0, 120);
    handle(hCenter-hMax);
  }
  if(bt1 == 'Y' || bt2 == 'Y')
  {
    accel(0, 120, 0, 0);
    handle(hCenter+hMax);
  }
}