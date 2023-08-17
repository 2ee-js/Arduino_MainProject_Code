#include <LiquidCrystal_I2C.h>
// 내부적으로 I2C 선으로 연결이 되어 있어야 함.
class LiquidCrystal_I2C lcd(0x27, 16, 2); //0x3F

void setup() {
  // put your setup code here, to run once:
    lcd.init();  //초기화
    lcd.backlight();
    lcd.home();  //커서(0,0)에 위치.
    lcd.print("HELLO JAESUNG");
}

void loop() {
  // put your main code here, to run repeatedly:

}
