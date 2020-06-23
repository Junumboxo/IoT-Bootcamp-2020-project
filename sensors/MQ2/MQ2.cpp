#include "MQ2.h"
#include <Arduino.h>

void setupGasSensor() {
  pinMode(GAS_SENSOR_PIN, INPUT);  
}


double getGasSensorValue() {
  int sensorValue = analogRead(GAS_SENSOR_PIN);
  return sensorValue/100 + 0.0;
}
