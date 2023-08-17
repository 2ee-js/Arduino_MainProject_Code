#include <IRremote.hpp>   //hpp -> C++에서 헤더파일. //# -> 매크로. 전처리.
constexpr uint8_t IR_PIN {50U};
class IRrecv irrecv {IRrecv(IR_PIN)}; //C++에서는 class 안써도 됨. 생성자 호출. irrecv = 객체.
class decode_results result;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200UL);
    pinMode(LED_BUILTIN, OUTPUT);  //13pin 옆 LED
    irrecv.begin(IR_PIN, LED_BUILTIN);  //하드웨어는 반드시 초기화 필수.

}

void loop() {
  // put your main code here, to run repeatedly:
    if(irrecv.decode()) {     //decode= 해석하다.
      // Serial.println(vr_value, DEC);  DEC = 10진수  
      Serial.println(irrecv.decodedIRData.command, HEX);  // HEX = 16진수
      //irrecv.resume();  //다음껄 받기 위해 끊어 줘야됨. 계속 신호를 받을거야!!
      irrecv.start(10);
    }   

}
