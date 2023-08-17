const uint8_t BUZZER_PIN=8U;
const uint8_t PIR_PIN =7U;
const uint8_t LED =2U;
const uint8_t BUTTON=6U;
int count =0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  Serial1.begin(9600UL);
  while(!Serial1); //블루투스 연결될때까지 대기
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON,INPUT);
}

void loop() {
  bool sw_state =digitalRead(BUTTON);
  // put your main code here, to run repeatedly:
  //버튼이 눌렸을 때 보안작동(블루투스로 전송) - 보안 작동 ( 작동 하였을 때 움직임이 감지되면 led 깜빡거리고 소리 나게)
  //버튼이 한번 더 눌리면 보안 해제 (블루투스 전송)- 보안 해제 (해제 하였을 때 움직여도 감지 x)
  if(sw_state==LOW){
    count++;
    delay(300UL);
    Serial.println(count);
    if(count==1){
      Serial.println(F("보안을 작동합니다."));
      Serial1.println(F("보안을 작동합니다."));
    }else{
      Serial.println(F("보안을 해제합니다."));
      Serial1.println(F("보안을 해제합니다."));
    }
  }
  if(count==1){
      if(digitalRead(PIR_PIN)){
        Serial.println(F("A thief!"));
        Serial1.println(F("도둑이야!"));
        tone(BUZZER_PIN, 100.2); //부저에게 PWM신호를 전달.
        digitalWrite(LED, HIGH);
        delay(1000UL);
        noTone(BUZZER_PIN); //부저 소리 차단.
        digitalWrite(LED,LOW);
      }
    }else if(count==0){
      if(digitalRead(PIR_PIN)){
        noTone(BUZZER_PIN); //부저 소리 차단.
        digitalWrite(LED,LOW);
      }
    }else if(count==2){
      count=0;
    }
}