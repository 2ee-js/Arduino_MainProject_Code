#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h> //SPI 통신을 사용
#include <MFRC522DriverPinSimple.h> // dump file 보기 위해서
#include <MFRC522Debug.h> //debugging

class MFRC522DriverPinSimple sda_pin{MFRC522DriverPinSimple(53)};
class MFRC522DriverSPI driver{sda_pin};
class MFRC522 mfrc522{driver};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  mfrc522.PCD_Init(); //초기화.
  MFRC522Debug::PCD_DumpVersionToSerial(mfrc522, Serial);
  Serial1.begin(9600UL);
  Serial.println(F("Checking NRFID Card"));
  Serial1.println(F("Checking NRFID Card"));
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!mfrc522.PICC_IsNewCardPresent()) return; //카드의 정보를 읽는 것을 PICC 라고 함. 
  if(!mfrc522.PICC_ReadCardSerial()) return; //시리얼 준비가 안됬다면 리턴
  MFRC522Debug::PICC_DumpToSerial(mfrc522, Serial, &(mfrc522.uid));
}
