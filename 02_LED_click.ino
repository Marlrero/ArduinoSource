const int LED = 9;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
 // digitalWrite(LED, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  for (i = 100; i <= 1000; i += 100) {
    digitalWrite(LED, HIGH);
    delay(i);
    digitalWrite(LED, LOW);
    delay(i);
  }
}