//수신문자 에코
char data;  //수신문자를 저장하는 문자열 변수 data 선언

void setup() {
  Serial.begin(9600);  //9600 속도로 시리얼 통신 시작
}

void loop() {
  //데이터를 수신할 때만 출력
  if(Serial.available() > 0){
    data=Serial.read();  //수신 문자 저장
    Serial.print(data);  //수신 문자를 시리얼 출력
  }
}