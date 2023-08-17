const uint8_t VR_RED = A0;
const uint8_t VR_GREEN = A1;
const uint8_t VR_BLUE = A2;

enum RGB{
  RED = 10,
  GREEN, //11
  BLUE //12
};
void setup(){
  // put your setup code here, to run once:
  pinMode(VR_RED, INPUT); //굳이 안써도 됨. 기본이 INPUT 모드임.
  pinMode(VR_GREEN, INPUT);
  pinMode(VR_BLUE, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);  
  Serial.begin(115200UL); //115200으로 초기화
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t red_value{analogRead(VR_RED)};
  uint16_t green_value{analogRead(VR_GREEN)};
  uint16_t blue_value{analogRead(VR_BLUE)};
  Serial.print(F("RED Value: "));
  Serial.println(red_value);
  Serial.print(F("GREEN Value: "));
  Serial.println(green_value);
  Serial.print(F("BLUE Value: "));
  Serial.println(blue_value);

  // 0 ~ 1023 -> 0~255 로 바꿔줘야한다
  //이때 map 함수를 사용한다.
  uint8_t mapped_red_value{map(red_value, 0, 1023, 0, 255)};
  uint8_t mapped_green_value{map(green_value, 0, 1023, 0, 255)};
  uint8_t mapped_blue_value{map(blue_value, 0, 1023, 0, 255)};

  analogWrite(RED, mapped_red_value);
  analogWrite(GREEN, mapped_green_value);
  analogWrite(BLUE, mapped_blue_value);
  delay(100UL); //0.1초의 딜레이
}
