

/*
 * Assembly and Wiring:
 The color sensor TCS34725 communicate via a 2-wire I2C interface. 
 To connect to the processor, you need a total of just 4 wires.
 Connect jumpers:
 Arduino -> TCS34725
 5v -> VIN  
 GND -> GND  
 SDA -> SDA  
 SCL -> SCL  

 concerning Arduino see info here: https://www.arduino.cc/en/reference/wire
 Uno, Ethernet: 
 A4 (SDA)
 A5 (SCL)


 * Libraries
 Navigate to: 
 /Users/charilaostsarouchas/Documents/Arduino/libraries
 And copy the relevant lib folder:
 adafruit-Adafruit_TCS34725-12be4c6
 (from https://github.com/adafruit/Adafruit_TCS34725)

 * Test the Sensor
 Run the TCS34725 test sketch to verify that your sensor is working properly

 
 * Validate results
 Just check in the Serial Monitor to see if the RGB numbers make sense.
 e.g. take 2 crayons Red and Blue and check that the value corresponding to red is the bigger one.
 The same with blue etc.
 */



#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

uint16_t clear, red, green, blue ;

void setup() {
  
  //Initializes serial connection (9600 bits per second)
  Serial.begin(9600);
  tcs.begin();
  if (tcs.begin()) {
    Serial.println("Color sensor found!");
    } 
  else {
    Serial.println("No TCS34725 found ... check your connections");
    }
}


void loop() {
  
  //Read seonsor values 
  tcs.setInterrupt(false);
  delay(1000);
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);
  
  //convert values in range [0, 255]
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  // Print in Serial Monitor
  Serial.print("R,G,B :"); Serial.print(r);  Serial.print(", ");  Serial.print(g); Serial.print(","); Serial.print(b); Serial.println(","); 
  Serial.println("--");

  // For data generation...
  //Serial.print(r);  Serial.print(", ");  Serial.print(g); Serial.print(","); Serial.print(b); Serial.println(","); 
  

}



