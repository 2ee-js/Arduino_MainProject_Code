#include <Arduino.h>  //써도되고, 안써도 된다.
const uint8_t VR_PIN {A0}; // A0에 연결할것이다.
const uint8_t LEDS[]{2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};
void setup() {
  // put your setup code here, to run once:
  for(auto&& i : LEDS)
  {
    pinMode(i, OUTPUT);
  } // LED 핀들을 모두 OUTPUT
  pinMode(VR_PIN, INPUT); // INPUT 설정은 안해도 된다. 기본모드가 INPUT
    Serial.begin(115200UL);  // 시리얼 포트를 사용할 것이다. 속도는 115200
}

void loop() {
  // put your main code here, to run repeatedly:
  for(auto&& i : LEDS) {
      digitalWrite(i, LOW); // 모든 LED를 한번 다 꺼야 함.
      // 모든 전자들이 Sinker 로 빠진다. => 다 꺼진다.
  }
  uint16_t vr_value = analogRead(VR_PIN); //int 16 해도 상관없음.
    Serial.println(vr_value);
    if(0 <= vr_value and vr_value < 128) {
      Serial.println(F("1 LED "));
      digitalWrite(LEDS[0], HIGH);
    }
    else if(128 <= vr_value and vr_value < 256) {
      Serial.println(F("2 LED "));
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
    }
    else if(256 <= vr_value and vr_value < 384) {
      Serial.println(F("3 LED "));
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
      digitalWrite(LEDS[2], HIGH);
    }
    else if(384 <= vr_value and vr_value < 512) {
      Serial.println(F("4 LED "));
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
      digitalWrite(LEDS[2], HIGH);
      digitalWrite(LEDS[3], HIGH);
    }
    else if(512 <= vr_value and vr_value < 640) {
      Serial.println(F("5 LED "));
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
      digitalWrite(LEDS[2], HIGH);
      digitalWrite(LEDS[3], HIGH);
      digitalWrite(LEDS[4], HIGH);
    }
    else if(640 <= vr_value and vr_value < 768) {
      Serial.println(F("6 LED "));
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
      digitalWrite(LEDS[2], HIGH);
      digitalWrite(LEDS[3], HIGH);
      digitalWrite(LEDS[4], HIGH);
      digitalWrite(LEDS[5], HIGH);
    }
    else if(768 <= vr_value and vr_value < 869) {
      Serial.println(F("7 LED "));
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
      digitalWrite(LEDS[2], HIGH);
      digitalWrite(LEDS[3], HIGH);
      digitalWrite(LEDS[4], HIGH);
      digitalWrite(LEDS[5], HIGH);
      digitalWrite(LEDS[6], HIGH);
    }
    else if(869 <= vr_value and vr_value < 1024) {
      Serial.println(F("8 LED "));
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
      digitalWrite(LEDS[2], HIGH);
      digitalWrite(LEDS[3], HIGH);
      digitalWrite(LEDS[4], HIGH);
      digitalWrite(LEDS[5], HIGH);
      digitalWrite(LEDS[6], HIGH);
      digitalWrite(LEDS[7], HIGH);
    }
    delay(100UL); // 0.1초
}
