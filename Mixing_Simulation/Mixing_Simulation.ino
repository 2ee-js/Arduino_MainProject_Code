#include <Arduino.h> //써도 되고, 안써도 된다. (C++언어 문법 - include => header 파일을 가져와서 다 넣으라는 것) java 및 python에서는 import를 사용
const uint8_t VR_PIN{A0}; //VR= 가변저항 A0에 연결할것이다.
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};
auto setup() -> void {
  // put your setup code here, to run once:
  pinMode(A0, INPUT); //INPUT 설정을 안해도 된다. 기본모드가 INPUT모드이기 때문이다.
    Serial.begin(115200UL); //시리얼 포트를 사용할 것이다. 속도는 115200이다.
     for(auto&& i : LEDS){
    pinMode(i, OUTPUT);
  } 
}

auto loop() -> void {
  // put your main code here, to run repeatedly:
  //값을 읽어오기 (값이 크기때문에 8비트로는 못불러와 uint16_t 16비트를 사용한다. int도 16비트)
  for(auto&& i : LEDS){
    digitalWrite(i,LOW);
  }
  int vr_value= analogRead(VR_PIN); //uint16_t vr_value도 사용 가능
    Serial.println(vr_value);
    if(0<=vr_value and vr_value<128){
      for(int i =2; i<=2; ++i){
      digitalWrite(i,HIGH);
      }
      Serial.println(F("1 LED "));
    }else if(128<=vr_value and vr_value<256){
      for(int i=2; i<=3; ++i){
       digitalWrite(i,HIGH);
      }
      Serial.println(F("2 LED "));
    }else if(256<=vr_value and vr_value<384){
       for(int i=2; i<=4; ++i){
       digitalWrite(i,HIGH);
      }
      Serial.println(F("3 LED "));
    }else if(384<=vr_value and vr_value<512){
       for(int i=2; i<=5; ++i){
       digitalWrite(i,HIGH);
      }
      Serial.println(F("4 LED "));
    }else if(512<=vr_value and vr_value<640){
       for(int i=2; i<=6; ++i){
       digitalWrite(i,HIGH);
      }
      Serial.println(F("5 LED "));
    }else if(640<=vr_value and vr_value<768){
       for(int i=2; i<=7; ++i){
       digitalWrite(i,HIGH);
      }
      Serial.println(F("6 LED "));
    }else if(768<=vr_value and vr_value<896){
       for(int i=2; i<=8; ++i){
       digitalWrite(i,HIGH);
      }
      Serial.println(F("7 LED "));
    }else if(896<=vr_value and vr_value<1024){
       for(int i=2; i<=9; ++i){
       digitalWrite(i,HIGH);
      }
      Serial.println(F("8 LED "));
    }else{}
    delay(100UL); //0.1초의 딜레이를 줌
}

/* 
  for(auto&& i : LEDS){
    digitalWrite(i,LOW);
  }

*/
//0~127
//128~255
//256~383
//384~511
//512~639
//640~767
//768~895
//896~1023