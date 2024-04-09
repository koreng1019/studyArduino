void setup() {
  pinMode(4, INPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

int d = 0; // 1이면 중복.
int c = 0; // 터치카운트

void loop() {
  touchcontrol(4, 7); // 터치여부 확인 및 중복 체크.
  if(c == 0) {
    rgbled(255,255,255);
  }
  else if(c == 1) {
    rgbled(0,255,255);
  }
  else if(c == 2) {
    rgbled(255,0,255);
  }
  else if(c == 3) {
    rgbled(255,255,0);
  }
  else if(c == 4) {
    rgbled(255,0,0);
  }
  else if(c == 5) {
    rgbled(0,255,0);
  }
  else if(c == 6) {
    rgbled(0,0,255);
  }
  else if(c == 7) {
    ledblink(5);
  }
}

void touchcontrol(int n, int m) {
  if(digitalRead(n) == 1) {
    if(d == 0) {
      d = 1;
      if(c < m) {
        c = c + 1;
      }
      else {
        c = 0;
      }
    }
  }
  else {
    d = 0;
  }
}

void rgbled(int R, int G, int B) {
  analogWrite(10, R);
  analogWrite(9, G);
  analogWrite(11, B);
}

void ledblink(int h) {
  for(int i = 0; i < h; i++) {
    rgbled(0,0,0);
    delay(50);
    rgbled(255,255,255);
    delay(50);
  }
}