#include "HCSR04.h"
#include "DHT.h"
HCSR04Sensor hcsr = HCSR04Sensor();
const uint8_t TRIGGER_PIN = 22U;
const uint8_t ECHO_PIN = 23U;
const uint8_t TEMPER_PIN = A0;  //온도 센서
DHT dht = DHT(TEMPER_PIN, 11);
void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200UL);
    Serial1.begin(9600UL);  // bluetooth
    dht.begin();
    hcsr.begin(TRIGGER_PIN, ECHO_PIN);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(dht.read()) { //온도 센서를 정상적으로 읽었다면
    float temperature = dht.readTemperature();
    double result = 0.0;
    hcsr.measureDistanceCm(temperature, &result);
    if(result <= 0.0 or result >= 400.0){
      Serial.println(F("Out of bound"));
      Serial1.println(F("Out of bound"));
      return;
    }
    Serial.print(F("Distance : "));
    Serial.println(result);
  }
  delay(1000UL);
}
