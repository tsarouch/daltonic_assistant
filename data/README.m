# rgb.csv

The rgb.csv file contains data generated from the color sensor TCS34725, in an Arduino setup which writes to Serial Monitor the output of the sensor values converted in range [0, 255]

Conversion code snippet below:
```
  //convert values in range [0, 255]
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
```

There are two color inputs: Green and Red (color markers used).
There is also the output of the color sensor where there is no any color marker placed on top of the sensor (so we have white color measurements too).


