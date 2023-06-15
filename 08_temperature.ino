//온도경보 장치 프로그램
const int BLED = 9;  // 9번 핀으로 파란색 BLED출력
const int GLED = 10;  // 10번 핀으로 초록색 GLED 출력
const int RLED = 11;  // 11번 핀으로 빨간색 RLED 출력
const int TEMP = 0;  // 아날로그 입력 0번 핀으로 온도 센서 입력
const int LOWER_BOUND = 139;  //온도하한값상수 정의 (약18℃)
const int UPPER_BOUND = 147;  //온도상한값상수 정의 (약22℃)
double val = 0;  // 온도 센서의 현재값을 저장하는 변수선언
double mvolt = 0;
double cel = 0;

void setup(){
  Serial.begin(9600);
  pinMode(BLED, OUTPUT);  //BLED를 출력으로 지정
  pinMode(GLED, OUTPUT);  //GLED를 출력으로 지정
  pinMode(RLED, OUTPUT);  //RLED를 출력으로 지정
}

void loop(){
  val = analogRead(TEMP);
  if (val < LOWER_BOUND) {  // 온도 측정값이 하한값이하
      digitalWrite(RLED, LOW);
      digitalWrite(GLED, LOW);
      digitalWrite(BLED, HIGH);
  } else if (val > UPPER_BOUND) {  // 온도 측정값이 상한값이상
      digitalWrite(RLED, HIGH);
      digitalWrite(GLED, LOW);
      digitalWrite(BLED, LOW);
  } else {  // 온도 측정값이 정상 범위 이내
      digitalWrite(RLED, LOW);
      digitalWrite(GLED, HIGH);
      digitalWrite(BLED, LOW);
  }

   //val=analogRead(TEMP);
   mvolt = val / 1023 * 5000;
//   cel =(mvolt-500)/10 ;   //for tmp36
   cel = mvolt / 10 ;
   Serial.print("val=");
   Serial.print(val);
   Serial.print(" mvolt=");
   Serial.print(mvolt);
   Serial.print(" Cel=");
   Serial.println(cel);
//   delay(500);
}