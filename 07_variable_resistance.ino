const int POT = 0; // analog pin 0 (가변저항 입력)
int val = 0; // 가변저항 값 저장

void setup() {
  Serial.begin(9600); // 시리얼 통신 속도 Baud Ratse 값
}

void loop() {
  val = analogRead(POT);
  Serial.println(val);
  delay(500); // 0.5 sec delay
}
