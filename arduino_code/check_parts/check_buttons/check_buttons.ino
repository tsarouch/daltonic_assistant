

/* Check Button functionality 
 *  
 *  We use 2 buttons and 1 LED. 
 *  The first button switches on the LED
 *  The second button switches off the LED.
 *  
 *  Wiring
 *  LED in digital 4
 *  button 1 in digital 3
 *  button 2 in digital 2
 *  
 *  Notice:
 *  We need to add pull up resistors in the buttons positive leg 
 *  to reliable read the pin as HIGH.
 * 
 */


int ledPin = 4;
int inputPin1 = 3;
int inputPin2 = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(inputPin1) == LOW)
    {
    digitalWrite(ledPin, LOW);  
    }
  else if  (digitalRead(inputPin2) == LOW)
    {
    digitalWrite(ledPin, HIGH);    
    }
}
