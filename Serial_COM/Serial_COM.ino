const uint8_t LED {13U};   // LED_BUILTIN => L (13);
void setup() {
  Serial.begin(115200UL);
  pinMode(LED, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
     char read_data = static_cast<char>(Serial.read());  //1byte 가져옵니다. // 버퍼가 빈다.
     if(read_data == '1') {
       digitalWrite(LED, HIGH);
     } else if(read_data == '0') {
       digitalWrite(LED, LOW);
     } else if(read_data == '\n') {
       Serial.println();
     } else {
       Serial.println(F("You pressed the wrong number."));
     }
  }
  delay(100UL); //0.1s delay
}
