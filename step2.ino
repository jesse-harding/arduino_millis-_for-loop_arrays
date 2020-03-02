//for reference: https://learn.adafruit.com/multi-tasking-the-arduino-part-1/using-millis-for-timing
//NOW LETS USE A MILLIS() TIMER INSTEAD OF A DELAY



//set which pin we want to use to blink our LED
int ledPin = 6;

//declare and initialize our prevMillis variable
//this variable stores the time after each interval passes, so that we can begin a new count
//make note of the datatype we are using here: integer
int prevMillis = 0;

//set the interval (how often in milliseconds our code will run)
int interval = 100;

// create a boolean variable to toggle the led state from on to off and so on
boolean ledState = true;

void setup() {
  //begin our serial connection so that we can observe the millis() clock counting up in the serial monitor
  Serial.begin(9600);
  
  pinMode(6, OUTPUT); //set LED pin to output
}

void loop(){
  if (millis()-prevMillis > interval){ //compare current time against stored time; if the difference is greater than our interval variable, the code within will run
    digitalWrite(ledPin, ledState); //write the ledState to our ledPin
    ledState = !ledState; //toggle the led state between true & false
    prevMillis = millis(); //set stored time to the current time to reset the timer (now the difference between prevMillis and the current time will be less than the interval)
  }
  Serial.println(millis()); //print the number of milliseconds since the program began to the serial connection
}


//after you load this code onto your arduino, note what happens to the LED after about 32 seconds. Afterwards, move to the next step
