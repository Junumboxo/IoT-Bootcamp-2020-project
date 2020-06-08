#include "DS18B20.h"

float currentTemp;

void setup() {
  Serial.begin(9600);
  setupDS18B20();
}

void loop() {
  currentTemp = getTemperatureDS18B20();
  Serial.print("Current temperature ");
  Serial.println(currentTemp);
  delay(1000);
}
