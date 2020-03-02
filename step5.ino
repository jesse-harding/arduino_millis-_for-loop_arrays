//LETS USE A MILLIS() TIMER WITH MORE THAN ONE LED

int ledPins[] = {3, 5, 6, 10, 11}; //an array can be thought of as a list. Instead of having multiple variables. I can store multiple values inside of one variable and reference that value's position in the list. Note that the first element in the array is at position zero.
unsigned long prevMillis = 0; 
int interval = 100;
boolean ledState = false;
int currentLED = 0; //declare and initialize a variable to determine which LED is currently illuminated

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++){ //see explanation of for loops in step4.ino in this repo
    pinMode(ledPins[i], OUTPUT);
  }  
}

void loop() {
    if (currentLED > 4){ //this conditional statment will reset the value of the currentLED variable to 0 if it ever goes beyond 4. We will be cycling from 0 to 4 to select elements from our array of pins connected to LEDs
      currentLED = 0; //reset the value to zero
    }
    if (millis()-prevMillis > interval){ //millis() timer to repeat after the value of interval in milliseconds
      digitalWrite(ledPins[currentLED], ledState); //select one of the LEDs in our array based on the value of the currentLED variable and turn it on or off with a toggled boolean variable
            Serial.println(currentLED); //print the current LED address to serial 
      prevMillis = millis(); //reset timer
      if (ledState == false){ //if the current LED has been turned off, now we can move on to the next LED in the array
        currentLED++;
      }
      ledState = !ledState; //toggle the boolean variable so that on the next loop, the next LED will be turned on
    }
}
