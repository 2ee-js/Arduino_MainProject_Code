#include <IRremote.hpp>   //hpp -> C++에서 헤더파일. //# -> 매크로. 전처리.
constexpr uint8_t IR_PIN {50U};
const uint8_t FND[] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 
                        0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11100110};                      
class IRrecv irrecv {IRrecv(IR_PIN)}; //C++에서는 class 안써도 됨. 생성자 호출. irrecv = 객체.
class decode_results result;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200UL);
    pinMode(LED_BUILTIN, OUTPUT);  //13pin 옆 LED
    irrecv.begin(IR_PIN, LED_BUILTIN);  //하드웨어는 반드시 초기화 필수.
    for(int i = 22; i <= 29; ++i) {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
    if(irrecv.decode()) {     //decode= 해석하다.
      // Serial.println(vr_value, DEC);  DEC = 10진수  
      // Serial.println(irrecv.decodedIRData.command, HEX);  // HEX = 16진수
      //irrecv.resume();  //다음껄 받기 위해 끊어 줘야됨. 계속 신호를 받을거야!!
      // irrecv.start(10);
      uint16_t remote_number = irrecv.decodedIRData.command;
      Serial.print(F("Pressed number : "));
      Serial.println(remote_number);
        switch(remote_number){
        case 22:
          Serial.println("0");
          remote_number=0;
          break;
        case 12:
          Serial.println("1");
          remote_number=1;
          break;
        case 24:
          Serial.println("2");
          remote_number=2;
          break;
        case 94:
          Serial.println("3");
          remote_number=3;
          break;
        case 8:
          Serial.println("4");
          remote_number=4;
          break;
        case 28:
          Serial.println("5");
          remote_number=5;
          break;
        case 90:
          Serial.println("6");
          remote_number=6;
          break;
        case 66:
          Serial.println("7");
          remote_number=7;
          break;
        case 82:
          Serial.println("8");
          remote_number=8;
          break;
        case 74:
          Serial.println("9");
          remote_number=9;
          break;            
        default:
          Serial.println();
      }
      for(int j=0; j<=9; ++j){
        for(int i=2; i<=9; ++i){
            if(bitRead(FND[remote_number], 9 - i)){
              digitalWrite(i +20, HIGH);
            }else{
              digitalWrite(i + 20, LOW);
            }
        delay(10UL);
        }
      }
    }
   irrecv.resume();
}

