const uint8_t WATER_SENSOR {A8};
const uint8_t SERVOR_MOTOR {12U};
void setup() {
    Serial.begin(115200UL);
    pinMode(WATER_SENSOR, INPUT);
    pinMode(SERVOR_MOTOR, OUTPUT);
}
void loop() {
    uint16_t water_value = analogRead(WATER_SENSOR);
    water_value = constrain(water_value, 0, 580);
    uint16_t mapped_value = map(water_value, 0, 580, 100, 20);
    if(water_value > 5) {  //비를 감지
        for(int i = 0; i < 256; i += 10) {
          analogWrite(SERVOR_MOTOR, i);
          delay(mapped_value);
        }
    }
    Serial.print(F("WATER value : "));
    Serial.println(water_value);
    delay(100UL); //0.1 second
}
