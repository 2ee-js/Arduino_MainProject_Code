#include <Arduino.h>
const uint8_t BUTTON_SW{26U};
const uint8_t RELAY{22U};
const uint8_t LED1 {12U};
const uint8_t LED2 {13U};
int count=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(BUTTON_SW, INPUT_PULLUP);
  pinMode(RELAY, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}
bool state = false;
void loop() {
  // put your main code here, to run repeatedly:
  uint8_t button_sw_state = digitalRead(BUTTON_SW);
  delay(100UL);
  Serial.println(count);
  if(button_sw_state==LOW){
    ++count;
    delay(100UL);
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
  }
  if(count==1){
    if(button_sw_state&&state == false) {
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      for(int i=0; i < 5; i++) {
      digitalWrite(RELAY, HIGH);
      delay(500UL);
      digitalWrite(RELAY, LOW);
      delay(500UL);
    }
    state=true;
  }
  }else if(count==2){
    if(button_sw_state&&state == true) {
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      for(int i=0; i < 5; i++) {
      digitalWrite(RELAY, HIGH);
      delay(500UL);
      digitalWrite(RELAY, LOW);
      delay(500UL);
      }
      state=false;
    }
  }else if(count==3){
    if(button_sw_state&&state == false) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
      for(int i=0; i < 5; i++) {
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
      }
      state=true;
    }
  }else if(count==4){
    count=1;
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,LOW);
    state=false;
  }
}