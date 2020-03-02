//LETS START WITH A BLINK SKETCH USING DELAY()

//set which pin we want to use to blink our LED
int ledPin = 6;

void setup() {
  pinMode(ledPin, OUTPUT); //set LED pin to output
}

void loop(){
  digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a tenth of a second
  digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a tenth of a second
}
