const int LED = 9; //PWM

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
 // digitalWrite(LED, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for (i = 0; i < 256; i++) {
    analogWrite(LED, i);
    delay(10);
  }
  for (i = 255; i >- 0; i--) {
    analogWrite(LED, i);
    delay(10);
  }
}