const uint8_t SW1 {22U};
const uint8_t SW2 {23U};
const uint8_t LEDS[]{2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U};
void setup() {
  Serial.begin(115200UL);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  for(auto&& i : LEDS)
  {
    pinMode(i, OUTPUT);
  }
}
void loop() {
  bool sw1_state = digitalRead(SW1);
  delay(50UL);
  if(sw1_state) {
        Serial.println(F("SW1 OFF"));
    for(int index=0; index<8; ++index) {
      if(index%2==1) {
        digitalWrite(LEDS[index], HIGH);
      }
    }
  }else {
    Serial.println(F("SW1 ON"));
    for(int index=0; index<8; ++index)
        if(index%2==1){
          digitalWrite(LEDS[index], LOW);
    }
  }
  delay(50UL);
  bool sw2_state = digitalRead(SW2);
  if(sw2_state) {
    Serial.println(F("SW2 OFF"));
     for(int index=0; index<8; ++index){
      if(index%2==0){
        digitalWrite(LEDS[index],HIGH);
      }
     }
    }else {
      Serial.println(F("SW2 ON"));
       for(int index=0; index<8; ++index)
        if(index%2==0){
          digitalWrite(LEDS[index],LOW);
        } 
      }
      delay(50UL);
}

