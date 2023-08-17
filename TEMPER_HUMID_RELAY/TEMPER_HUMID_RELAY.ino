#include "DHT.h"
const uint8_t DHT_PIN {A2};
const uint8_t RELAY_SW {30U};
const uint8_t LED {11U};
class DHT dht = DHT(DHT_PIN, 11);
void setup() {
    Serial.begin(115200UL); // 시리얼포트 속도 셋팅
    dht.begin(); // 온, 습도 센서 시작.
    pinMode(RELAY_SW, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    if(dht.read()) {  //dht 센서에서 문제 없이 읽었다면
      float temperature = dht.readTemperature();  //16bit
      float percentHumidity = dht.readHumidity();
      Serial.print(F("온도 : "));
      Serial.println(String(temperature) + " C");
      Serial.print(F("습도 : "));
      Serial.println(String(percentHumidity) + " %");
      float heat = dht.computeHeatIndex(temperature, percentHumidity);
      Serial.print(F("열 : "));
      Serial.println(heat);

    if(temperature >= 28) {
      digitalWrite(LED, HIGH);
      digitalWrite(RELAY_SW, HIGH);
      delay(500UL);
      digitalWrite(RELAY_SW, LOW);
      delay(500UL);      
    }
  }
    delay(500UL);
}

