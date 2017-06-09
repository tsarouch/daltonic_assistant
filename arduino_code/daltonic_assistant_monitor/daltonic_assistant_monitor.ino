
#include "Perceptron.h"
#include "Adafruit_TCS34725.h"
#include <LiquidCrystal.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

uint16_t clear, red, green, blue ;

//we will use one perceptron with 3 inputs (Red, green, blue)
perceptron colorPerceptron(3);//fourth is for bias

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);



bool serial_only_values = true;

// TODO Extension so to evaluate prediction accuracy
//const int prediction_cycles = 200;
//short int prediction_labels[prediction_cycles];
//short int prediction_guesses[prediction_cycles];
//short int prediction_ctr = 0;

void setup() {
  
  //Initialize serial connection (9600 bits per second)
  Serial.begin(9600);
  
  
  //Initializes color sensor
  if (tcs.begin()) {
    //Serial.println("Color sensor found!");
    } 
  else {
    //Serial.println("No TCS34725 found ... check your connections");
    }

  randomSeed(A0);
  colorPerceptron.randomize();//weight initialization

  //To control the LED from the INT pin, tie LED to INT. 
  //Then you can call setInterrupt to turn it on/off. 
  //just give it at least 50ms to stabilize before you take a reading!
  // so no need to connect the led to any arduino pin - just use the INT output of color sensor and connect it to the led output of color sensor


  // Initialize input buttons info
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);

  //Initialize LCD screen
  // set up the LCD's number of columns and rows: 
  lcd.begin(20, 2);
  lcd.print("Hi, I am Socrates!");
  
}

void loop() {

  delay(500);
  lcd.clear();
  lcd.print("Hi, I am Socrates!");
  lcd.setCursor(0, 1);
  lcd.print("...thinking...");
  
  delay(1000);
  
  tcs.setInterrupt(false);
  delay(100); // takes 50ms for a reading
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);
  
  //convert then in values from 0 to 255
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;


  // store in perceptron inputs 
  colorPerceptron.inputs[0] = r;
  colorPerceptron.inputs[1] = g;
  //colorPerceptron.inputs[2] = b; //we do not need blue in daltonic assistant
 //colorPerceptron.inputs[2] = 0;

  
  float guess = colorPerceptron.feedForward();

  if (guess ==1) {
    //Serial.println("I think is RED");
    lcd.setCursor(0, 1);
    lcd.print("I think is RED");
  }
  else{
    //Serial.println("I think is GREEN");
    lcd.setCursor(0, 1);
    lcd.print("I think is GREEN");
  }
  
  // Train RED
  if (digitalRead(12) == 0) {
    //Serial.println("How RED looks like?");
    lcd.setCursor(0, 1);
    lcd.print("How RED looks like?");
    colorPerceptron.train(1, guess);
    
    delay(1000);
    Serial.print("training"); Serial.print(",");  Serial.print(r); Serial.print(","); Serial.print(g); Serial.print(","); Serial.print("r"); 
    Serial.print(","); Serial.print(colorPerceptron.weights[0]); Serial.print(","); Serial.print(colorPerceptron.weights[1]); Serial.print(","); Serial.println(colorPerceptron.weights[3]);
  
    //update the performance
    //prediction_ctr += 1;
    //prediction_labels[prediction_ctr] = 1;
    //prediction_guesses[prediction_ctr] = guess;
    
  }
  else if (digitalRead(11) == 0) {
    //Serial.println("How GREEN looks like?");
    lcd.setCursor(0, 1);
    lcd.print("How GREEN looks like?");
    colorPerceptron.train(-1, guess);
    delay(1000);
    Serial.print("training"); Serial.print(",");  Serial.print(r); Serial.print(","); Serial.print(g); Serial.print(","); Serial.print("g"); 
    Serial.print(","); Serial.print(colorPerceptron.weights[0]); Serial.print(","); Serial.print(colorPerceptron.weights[1]); Serial.print(","); Serial.println(colorPerceptron.weights[3]);

    //update the performance
    //prediction_ctr += 1;
    //prediction_labels[prediction_ctr] = 1;
    //prediction_guesses[prediction_ctr] = guess;

 }
 else{
    Serial.print("reading"); Serial.print(","); Serial.print(r); Serial.print(","); Serial.print(g);  Serial.print(","); Serial.println("b"); 
    }


/*
   //Calculate the prediction efficiency
   int guess_total = 0;
   int label_total = 0;
   float prediction_accuracy = 0;
   for(int i = 0; i <= prediction_ctr; i++)
    {
    guess_total = guess_total + prediction_guesses[i];
    label_total = label_total + prediction_labels[i];
    }
   lcd.setCursor(0, 1);
   lcd.print(guess_total);
 */

}
