#include <Wire.h>
#include "SparkFunMPL3115A2.h"

//Create an instance of the object
MPL3115A2 myPressure;

float millisecondsStart = 0;
float altitude = 0;
float pressure = 0;

void setup()
{
  Wire.begin();        // Join i2c bus
  Serial.begin(9600);  // Start serial for output

  myPressure.begin(); // Get sensor online

  //Configure the sensor
  myPressure.setModeAltimeter(); // Measure altitude above sea level in meters
  //myPressure.setModeBarometer(); // Measure pressure in Pascals from 20 to 110 kPa

  myPressure.setOversampleRate(4); // Set oversample rate to 2^(4) = 16  ->  66 ms update rate on sensor (data sheet page 31)
  myPressure.enableEventFlags(); // Enable all three pressure and temp event flags


  Serial.print("Time (ms),Altitude (Ft)"); // ,Pressure (Pa)");
  Serial.println();
}



void loop()
{
  millisecondsStart = millis();
  altitude = myPressure.readAltitudeFt();
//  pressure = myPressure.readPressure();

  Serial.print(millisecondsStart);
  Serial.print(",");
  Serial.print(altitude, 2);
//  Serial.print(",");
//  Serial.print(pressure, 2);
  //  Serial.print(",");
  //  Serial.print(millisecondsEnd - millisecondsStart);
  Serial.println();
  delay(2);
}
