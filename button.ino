void setup()
{
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(27, OUTPUT);
  Serial.begin(115200);

  rgb(1,1,1);
}

char keyIn;

void loop()
{
  if(Serial.available())
  { 
    keyIn = Serial.read();
  }

  if(keyIn == 'r') {
    rgb(0,1,1);
    Serial.println("빨간색");
  }
  else if(keyIn == 'g') {
    rgb(1,0,1);
    Serial.println("초록색");
  }
  else if(keyIn == 'b') {
    rgb(1,1,0);
    Serial.println("파란색");
  }
  else if(keyIn == 'c') {
    rgb(1,1,1);
  }
}

void rgb(int r, int g, int b)
{
  digitalWrite(26, r);
  digitalWrite(25, g);
  digitalWrite(27, b);
}
