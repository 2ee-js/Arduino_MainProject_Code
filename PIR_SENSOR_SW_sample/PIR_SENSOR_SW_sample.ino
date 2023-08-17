const uint8_t BUZZER_PIN = 8U;
const uint8_t PIR_PIN = 7U;
const uint8_t LED = 2U;
const uint8_t BUTTON_SW = 6U;

bool sentinel = false;
bool button_state = false;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200UL);
    Serial1.begin(9600UL);
    while(!Serial1);  //블루투스 연결될때까지 대기.
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(BUTTON_SW, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(!digitalRead(BUTTON_SW)) {
      button_state ^= HIGH;
      if(button_state) {
        Serial.println(F("Security MODE"));
        Serial1.println(F("방범 모드 ON"));
        sentinel = true;
      } else {
        Serial.println(F("Non security MODE"));
        Serial1.println(F("방범 모드 OFF"));
        sentinel = false;
      }
    }
      if(digitalRead(PIR_PIN) and sentinel) {
      Serial.println(F("A thief!"));
      Serial1.println(F("도둑이야!"));
      tone(BUZZER_PIN, 100.2);  //PWM 부저에게 PWM 신호를 전달.
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000UL);
      noTone(BUZZER_PIN);
      digitalWrite(LED_BUILTIN, LOW);
    }
}

