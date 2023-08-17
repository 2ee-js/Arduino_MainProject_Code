#include <Arduino.h>  
const uint8_t VR_PIN {A0}; // A0에 연결할것이다.
const uint8_t LEDS[]{2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};
void setup() {
  for(auto&& i : LEDS){
    pinMode(i, OUTPUT);} // LED 핀들을 모두 OUTPUT
    pinMode(VR_PIN, INPUT); // INPUT 설정은 안해도 된다. 기본모드가 INPUT
    Serial.begin(115200UL);  // 시리얼 포트를 사용할 것이다. 속도는 115200
}
void loop() {
  for(auto&& i : LEDS) {
      digitalWrite(i, LOW); // 모든 LED를 한번 다 꺼야 함.
      // 모든 전자들이 Sinker 로 빠진다. => 다 꺼진다.
  }
  uint16_t vr_value = analogRead(VR_PIN); //int 16 해도 상관없음.
  uint16_t mapped_vr_value = map(vr_value, 0, 1023, 0, 7);
  Serial.println(mapped_vr_value);   
  for(int i = 0; i <= mapped_vr_value; ++i){
    digitalWrite(LEDS[i], HIGH);
  }
  delay(10UL);  //0.01초
} 