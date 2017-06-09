

/* Just a quick test that arduino is properly connected and loaded

 Hardware:
 Connect a LED directly in the digital ports 13 and port GND of hte arduino UNO board

 Software:
 1. Configure  
    a) Tools > Board  
    b) Tools > Port
 2. Try to verify that the code is ok
 3. Try to Upload the code. 

 If the lamp blinks with 5sec intervals means that the Arduino setup is ok 
 Ready to inject some neurons to it!
*/

int led_pin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(led_pin, HIGH);
  delay(5000);
  digitalWrite(led_pin, LOW);
  delay(5000);
  
}
