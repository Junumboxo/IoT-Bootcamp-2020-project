#include "MQ2.h"
#include <Arduino.h>

int sensorBool;

void setupGasSensor() {
  pinMode(GAS_SENSOR_PIN, INPUT);  
}


double getGasSensorValue(void) {
  int sensorValue = analogRead(GAS_SENSOR_PIN);
  if (sensorValue > 400) {
    sensorBool = 1;  
  }
  else {
    sensorBool = 0;
  }
  return sensorBool;
}
