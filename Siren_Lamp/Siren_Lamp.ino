/*const uint8_t LED1={2U};//global space(or global scope) == 전역공간
const uint8_t LED2={3U};
const uint8_t LED3={4U};
const uint8_t LED4={5U};
const uint8_t LED5={6U};
const uint8_t LED6={7U};
const uint8_t LED7={8U};
const uint8_t LED8={9U};
*/
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};
auto setup()  -> void{
  // put your setup code here, to run once:
  /*for(int i=2; i<10; ++i){
    pinMode(i,OUTPUT);
  }*/
  /*
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  */
  for(auto&& i : LEDS){
    pinMode(i, OUTPUT);
  } 
  //python의 문법 for i in range(2,10):
  //               pinMode(i,OUTPUT); 과 비슷하다.
}
auto loop() -> void {
  // put your main code here, to run repeatedly:
  /*
  짝수번째 LED ON
  */
for(int index=0; index<8; ++index){
if(index%2==1){
  digitalWrite(LEDS[index],HIGH);
}else{
  digitalWrite(LEDS[index], LOW);
}
}
delay(300UL);
for(auto&& i : LEDS){
  digitalWrite(i,LOW);
}
//홀수번째 LED ON
for(int index=0; index<8; ++index){
if(index%2==0){
  digitalWrite(LEDS[index],HIGH);
}else{
  digitalWrite(LEDS[index],LOW);
}
}
delay(300UL);
for(auto&& i : LEDS){
  digitalWrite(i,LOW);
}
delay(100UL);
  for(int i=2; i<10; ++i ){
    digitalWrite(i,HIGH);
    delay(100UL);
  }
  delay(100UL);
  for(int i=9; i>=2; --i){
    digitalWrite(i, LOW);
    delay(100UL);
  }
  delay(100UL);
  /*digitalWrite(LED1, HIGH);
  delay(100UL);
  digitalWrite(LED2, 1); //HIGH == 1
  delay(100UL);
  digitalWrite(LED3, HIGH);
  delay(100UL);
  digitalWrite(LED4, HIGH);
  delay(100UL);
  digitalWrite(LED5, HIGH);
  delay(100UL);
  digitalWrite(LED6, HIGH);
  delay(100UL);
  digitalWrite(LED7, HIGH);
  delay(100UL);
  digitalWrite(LED8, HIGH);
  delay(100UL);
  digitalWrite(LED8, LOW);
  delay(100UL);
  digitalWrite(LED7, LOW); //HIGH == 1
  delay(100UL);
  digitalWrite(LED6, LOW);
  delay(100UL);
  digitalWrite(LED5, LOW);
  delay(100UL);
  digitalWrite(LED4, LOW);
  delay(100UL);
  digitalWrite(LED3, LOW);
  delay(100UL);
  digitalWrite(LED2, LOW);
  delay(100UL);
  digitalWrite(LED1, LOW);
  delay(100UL);
  digitalWrite(LED1, HIGH);
  delay(100UL);
  digitalWrite(LED2, 1); //HIGH == 1
  delay(100UL);
  digitalWrite(LED3, HIGH);
  delay(100UL);
  digitalWrite(LED4, HIGH);
  delay(100UL);
  digitalWrite(LED5, HIGH);
  delay(100UL);
  digitalWrite(LED6, HIGH);
  delay(100UL);
  digitalWrite(LED7, HIGH);
  delay(100UL);
  digitalWrite(LED8, HIGH);
  delay(100UL);
  digitalWrite(LED8, LOW);
  delay(100UL);
  digitalWrite(LED7, LOW); //HIGH == 1
  delay(100UL);
  digitalWrite(LED6, LOW);
  delay(100UL);
  digitalWrite(LED5, LOW);
  delay(100UL);
  digitalWrite(LED4, LOW);
  delay(100UL);
  digitalWrite(LED3, LOW);
  delay(100UL);
  digitalWrite(LED2, LOW);
  delay(100UL);
  digitalWrite(LED1, LOW);
  delay(100UL);*/
}
