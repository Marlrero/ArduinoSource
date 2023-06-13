int flag = 0;
const int LED = 9;
float startTime = 0.0;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);      // sets the digital pin as output

  // test 1 ----------------------
  startTime = micros();
  for (int i = 0; i < 10000; i++) {
    if (flag == 0) {
      digitalWrite(LED, HIGH);
      flag = 1;
    } else {
      digitalWrite(LED, LOW);
      flag = 0;
    }
  }
  Serial.println((micros() - startTime) / 10000.0, 2);
/*
  // Test 2 ----------------------
  startTime = micros();
  for (int i = 0; i < 10000; i++) {
    if (flag == 0) {
      digitalWriteDirect(LED, HIGH);
      flag = 1;
    } else {
      digitalWriteDirect(LED, LOW);
      flag = 0;
    }
  }
  Serial.println((micros() - startTime) / 10000.0, 2);
 */
}

void loop() {
}