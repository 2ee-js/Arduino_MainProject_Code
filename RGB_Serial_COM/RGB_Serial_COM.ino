//RGB 설정하세요.
const uint8_t RED {2U};
const uint8_t GREEN {3U};
const uint8_t BLUE {4U};
void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
    Serial.begin(115200UL);
}

void loop() {
    if(Serial.available() > 0) {
      uint8_t RED_value = Serial.parseInt();  //0 ~ 255까지 들어와짐.
      uint8_t GREEN_value = Serial.parseInt();
      uint8_t BLUE_value = Serial.parseInt();

      analogWrite(RED, RED_value);
      analogWrite(GREEN, GREEN_value);
      analogWrite(BLUE, BLUE_value);
    } 
    delay(100UL);
}
