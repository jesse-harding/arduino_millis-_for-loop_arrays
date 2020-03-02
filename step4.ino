//for reference: https://www.arduino.cc/reference/tr/language/variables/data-types/array/ & https://www.arduino.cc/reference/en/language/structure/control-structure/for/
//LETS LOOK AT ARRAYS & ITERATION

int ledPins[] = {3, 5, 6, 10, 11}; //an array can be thought of as a list. Instead of having multiple variables. I can store multiple values inside of one variable and reference that value's position in the list. Note that the first element in the array is at position zero.

void setup() {
  for (int i = 0; i < 5; i++){ //for loops will run a chunk of code repeatedly. In this for loop, i is initialized at zero, is incremented each time the code runs, until the condition is no longer satisfied. So, this code will run 5 times where the value of i will go from 0 to 4. After that point, the setup function will be finished and the loop function will begin running.
    pinMode(ledPins[i], OUTPUT); //set led pins to output. note that the value of ledPins[0] is 3, the value of ledPins[1] is 5, the value of ledPins[2] is 6, the value of ledPins[3] is 10, and the value of ledPins[4] is 11. If you try to use ledPins[5], you will get an error, because there is not a 6th element in the array.
  }  
}

void loop() {
  for (int i = 0; i < 5; i++){  //see the comment at the previous for loop
  digitalWrite(ledPins[i], HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                       // wait for a second
  digitalWrite(ledPins[i], LOW);    // turn the LED off by making the voltage LOW
  delay(100);                       // wait for a second
  }
}
