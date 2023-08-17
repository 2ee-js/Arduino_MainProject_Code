
const uint8_t LEFT_LED {11U};
const uint8_t RIGHT_LED {12U};
const uint8_t RELAY_SWITCH {32U};
const uint8_t BUTTON_SWITCH {26U};
void setup() {
    Serial.begin(115200UL);  // unsigned long -> 32bit
    pinMode(LEFT_LED, OUTPUT);
    pinMode(RIGHT_LED, OUTPUT);
    pinMode(RELAY_SWITCH, OUTPUT);
    pinMode(BUTTON_SWITCH, INPUT);  //PULL-UP SWITCH;

}

void loop() {
    static uint8_t button_count {0u};
    static bool button_switch_state {false};
    digitalWrite(LEFT_LED, LOW);
    digitalWrite(RIGHT_LED, LOW);
    digitalWrite(RELAY_SWITCH, LOW);  //초기화

    if(!digitalRead(BUTTON_SWITCH)) {
      Serial.println(F("BUTTON SWITCH ON"));
      ++button_count;
      if(button_count == 3) button_count = 0;
      if(button_count % 3 == 1) {
        digitalWrite(LEFT_LED, HIGH);
        Serial.println(F("LEFT LED ON"));
        for(uint8_t i {0u}; i < 5; ++i) {
          digitalWrite(RELAY_SWITCH, HIGH);
          delay(500UL);
          digitalWrite(RELAY_SWITCH, LOW);
          delay(500UL);
        }
      } else if(button_count % 3 == 2) {
        digitalWrite(RIGHT_LED, HIGH);
        Serial.println(F("LEFT LED ON"));
        for(uint8_t i {0u}; i < 5; ++i) {
          digitalWrite(RELAY_SWITCH, HIGH);
          delay(500UL);
          digitalWrite(RELAY_SWITCH, LOW);
          delay(500UL);
      }
    } else {
        digitalWrite(LEFT_LED, HIGH);
        digitalWrite(RIGHT_LED, HIGH);
        Serial.println(F("LEFT LED ON"));
        for(uint8_t i {0u}; i < 5; ++i) {
          digitalWrite(RELAY_SWITCH, HIGH);
          delay(500UL);
          digitalWrite(RELAY_SWITCH, LOW);
          delay(500UL);
      }
    }
  }
  delay(50UL);
}
