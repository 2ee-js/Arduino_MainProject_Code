#include <IRremote.hpp>
constexpr uint8_t IR_PIN{uint8_t (50U)}; 
class IRrecv irrecv {IRrecv(IR_PIN)};  //생성자 호출 -> {IRrecv(IR_PIN)} // 객체 -> irrecv
class decode_results result; //default 생성자. 
uint8_t FND[]{0b11111100, 0b01100000, 0b11011010, 
              0b11110010, 0b01100110, 
              0b10110110, 0b00111110, 0b11100100, 
              0b11111110, 0b11100110};
uint8_t RC[]{22,12,24,94,8,28,90,66,82,74};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(LED_BUILTIN, OUTPUT); //BUILTIN -> 13번 핀 MCU에 있는 L (light).
  irrecv.begin(IR_PIN, LED_BUILTIN); //초기화 설정 --> '하드웨어는 반드시 초기화 해주는게 좋음.

  Serial.begin(115200UL);
  for(int i=22; i<=29; ++i){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode()){//decode == 해석하다.
    Serial.println(irrecv.decodedIRData.command, HEX); //HEX --> 16진수로 출력시킴. // BIN --> 2진수 //DEX --> 10진수 (10진수가 default 이다.)
    uint16_t remote_number = irrecv.decodedIRData.command;
    Serial.print(F("remote_number: "));
    Serial.println(remote_number);
    //irrecv.start(10);
    for(int j=0; j<=9; ++j){
      for(int i=2; i<=9; ++i){
        if(irrecv.decodedIRData.command==RC[j]){
          if(bitRead(FND[j], 9 - i)){
            digitalWrite(i +20, HIGH);
          }else{
            digitalWrite(i + 20, LOW);
          }
        }
      delay(10UL);
      }
    }
    irrecv.resume();
  }
}
