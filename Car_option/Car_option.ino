// 거리 감지  
#include "HCSR04.h"
#include "DHT.h"
HCSR04Sensor hcsr = HCSR04Sensor();
const uint8_t TRIGGER_PIN = 40U;
const uint8_t ECHO_PIN = 41U;
const uint8_t TEMPER_PIN = A2;  //온도 센서
DHT dht = DHT(TEMPER_PIN, 11);

const uint8_t WATER_SENSOR {A8};
const uint8_t SERVOR_MOTOR {10U};
//깜박이
const uint8_t BUTTON_SW{6U};
const uint8_t RELAY{30U};
const uint8_t LEFT_LED {13U};
const uint8_t RIGHT_LED {12U};

//부저
const uint8_t BUZZER_PIN=8U;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  Serial1.begin(9600UL);
  while(!Serial1); //블루투스 연결될때까지 대기
  //와이퍼
  pinMode(WATER_SENSOR, INPUT);
  pinMode(SERVOR_MOTOR, OUTPUT);
  //깜박이
  pinMode(LEFT_LED, OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(RELAY, OUTPUT);
  pinMode(BUTTON_SW, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //와이퍼
  uint16_t water_value = analogRead(WATER_SENSOR);
  water_value = constrain(water_value, 0, 580);
  uint16_t mapped_value = map(water_value, 0,580, 100, 20);
  Serial.print(F("Water value: "));
  Serial.println(water_value);
  if(water_value >5){ //비를 감지
    for(int i = 0; i<256; i +=10){
      analogWrite(SERVOR_MOTOR, i);
      delay(mapped_value);
    }
  }
  //깜박이
  static uint8_t button_count {0u};
  static bool button_sw_state {false};
  digitalWrite(LEFT_LED, LOW);
  digitalWrite(RIGHT_LED, LOW);
  digitalWrite(RELAY, LOW); //초기화

  if(! digitalRead(BUTTON_SW)){
    Serial.println(F("BUTTON-SWITCH-ON"));
    ++button_count;
    if(button_count ==3) button_count=0;
    if(button_count % 3 ==1){
      digitalWrite(LEFT_LED, HIGH);
      if(water_value >5){ //비를 감지
        for(int i = 0; i<256; i +=10){
        analogWrite(SERVOR_MOTOR, i);
        delay(mapped_value);
        }
      }
      Serial.println(F("LEFT_LED ON"));
      for(uint8_t i {0u}; i<5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
      }
    }else if(button_count % 3 ==2){
      digitalWrite(RIGHT_LED, HIGH);
      Serial.println(F("RIGHT_LED ON"));
      for(uint8_t i {0u}; i<5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
      }
    }else{
      digitalWrite(LEFT_LED, HIGH);
      digitalWrite(RIGHT_LED, HIGH);
      Serial.println(F("EMERGENCY LED ON"));
      for(uint8_t i {0u}; i<5; ++i){
        digitalWrite(RELAY, HIGH);
        delay(500UL);
        digitalWrite(RELAY, LOW);
        delay(500UL);
      }
    }
  }
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
