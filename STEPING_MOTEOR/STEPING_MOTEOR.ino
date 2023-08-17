#include <Stepper.h>

const int STEP_PER_REVOLUTION = 64 * 32;  //2048 -> 1회전.
//(회전수, IN4, IN2, IN3, IN1);
class Stepper stepping = Stepper(STEP_PER_REVOLUTION, 8, 10, 9, 11);
void setup() {
  // put your setup code here, to run once:
    stepping.setSpeed(14L);  //RPM -> SPEED
    Serial.begin(115200UL);

}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.println(F("시계방향으로 전진"));
    stepping.step(STEP_PER_REVOLUTION); //한바퀴
    delay(1000UL);
    Serial.println(F("반시계방향으로 전진"));
    stepping.step(-STEP_PER_REVOLUTION); //거꾸로 한바퀴
    delay(1000UL);
}
