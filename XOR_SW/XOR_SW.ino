const uint8_t SW1{26U};
const uint8_t LEDS[]{2U,3U,4U,5U,6U,7U,8U,9U};
bool button_state = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(SW1,INPUT);
  for(auto&&i : LEDS){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  //XOR 설정 -- static
  bool sw1_state = digitalRead(SW1);
  Serial.println(button_state);
  delay(50UL);
  if(!sw1_state){
    button_state=button_state ^ HIGH;
    if(button_state){
        for(int index=0; index<=7; ++index){
          digitalWrite(LEDS[index], HIGH);
        }
      }else{
        for(int index=0; index<=7; ++index){
          digitalWrite(LEDS[index],LOW);
        }
    }
  }
}

