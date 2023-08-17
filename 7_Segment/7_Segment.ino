const uint8_t FND[] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 
                        0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11100110};
void setup() {
  for(int i = 22; i <= 29; ++i) {
    pinMode(i, OUTPUT);
  }
  Serial.begin(115200UL);
}

void loop() {
    for(int j = 0; j <= 9; ++j)
    {
        for(int i = 2; i <= 9; ++i)
        {
          if(bitRead(FND[j], 9 - i)) {
            digitalWrite(i + 20, HIGH);
          } else {
            digitalWrite(i + 20, LOW);
          }
        }
      delay(1000UL);
    }
}
