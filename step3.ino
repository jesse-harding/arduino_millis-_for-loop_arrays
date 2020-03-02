//for reference: https://www.arduino.cc/en/Reference.Int & https://www.arduino.cc/reference/en/language/variables/data-types/unsignedlong/
//LETS CHANGE THAT "int" TO AN "unsigned long" DATATYPE on line 12
//unsigned long variables can range from 0 to 4,294,967,295 whereas -32,768 to 32,767
//now the timer will be able to run for days, as opposed to seconds without running out of room as we continue to update the value of prevMillis to the current time (in milliseconds from the start of the program)



//set which pin we want to use to blink our LED
int ledPin = 6;

//declare and initialize our prevMillis variable
//this variable stores the time after each interval passes, so that we can begin a new count
unsigned long prevMillis = 0;

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
