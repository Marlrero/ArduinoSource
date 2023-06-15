const int BLED = 9;    //Blue LED on Pin 9 (or Red LED)
const int GLED = 10;   //Green LED on Pin 10
const int RLED = 11;   //Red LED on Pin 11 (or Blue LED)
const int BUTTON = 2;    //The Button isconnected to pin 2
boolean lastButton = LOW;    //Last Button State
boolean currentButton = LOW; //Current Button State
int ledMode = 0;             //Cycle between LEDstates

void setup() {
  pinMode(BLED, OUTPUT);   //Set Blue LED as Output
  pinMode(GLED, OUTPUT);   //Set Green LED as Output
  pinMode(RLED, OUTPUT);   //Set Red LED as Output
  pinMode(BUTTON, INPUT);  //Set button as input (not required)
}

/*Debouncing Function */
boolean debounce(boolean last) {
  boolean current = digitalRead(BUTTON);       //Read the button state
  if (last != current) { //if it's different...
    delay(5);  //wait5ms
    current = digitalRead(BUTTON);  //read it again
  }
  return current;                              //return the current value
}

/* LED Mode Selection */
void setMode(int mode) {
  if (mode == 1)  {  // RED (or BLUE)
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  } else if (mode == 2) {  // GREEN
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  } else if (mode == 3) {  // BLUE (or RED)
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  } else if (mode == 4) {  //PURPLE (RED+BLUE)
    analogWrite(RLED, 127); // 9, 10, 11은 ~ 모양 (analog 가능)
    analogWrite(GLED, 0);
    analogWrite(BLED, 127);
  } else if (mode == 5) {  //TEAL (BLUE+GREEN or RED+GREEN)
    analogWrite(RLED, 0);
    analogWrite(GLED, 127);
    analogWrite(BLED, 127);
  } //  …mode 6,7 생략
  else {    //OFF (mode = 0)
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
}

void loop(){
  currentButton = debounce(lastButton);           //read debouncedstate
  if (lastButton == LOW && currentButton == HIGH){ //if it was pressed...
    ledMode++;  //increment the LED value
  }
  lastButton = currentButton;  //reset button value
  //if you’ve cycled through thedifferent options, reset the counter to 0
  if (ledMode ==  8) 
    ledMode = 0;
  setMode(ledMode);  //change the LED state
}