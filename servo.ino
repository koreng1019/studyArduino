#include <Servo.h>
Servo sm1;

void setup() {
  sm1.attach(16);

  sm1.write(0);
  delay(1000);
  sm1.write(90);
  delay(1000);
}

void loop() {

}
