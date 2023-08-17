const uint8_t TILT_SW= 30U;
const uint8_t RESET_SW=26U;
const uint8_t LED=13U;
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};
int count =0;
int time_count=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(LED,OUTPUT);
  pinMode(RESET_SW,INPUT_PULLUP);
  for(auto&&i :LEDS){
    pinMode(i, OUTPUT);
  }
  //INPUT_PULLUP 내부적으로 풀업 저항 상태가 된다.
  pinMode(TILT_SW, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool tilt_state = digitalRead(TILT_SW);
  if(tilt_state){
    //지진 카운트 세기
    Serial.println(F("HIGH STATE"));
    ++count;
    Serial.println(count);
    //카운트 8이상시 LED 빛 들어오기 및 시간 카운트 초기화.
    if(count >=8){
      digitalWrite(LED, HIGH);
      time_count = 0;
    }else{
      digitalWrite(LED,LOW);
    }
    //카운트 단계별 LED 빛 들어오가.
    if(count >=3){
      digitalWrite(LEDS[0], HIGH);
      if(count >=6){
        digitalWrite(LEDS[1], HIGH);
        if(count >=9){
          digitalWrite(LEDS[2], HIGH);
          if(count >=12){
            digitalWrite(LEDS[3], HIGH);
            if(count >=15){
              digitalWrite(LEDS[4], HIGH);
              if(count >=18){
                digitalWrite(LEDS[5], HIGH);
                if(count >= 21){
                  digitalWrite(LEDS[6], HIGH);
                  if(count >=24){
                    digitalWrite(LEDS[7], HIGH);
                  }
                }
              }
            }
          }
        }
      }
    }
  }else{
    //카운트 8이상시 1초에 한번 시간 카운트 증가.
    //시간 카운트 10초가 되면 초기화.
    Serial.println(F("LOW STATE"));
      if(count >=8){
        delay(1000UL);
        ++time_count;
        Serial.println(time_count);
        if(time_count == 10){
          digitalWrite(LED, LOW);
          count=0;
          time_count =0;
          for(int i=0; i<=7; ++i){
          digitalWrite(LEDS[i], LOW);
        }
      }
    }
  }
  
  delay(100UL);
  //초기화 버튼
  bool reset_state = digitalRead(RESET_SW);
  if(reset_state == LOW){
  Serial.println(F("Reset"));
  count=0;
  digitalWrite(LED,LOW);
  }
  delay(100UL);
}
