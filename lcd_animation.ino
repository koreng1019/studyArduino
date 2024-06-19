#include <Wire.h>               // I2C 통신을 위한 라이브러리 포함
#include <LiquidCrystal_I2C.h>  // I2C 방식의 LCD를 제어하기 위한 라이브러리 포함

// I2C 주소 설정 (일반적으로 0x27 또는 0x3F 사용)
// 16x2 LCD 모듈 설정 (16 열, 2 행)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  //lCD 초기화
  lcd.init(); // LCD 모듈을 초기화하고 설정된 I2C 주소와 통신 시작
  lcd.backlight(); // LCD 백라이트 켜기
}

void loop() {
  //문자열을 오른쪽에서 왼쪽으로 이동시키는 애니메이션
  for(int position = 15; position >= 0; position--)
  {
    lcd.clear(); //화면을 지움
    lcd.setCursor(position, 0); // 커서를 새로운 위치로 이동
    lcd.print("Start LCD"); //텍스트를 출력
    delay(300); // 지연 시간 (밀리초 단위)
  }
  delay(1000); //문자열이 끝에 도달한 후 잠시 대기
}
