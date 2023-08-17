const uint8_t BUZZER_PIN = 12U;
const uint8_t PIR_PIN = 7U;

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200Ul);
    Serial1.begin(9600UL);  //bluetooth 연결.
    while(!Serial1);  //블루투스연결될떄까지 대기.
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(PIR_PIN, INPUT);
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 버튼이 한번 눌렀을떄 보안작동(블루투스 전송)
  // 버튼이 한번 더 눌리면 보안해제 (블루투스 전송)
    if(digitalRead(PIR_PIN)) {
      Serial.println(F("A thief!"));
      Serial1.println(F("도둑이야!"));
      tone(BUZZER_PIN, 100.2);  //PWM 부저에게 PWM 신호를 전달.
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000UL);
      noTone(BUZZER_PIN);
      digitalWrite(LED_BUILTIN, LOW);
    }
}
