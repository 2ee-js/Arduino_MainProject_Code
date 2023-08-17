/*
 LEFT_LED, RIGHT_LED, RELAY, BUTTON(PULLUP SW)
*/

const uint8_t BUTTON_SW{6U};
const uint8_t RELAY{30U};
const uint8_t LEFT_LED {13U};
const uint8_t RIGHT_LED {12U};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(LEFT_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUTTON_SW, INPUT); //PULL-UP SW
}

void loop() {
  // put your main code here, to run repeatedly:
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
  delay(50UL);
}
