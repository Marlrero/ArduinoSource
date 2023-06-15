const int LED = 9;
char data;  //수신문자를 저장하는 문자열 변수 data 선언

void setup() {
  Serial.begin(9600);  //9600 속도로 시리얼 통신 시작
  pinMode(LED,OUTPUT);
}

void loop() {
  if(Serial.available()>0){  //데이터를 수신할 때만 작동
    data=Serial.read();
    if(data=='1') {  //1을 수신하면 LED켜기
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    } else if(data=='0'){  //0을 수신하면 LED끄기
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
  }
}