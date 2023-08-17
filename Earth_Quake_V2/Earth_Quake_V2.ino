#include <Arduino.h>
const uint8_t BUTTON_SW{26U};
const uint8_t TILT_SW {30U};
static uint8_t earth_quake_count {0U};
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(BUTTON_SW, INPUT_PULLUP);
  pinMode(TILT_SW, INPUT_PULLUP);
  for(auto&&i : LEDS){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  bool button_sw_state{digitalRead(BUTTON_SW)};
  bool tilt_sw_state{digitalRead(TILT_SW)};
  if(tilt_sw_state){
    ++earth_quake_count;
    if(earth_quake_count >8) earth_quake_count =8;
  }

  if(!button_sw_state){ //reset == initializing
    earth_quake_count=0;
    Serial.println(F("Initializing"));
    Serial.println(F("LEDS all OFF"));
    //ALL LEDS OFF
    for(int index=0; index<=7; ++index){
      digitalWrite(LEDS[index], LOW);
    }
    return;
  }
  switch(earth_quake_count){
    case 1:
      Serial.println(F("Richter scale: 1"));
      digitalWrite(LEDS[0], HIGH);
      break;
    case 2:
      Serial.println(F("Richter scale: 2"));
      digitalWrite(LEDS[0], HIGH);
      digitalWrite(LEDS[1], HIGH);
      break;
    case 3:
      Serial.println(F("Richter scale: 3"));
      for(int index=0; index<3; ++index){
         digitalWrite(LEDS[index], HIGH);
      }
      break;
    case 4:
      Serial.println(F("Richter scale: 4"));
      for(int index=0; index<4; ++index){
         digitalWrite(LEDS[index], HIGH);
      }
      break;
    case 5:
      Serial.println(F("Richter scale: 5"));
      for(int index=0; index<5; ++index){
         digitalWrite(LEDS[index], HIGH);
      }
      break;    
    case 6:
      Serial.println(F("Richter scale: 6"));
      for(int index=0; index<6; ++index){
         digitalWrite(LEDS[index], HIGH);
      }
      break;  
    case 7:
      Serial.println(F("Richter scale: 7"));
      for(int index=0; index<7; ++index){
         digitalWrite(LEDS[index], HIGH);
      }
      break; 
    case 8:
      Serial.println(F("Richter scale: 8"));
      for(int index=0; index<8; ++index){
         digitalWrite(LEDS[index], HIGH);
      }
      break;
    default:
      Serial.println(F("No Earth Quake - Richter scale: 0"));
      for(int index=0; index<8; ++index){
        digitalWrite(LEDS[index], LOW);
      }
    delay(100UL);   
  }
}
