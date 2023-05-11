#include <Adafruit_TCS34725softi2c.h>

#include <Wire.h>




// You can use any digital pin for emulate SDA / SCL
#define SDApin 47
#define SCLpin 49

#define SDApinD 51
#define SCLpinD 53


Adafruit_TCS34725softi2c tcs = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, SDApin, SCLpin);

Adafruit_TCS34725softi2c tcsD = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, SDApinD, SCLpinD);
void setup() {
  Serial.begin(9600);
  Serial.println("Color View Test!");
  if (!tcs.begin()) {Serial.println("CAVALU");}
  if (!tcsD.begin()) {Serial.println("CAVALUD");}
  Wire.begin();
}


void loop() {
  uint16_t clear;
  uint16_t r, g, b;
  uint16_t rD, gD, bD;
  
  tcs.getRawData(&r, &g, &b, &clear);
  tcsD.getRawData(&rD, &gD, &bD, &clear);


Serial.print(r+g+b); Serial.print(" "); Serial.println(rD+gD+bD);

  
}
