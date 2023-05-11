#include <Adafruit_TCS34725softi2c.h>

#include <Wire.h>




// You can use any digital pin for emulate SDA / SCL
#define SDApin 47
#define SCLpin 49

#define SDApinD 51
#define SCLpinD 53


Adafruit_TCS34725softi2c tcs = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, SDApin, SCLpin);
Adafruit_TCS34725softi2c tcsD = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, SDApinD, SCLpinD);

  uint16_t clear;
  uint16_t lR, lG, lB;
  uint16_t rR, rG, rB;

void setup() {
  Serial.begin(9600);
  Serial.println("Color View Test!");
  if (!tcs.begin()) {Serial.println("CAVALU");}
  if (!tcsD.begin()) {Serial.println("CAVALUD");}
  Wire.begin();
}


void loop() {
//  Serial.print(lG); Serial.print(" ");
//  Serial.print(lR); Serial.print(" | ");
//  Serial.println(CR7());
  CR7();
}


long CR7()
{
  tcs.getRawData(&lR, &lG, &lB, &clear);
  Serial.print(lB); Serial.print(" ");
  lB += lR;
  Serial.print(lB); Serial.print(" ");
  lB /= 2;
  Serial.println(lB);
  return lG - lB;
}

