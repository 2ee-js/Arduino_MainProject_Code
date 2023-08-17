#include "DHT.h"
class DHT dht(A0, 11);
const uint8_t RELAY_SW {30U};
void setup() {
  dht.begin();
  Serial.begin(115200UL);  //COM 통신용
  pinMode(RELAY_SW, OUTPUT); //RELAY
}
void loop() {
  float temperature = 0.0;
    float percentHumidity = 0.0F;
    if(dht.read()) {
      temperature = dht.readTemperature();
      percentHumidity = dht.readHumidity();}
    if(Serial.available()) {
      String str_command = Serial.readString();  // SW_ON
      str_command.trim();
      str_command.toUpperCase();      
      if(str_command == "SW_ON")
      { digitalWrite(RELAY_SW, HIGH);
        delay(500UL);
      } else if(str_command == "SW_OFF") {
        digitalWrite(RELAY_SW, LOW);
        delay(500UL);
      } else {
      }
    }
    Serial.print(temperature);
    Serial.print(",");
    Serial.println(percentHumidity);
    delay(700UL);
}
