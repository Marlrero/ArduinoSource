//동시에여러 값 전송하기
//RGBLED 핀 상수 정의
const int RED = 9;     // mega보드에서는 PWM
const int GREEN = 10;   // mega보드에서는 PWM
const int BLUE = 11;    // mega보드에서는 PWM

//RGB값을저장할 정수형 변수 선언
int rval = 0;
int gval = 0;
int bval = 0;

void setup() {
  Serial.begin(9600);  //9600 속도로 시리얼 통신 시작
  //RGB LED가연결된 핀을 출력으로 지정
  pinMode(RED, OUTPUT);
  pinMode(GREEN ,OUTPUT);
  pinMode(BLUE ,OUTPUT);
}

void loop() {
  //수신 데이터가 있을 때만 프로그램 코드 실행
  while(Serial.available() > 0){
    rval = Serial.parseInt();  //첫 번째 정수값 읽음
    gval = Serial.parseInt();  //두 번째 정수값 읽음
    bval = Serial.parseInt();  //세 번째 정수값 읽음
    //전송 완료
    if(Serial.read() == '\n'){ // 255,255,0
      //LED의 RGB값 설정
      analogWrite(RED, rval);
      analogWrite(GREEN,gval);
      analogWrite(BLUE, bval);
    }
  }
}