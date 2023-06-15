//자동야간 조명 프로그램
const int RLED = 9;  // 9번 핀으로 빨간색 RLED 출력
const int LIGHT = 0;  // 아날로그 입력 0번 핀으로 포토레지스터 입력
const int MIN_LIGHT = 200;  //최저 조도값 200(상수)
const int MAX_LIGHT = 900;  //최대 조도값 900(상수)
int val = 0;  //포토레지스터가 읽은 현재 조도값을 저장하는 변수

void setup() {
  Serial.begin(9600);
  pinMode(RLED,OUTPUT);  //RLED 핀을 출력으로 지정
}

void loop() {
  val = analogRead(LIGHT);  //포토레지스터에서 현재 조도값 읽음
  Serial.print(val); Serial.print(" ");
  val = map(val, MIN_LIGHT, MAX_LIGHT, 255, 0);  // 8비트 값으로 매핑
  Serial.print(val); Serial.print(" ");
  
  int per = map(val, 0, 1023, 0, 100);  //가변 저항 값을 백분율(%)로 변환
  Serial.print("Percentage:");
  Serial.print(per);  //백분율(%)로 변환된 값 출력
  Serial.print("%");  //'%' 기호 출력, 줄바꿈
  
  val = constrain(val, 0, 255);  //매핑된 조도 값을 0 - 255 사이의 값으로 제한
  Serial.println(val);
  
  analogWrite(RLED, val);  //조도 값에 따라 LED 밝기를 조정
}