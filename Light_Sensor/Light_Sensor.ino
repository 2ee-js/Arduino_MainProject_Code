const uint8_t LIGHT_SENSOR{A3};
//자동차 라이트 자동 ON, OFF 시뮬레이션
//포토폴리오 -> 향후 자동차에 자동으로 라이트가 들어오는 기능을 만들고 싶습니다.
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(LIGHT_SENSOR,INPUT);
  for(auto&&i :LEDS){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

  uint16_t light_value = analogRead(LIGHT_SENSOR);
  uint16_t mapped_light_value = map(light_value, 0,1000,0,9);
  Serial.print(F("Light value: "));
  Serial.println(light_value);
  Serial.print(F("Mapped_Light_value: "));
  Serial.println(mapped_light_value);
  delay(100UL);
  for(int i=0; i<8; ++i){
      digitalWrite(LEDS[i],LOW);
  }
  if(mapped_light_value==8){
   digitalWrite(LEDS[1],HIGH); 
  }else if(mapped_light_value==7){
    for(int i=0; i<2; ++i){
      digitalWrite(LEDS[i],HIGH);
    }
  }else if(mapped_light_value==6){
    for(int i=0; i<3; ++i){
      digitalWrite(LEDS[i],HIGH);
    }
  }else if(mapped_light_value==5){
    for(int i=0; i<4; ++i){
      digitalWrite(LEDS[i],HIGH);
    }
  }else if(mapped_light_value==4){
    for(int i=0; i<5; ++i){
      digitalWrite(LEDS[i],HIGH);
    }
  }else if(mapped_light_value==3){
    for(int i=0; i<6; ++i){
      digitalWrite(LEDS[i],HIGH);
    }
  }else if(mapped_light_value==2){
    for(int i=0; i<7; ++i){
      digitalWrite(LEDS[i],HIGH);
    }
  }else if(mapped_light_value==1){
    for(int i=0; i<8; ++i){
      digitalWrite(LEDS[i],HIGH);
    }
  }else{
    for(int i=0; i<8; ++i){
      digitalWrite(LEDS[i],LOW);
    }
  }
  delay(100UL);
}
