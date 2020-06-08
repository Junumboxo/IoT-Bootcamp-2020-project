#include "analog_temp.h"

float currentTemp;

void setup() {
  Serial.begin(9600);
}

void loop() {
  currentTemp = getTempThermistor();
  Serial.print("Current temperature ");
  Serial.println(currentTemp);
  delay(1000);
}
