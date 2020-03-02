//for reference: https://www.arduino.cc/reference/tr/language/variables/data-types/array/
//LETS LOOK AT ARRAYS & ITERATION

int ledPins[] = {3, 5, 6, 10, 11};
unsigned long prevMillis = 0;
int interval = 100;
boolean ledState = false;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++){
    pinMode(ledPins[i], OUTPUT);
  }  
}

void loop() {
  Serial.println(millis());
  for (int i = 0; i < 5; i++){
  digitalWrite(ledPins[i], HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledPins[i], LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  }
}
