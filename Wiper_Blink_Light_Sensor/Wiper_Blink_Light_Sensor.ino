const uint8_t WATER_SENSOR {A8};
const uint8_t SERVOR_MOTOR {10U};
//깜박이
const uint8_t BUTTON_SW{26U};
const uint8_t RELAY{22U};
const uint8_t LEFT_LED {13U};
const uint8_t RIGHT_LED {12U};
//자동 라이트
const uint8_t LIGHT_SENSOR{A3};
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  //와이퍼
  pinMode(WATER_SENSOR, INPUT);
  pinMode(SERVOR_MOTOR, OUTPUT);
  //깜박이
  pinMode(LEFT_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUTTON_SW, INPUT);
  //자동라이트
   pinMode(LIGHT_SENSOR,INPUT);
  for(auto&&i :LEDS){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //와이퍼
  uint16_t water_value = analogRead(WATER_SENSOR);
  water_value = constrain(water_value, 9, 650);
  uint16_t mapped_value = map(water_value, 0,650, 100, 50);
  Serial.print(F("Water value: "));
  Serial.println(water_value);
  if(water_value >5){ //비를 감지
    for(int i = 0; i<256; i +=10){
      analogWrite(SERVOR_MOTOR, i);
      delay(mapped_value);
    }
  }
  //깜박이
  static uint8_t button_count {0u};
  static bool button_sw_state {false};
  digitalWrite(LEFT_LED, LOW);
  digitalWrite(RIGHT_LED, LOW);
  digitalWrite(RELAY, LOW); //초기화

  if(! digitalRead(BUTTON_SW)){
    Serial.println(F("BUTTON-SWITCH-ON"));
    ++button_count;
    if(button_count ==3) button_count=0;
    if(button_count % 3 ==1){
      digitalWrite(LEFT_LED, HIGH);
      if(water_value >5){ //비를 감지
        for(int i = 0; i<256; i +=10){
        analogWrite(SERVOR_MOTOR, i);
        delay(mapped_value);
        }
      }
      Serial.println(F("LEFT_LED ON"));
      for(uint8_t i {0u}; i<5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
      }
    }else if(button_count % 3 ==2){
      digitalWrite(RIGHT_LED, HIGH);
      Serial.println(F("RIGHT_LED ON"));
      for(uint8_t i {0u}; i<5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
      }
    }else{
      digitalWrite(LEFT_LED, HIGH);
      digitalWrite(RIGHT_LED, HIGH);
      Serial.println(F("EMERGENCY LED ON"));
      for(uint8_t i {0u}; i<5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
      }
    }
  }
  //자동라이트
  uint16_t light_value = analogRead(LIGHT_SENSOR);
  light_value=constrain(light_value, 596,1000);
  uint16_t mapped_light_value = map(light_value, 596,1000,0,202);
  Serial.print(F("Light value: "));
  Serial.println(light_value);
  Serial.print(F("Mapped_Light_value: "));
  Serial.println(mapped_light_value);
  delay(100UL);
  if(mapped_light_value>150){
    for(int i=0; i<8; ++i){
      digitalWrite(LEDS[i],LOW);
    }
  }
  if(mapped_light_value<=150){
    for(int i=0; i<8; ++i){
      digitalWrite(LEDS[i], HIGH);
    }
  }
  delay(50UL);
}
