const uint8_t WATER_SENSOR {A8};
const uint8_t SERVOR_MOTOR {10U};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  pinMode(WATER_SENSOR, INPUT);
  pinMode(SERVOR_MOTOR, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t water_value = analogRead(WATER_SENSOR);
  water_value = constrain(water_value, 9, 650);
  uint16_t mapped_value = map(water_value, 0,650, 100, 50);
  Serial.print(F("Water value: "));
  Serial.println(water_value);
  if(water_value >5){ //비를 감지
    for(int i = 0; i<256; i +=10){
      analogWrite(SERVOR_MOTOR, i);
      delay(mapped_value);
    }
  }

  delay(100UL);
}
