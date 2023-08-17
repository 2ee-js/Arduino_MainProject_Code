#include <Arduino.h>
const uint8_t LED_PIN {13U};

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT); //방어막 해제, OUTPUT- 전류가 밖으로 나간다.

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, HIGH); //HIGH-> 13번 핀에 5V 출력 (4.7~4.9V) 정도 출력이고 25mA
  delay(500UL); //1초 딜레이
  digitalWrite(LED_PIN, LOW); //LOW -> 전력을 끔
  delay(500UL); //1초 딜레이
}



