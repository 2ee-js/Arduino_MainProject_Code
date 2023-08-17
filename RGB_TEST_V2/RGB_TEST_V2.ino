#include <Arduino.h>
const uint8_t VR_PIN{A0};
enum RGB{
  RED=10, //가독성이 좋은 상수를 만든다.
  GREEN, //11
  BLUE //12
};
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(115200UL); //시리얼포트를 115200 속도로 초기화
  pinMode(RED, OUTPUT); //10번 핀 출력포트
  pinMode(GREEN, OUTPUT); //11번 핀 출력포트
  pinMode(BLUE, OUTPUT); //12번 핀 출력포트
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(RED, HIGH); //HIGH==1, 255 밝기가 최대
  /*
  0 ~ 255 빛의 밝기를 0(어두움) -> 255(제일밝음) : 256 -> 2^8 즉 8비트이다.
  */
  //analogWrite(RED, 0~255); //analogWrite는 0 ~ 255 값을 줄 수 있다 

  uint16_t light_value= analogRead(VR_PIN); //uint16_t vr_value도 사용 가능
  uint16_t mapped_light_value=map(light_value, 0,1023,0,255); 
  Serial.println(mapped_light_value); //debugging code
  
  
  for(int light = 0; light<=mapped_light_value; ++light){
    analogWrite(RED, light);
    analogWrite(GREEN, light);
    analogWrite(BLUE, light);
  }
  delay(10UL);
}
