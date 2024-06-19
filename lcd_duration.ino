#include <Wire.h>               // I2C 통신을 위한 라이브러리 포함
#include <LiquidCrystal_I2C.h>  // I2C 방식의 LCD를 제어하기 위한 라이브러리 포함

// I2C 주소 설정 (일반적으로 0x27 또는 0x3F 사용)
// 16x2 LCD 모듈 설정 (16 열, 2 행)
LiquidCrystal_I2C lcd(0x27, 16, 2);

int e = 8;
int t = 9;

unsigned long beforedu = 0;
unsigned long nowdu = 0;

unsigned long beforelcd = 0;
unsigned long nowlcd = 0;
int i = 15;


void setup() {
  //lCD 초기화
  lcd.init(); // LCD 모듈을 초기화하고 설정된 I2C 주소와 통신 시작
  lcd.backlight(); // LCD 백라이트 켜기
  pinMode(t, OUTPUT);
  pinMode(e, INPUT);
}

void loop() {
  nowdu = millis();
  if (nowdu - beforedu >= 100) 
  {
    beforedu = nowdu;
    digitalWrite(t, HIGH);
    delayMicroseconds(10);
    digitalWrite(t, LOW);
    float duration = pulseIn(e, HIGH);
    float distance = duration / 29 / 2;
    lcd.setCursor(0, 1);
    lcd.print ("duration : ");
    lcd.setCursor(11, 1);
    lcd.print ("      ");
    lcd.setCursor(11, 1);
    lcd.print (duration/100, 1);
  }

  nowlcd = millis();
  if (nowlcd - beforelcd >= 500)
  {
    beforelcd = nowlcd;
    if(i < 0)
    {
      i = 15;
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print ("                ");
      lcd.setCursor(i, 0);
      lcd.print ("MAKIST Coding!");
      i--;
    }
  }
}
