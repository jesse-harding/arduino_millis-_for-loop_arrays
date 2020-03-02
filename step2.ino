//NOW LETS USE A MILLIS() TIMER INSTEAD OF A DELAY
//https://learn.adafruit.com/multi-tasking-the-arduino-part-1/using-millis-for-timing

int ledPin = 6;
int prevMillis = 0;
int interval = 100;
boolean ledState = false;

void setup() {
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop(){
  if (millis()-prevMillis > interval){
    digitalWrite(ledPin, ledState);
    ledState = !ledState;
    prevMillis = millis();
  }
  Serial.println(millis());
}
