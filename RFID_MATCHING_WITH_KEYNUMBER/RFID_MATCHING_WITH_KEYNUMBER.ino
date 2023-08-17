#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h> //SPI 통신을 사용
#include <MFRC522DriverPinSimple.h> // dump file 보기 위해서
#include <MFRC522Debug.h> //debugging

class MFRC522DriverPinSimple sda_pin{MFRC522DriverPinSimple(53)};
class MFRC522DriverSPI driver{sda_pin};
class MFRC522 mfrc522{driver};
const String MASTER_CARD_UID{String("F14C751B")};
const String MASTER2_CARD_UID{String("70CA6621")};
//서보모터
const uint8_t SERVOR_MOTOR{10U};
//부저
const uint8_t BUZZER_PIN =4U;
int tone_value[]={524,660,784,524, 660, 524};
int wrong_count =0;
bool wrong_value =false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200UL);
  Serial1.begin(9600UL); //블루투스
  mfrc522.PCD_Init(); //초기화
  Serial.println(F("Checking UID"));
  //서보모터
  pinMode(SERVOR_MOTOR, OUTPUT);
  //부저
  pinMode(BUZZER_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(!mfrc522.PICC_IsNewCardPresent()) return; //카드의 정보를 읽는 것을 PICC 라고 함. 
  if(!mfrc522.PICC_ReadCardSerial()) return; //시리얼 준비가 안됬다면 리턴   //이거 두개는 반드시 해야 함.
  String tagID = ""; //임시 tagID
  //카드 UID는 총 4바이트이다. 10진수로 표현. 1바이트 씩 4번 읽어와야 함
  for(uint8_t i {0u}; i<4; ++i){
    tagID += String(mfrc522.uid.uidByte[i], HEX); //HEX 타입의 문자열로 만듦 A7 ==> 'A7'으로
  }
  tagID.toUpperCase(); //소문자이면 대문자로 모두 바꿔라.
  mfrc522.PICC_HaltA(); //그만 읽겠다.

  if(tagID==MASTER_CARD_UID || tagID==MASTER2_CARD_UID){
    Serial.println(F("카드가 일치합니다."));
    Serial1.println(F("카드가 일치합니다."));
    Serial.println(F("PIN is right"));
    Serial1.println(F("도어락이 열렸습니다."));
    wrong_count=0;
    wrong_value==false;
    for(int i=0; i<=3; ++i){
      tone(BUZZER_PIN, tone_value[i]);
      delay(150UL);
      noTone(BUZZER_PIN);
    }
  }else{
    Serial.println(F("Card is wrong"));
    Serial.println(F("도어락이 열리지 않았습니다."));
    wrong_count++;
    wrong_value=true;
    Serial1.print(F("비밀번호를 "));
    Serial1.print(wrong_count);
    Serial1.println(F("회 틀렸습니다."));
    for(int i=4; i<=5; ++i){
      tone(BUZZER_PIN, tone_value[i] );
      delay(150UL);
    }
    noTone(BUZZER_PIN);
  }
}
