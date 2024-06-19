#include <Wire.h>               // I2C 통신을 위한 라이브러리 포함
#include <LiquidCrystal_I2C.h>  // I2C 방식의 LCD를 제어하기 위한 라이브러리 포함

// I2C 주소 설정 (일반적으로 0x27 또는 0x3F 사용)
// 16x2 LCD 모듈 설정 (16 열, 2 행)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //lCD 초기화
  lcd.init(); // LCD 모듈을 초기화하고 설정된 I2C 주소와 통신 시작
  lcd.backlight(); // LCD 백라이트 켜기

  //LCD에 메세지 출력
  lcd.setCursor(0, 0); // LCD 커서를 첫 번째 행, 첫 번째 열로 이동
  lcd.print("Start LCD"); // "Start LCD!!" 메시지를 출력

  lcd.setCursor(0, 1); // LCD 커서를 첫 번째 행, 두 번째 열로 이동
  lcd.print ("MAKIST Good!"); // "MAKIS Good!!" 메시지를 출력
}

void loop() {
  // put your main code here, to run repeatedly:

}
