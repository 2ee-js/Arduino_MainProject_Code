#include <LiquidCrystal_I2C.h>
#include "DHT.h"
class LiquidCrystal_I2C lcd(0x27, 16, 2);
class DHT dht(A0, 11);
void setup() {
    lcd.init();  //lcd 초기화.
    dht.begin(); 
    Serial.begin(115200UL);
    lcd.home();
    lcd.backlight();
    lcd.clear(); //화면을 한번 지워 주세요.
}
void loop() {
    float temperature = 0.0;
    float percentHumidity = 0.0F;
    if(dht.read()) {
      temperature = dht.readTemperature();
      percentHumidity = dht.readHumidity();}
    lcd.setCursor(0,0);
    lcd.print("TEMPER : ");
    lcd.print(temperature);
    lcd.setCursor(0,1);
    lcd.print("HUMID : ");
    lcd.print(percentHumidity);
    Serial.print(F("온도는 : "));
    Serial.println(temperature);
    Serial.print(F("습도는 : "));
    Serial.println(percentHumidity);
    delay(500UL);
    lcd.clear();
}
