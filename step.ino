int mp1 = 8, mp2 = 9, mp3 = 10, mp4 = 11;
int mSpeed = 1200; //1200 = 최고속도, 9600 = 최저속도
int revCount = 1;
int angle = 5;
int stepangle = map(angle, 0, 360, 0, 520); //스텝모터의 최대 각으로 맵핑
int lookup[8] = {B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001};

void setup() {
  pinMode(mp1, OUTPUT); pinMode(mp2, OUTPUT); pinMode(mp3, OUTPUT); pinMode(mp4, OUTPUT);

}
int i, y, z; //모터 제어, 각도 제어, 회전수 제어용 변수 선언
void loop() {
  for(z = 0; z < revCount; z++) //회전수
  {
    for(y = 0; y < stepangle; y++) //회전각
    {
      for(i = 0; i < 8; i++)
      {
        digitalWrite(mp1, bitRead(lookup[i], 0));
        digitalWrite(mp2, bitRead(lookup[i], 1));
        digitalWrite(mp3, bitRead(lookup[i], 2));
        digitalWrite(mp4, bitRead(lookup[i], 3));
        delayMicroseconds(mSpeed);
      }
    }
    delay(200); //회전 속도
  }
  digitalWrite(mp1, LOW);
  digitalWrite(mp2, LOW);
  digitalWrite(mp3, LOW);
  digitalWrite(mp4, LOW);
  delay(500);
}