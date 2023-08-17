const uint8_t SW1{26U};
const uint8_t SW2{28U};
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(SW1,INPUT);
  pinMode(SW2,INPUT);
  for(auto&& i : LEDS){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //Pull-Up-SW
  bool sw1_state = digitalRead(SW1);
  bool sw2_state = digitalRead(SW2);
  delay(50UL);
  //1번 스위치
  if(sw1_state == LOW){
    Serial.println(F("SW1 ON"));
    //홀수 번호의 LED 꺼짐
    for(int index=0; index<=7; ++index){
      if(index%2==0){
        digitalWrite(LEDS[index],LOW);
      }
    }
  }else{
    Serial.println(F("SW1 OFF"));
    for(int index=0; index<=7; ++index){
      if(sw2_state ==LOW){
        if(index%2==1){
        digitalWrite(LEDS[index],LOW);
        }
      }else{
      digitalWrite(LEDS[index],HIGH);
      }
    }
  }
  //2번 스위치
  if(sw2_state== LOW){
    Serial.println(F("SW2 ON"));
    //홀수 번호의 LED 꺼짐
    for(int index=0; index<=7; ++index){
      if(index%2==1){
        digitalWrite(LEDS[index], LOW);
      }
    }
  }
}
