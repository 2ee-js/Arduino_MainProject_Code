const uint8_t VR_PIN{A0};
const uint8_t FND[] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 
                        0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11100110,
                        0b11101110, 0b00111110, 0b10011100, 0b01111010, 0b10011110, 0b10001110};
void setup() {
  for(int i = 22; i <= 29; ++i) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, INPUT);
  Serial.begin(115200UL);
}

void loop() {
  uint16_t vr_value = analogRead(VR_PIN);
  uint16_t mapped_vr_value = map(vr_value, 0, 1023, 0, 15);
  Serial.println(mapped_vr_value);
    for(int j = 0; j <= 15; ++j)
    {
        for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[mapped_vr_value], 9 - i)) {
            digitalWrite(i + 20, HIGH);
          } else {
            digitalWrite(i + 20, LOW);
          }
        }
      delay(10UL);
    }
}
