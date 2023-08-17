const uint8_t SERVO_MOTOR = 12U;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(SERVO_MOTOR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<256; i += 10){
    analogWrite(SERVO_MOTOR, i); // PULSE WIDTH 펄스의 폭
    delay(100UL); //서보의 속도 -> Frequency  빈도
  }
}
