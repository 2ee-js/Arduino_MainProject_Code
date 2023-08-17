const uint8_t SW_PIN1 {22U};
const uint8_t SW_PIN2 {24U};
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};
auto setup() -> void {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  
  pinMode(SW_PIN1, INPUT);
  pinMode(SW_PIN2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); //LED_BUILTIN -> 13 Pin LED
  
  for(auto&& i : LEDS){
    pinMode(i,OUTPUT);
  }
}

auto loop() -> void {
  // put your main code here, to run repeatedly:
  //1번 스위치
  bool sw_state1 = digitalRead(SW_PIN1); //HIGH == true or LOW == false -digitalRead이기 떄문에.
  if(sw_state1 == true){
    Serial.println(F("SWITCH1 ON"));
    //짝수 LED 
    for(int index=0; index<8; ++index){
      if(index%2==1){
        digitalWrite(LEDS[index], HIGH);
      }
    }
  }else{
    Serial.println("SWITCH1 OFF");
    for(int index=0; index<8; ++index){
      if(index%2==1){
      digitalWrite(LEDS[index], LOW);
      }
    }
  }
  //2번 스위치
  bool sw_state2 = digitalRead(SW_PIN2);
  if(sw_state2 == true){
    Serial.println(F("SWITCH2 ON"));
    //홀수 LED
    for(int index=0; index<8; ++index){
      if(index%2==0){
        digitalWrite(LEDS[index], HIGH);
      }
  }
  }else{
    Serial.println("SWITCH2 OFF");
    for(int index=0; index<8; ++index){
      if(index%2==0){
      digitalWrite(LEDS[index], LOW);
      }
    }
  }
  delay(50UL);
}
