/*
 Input Pullup Serial

 This example demonstrates the use of pinMode(INPUT_PULLUP). It reads a
 digital input on pin 2 and prints the results to the serial monitor.

 The circuit:
 * Momentary switch attached from pin 2 to ground
 * Built-in LED on pin 13

 Unlike pinMode(INPUT), there is no pull-down resistor necessary. An internal
 20K-ohm resistor is pulled to 5V. This configuration causes the input to
 read HIGH when the switch is open, and LOW when it is closed.

 created 14 March 2012
 by Scott Fitzgerald

 http://www.arduino.cc/en/Tutorial/InputPullupSerial

 This example code is in the public domain

 */
 

void setup() {
  
  // put your setup code here, to run once:
  //start serial connection
  Serial.begin(9600);
  
  //configure pin2 as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);

  pinMode(13, OUTPUT);
}

void loop() {
    delay(5000);
   // read the button sensor val (1 means we do not push it)
   int sensorVal = digitalRead(2);

    while(digitalRead(2) == HIGH) { 
      //Serial.println("Inside while loop... waiting for someone to press the button :-) ");
      } 

   Serial.println("Oh button pressed, now we can move on... ");

}
