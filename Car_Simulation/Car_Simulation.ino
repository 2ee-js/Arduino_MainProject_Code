const uint8_t LEFT_LED {11U};
const uint8_t RIGHT_LED {12U};
const uint8_t RELAY_SWITCH {32U};
const uint8_t BUTTON_SWITCH {26U};
const uint8_t WATER_SENSOR {A8};
const uint8_t SERVOR_MOTOR {13U};
const uint8_t LIGHT_SENSOR {A3};
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200UL);  // unsigned long -> 32bit
    pinMode(LEFT_LED, OUTPUT);
    pinMode(RIGHT_LED, OUTPUT);
    pinMode(RELAY_SWITCH, OUTPUT);
    pinMode(BUTTON_SWITCH, INPUT);  //PULL-UP SWITCH;
    pinMode(WATER_SENSOR, INPUT);
    pinMode(SERVOR_MOTOR, OUTPUT);
    pinMode(LIGHT_SENSOR, INPUT);
    for(auto&&i : LEDS){  //LED 셋팅
    pinMode(i,OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
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
        Serial.println(F("RIGHT LED ON"));
        for(uint8_t i {0u}; i < 5; ++i) {
          digitalWrite(RELAY_SWITCH, HIGH);
          delay(500UL);
          digitalWrite(RELAY_SWITCH, LOW);
          delay(500UL);
      }
    } else {
        digitalWrite(LEFT_LED, HIGH);
        digitalWrite(RIGHT_LED, HIGH);
        Serial.println(F("LEFT, RIGHT LED ON"));
        for(uint8_t i {0u}; i < 5; ++i) {
          digitalWrite(RELAY_SWITCH, HIGH);
          delay(500UL);
          digitalWrite(RELAY_SWITCH, LOW);
          delay(500UL);
      }
    }
  }
  delay(50UL);
    uint16_t water_value = analogRead(WATER_SENSOR);
    water_value = constrain(water_value, 0, 580);
    uint16_t mapped_value = map(water_value, 0, 580, 100, 20);
    if(water_value > 5) {  //비를 감지
        for(int i = 0; i < 256; i += 10) {
          analogWrite(SERVOR_MOTOR, i);
          delay(mapped_value);
        }
    }
    Serial.print(F("WATER value : "));
    Serial.println(water_value);
    delay(100UL); //0.1 second

  uint16_t light_value = analogRead(LIGHT_SENSOR);
    light_value = constrain(light_value, 31, 730);
    uint16_t mapped_light_value = map(light_value, 31, 730, 0, 7); 
    Serial.print(F("Light value : "));
    Serial.println(light_value);
    Serial.println(mapped_light_value);
    for(int i = 0; i < 8; ++i){
          digitalWrite(LEDS[i], LOW);
        } 
      if(mapped_light_value >=3){
        for(int i = 0; i < 7 ; ++i){
          digitalWrite(LEDS[i], LOW);
        }
      } 
      if(mapped_light_value < 3){
        for(int i = 0; i < 8; ++i){
          digitalWrite(LEDS[i], HIGH);
        } 
      }
    delay(100UL);
}
