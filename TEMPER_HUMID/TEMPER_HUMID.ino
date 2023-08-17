#include "DHT.h"
const uint8_t DHT_PIN {A2};
const uint8_t RELAY_SW {30U};
class DHT dht = DHT(DHT_PIN, 11);
void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200UL); // 시리얼포트 속도 셋팅
    dht.begin(); // 온, 습도 센서 시작.
    pinMode(RELAY_SW, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
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
      delay(500UL);
    }
}
