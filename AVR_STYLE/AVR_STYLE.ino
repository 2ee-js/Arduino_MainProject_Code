#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 16000000UL // 클럭수 16.0Mhz

//Arduino : PIN13 -> PB7, Arduino : PIN3 -> PE5 ==> PIN3에 스위치를 연결
int main(){
  DDRB = 0b10000000; //pinMode(13, OUTPUT); --> OUTPUT ==1 //0b -> 비트
  //DDRE = ~0b00100000;
  //1의 자리 -> PB0 / 10의 자리 -> PB1 / 100의 자리 -> PB2 / 1000의 자리 -> PB3 ....etc

  for(;;){ // (;;) --> 무한 루프
    uint8_t button_state = PINE & 0x20; // --> 0x는 16진수 0b -> 비트이다. // digitalRead(3); -> 3번 핀을 읽어오기
    if(button_state){
      PORTB= 0x80; //0b10000000 (digiterWrite(13,HIGH));
    }else{
      PORTB= 0x00; //0b00000000 (digiterWrite(13,LOW))
    }
  }
  return 0;
}
