#include "MQ2.h"

void setup() {
  Serial.begin(9600);
  setupGasSensor();
   
}

void loop() {
  float value =  getGasSensorValue();
  Serial.println(value);
  delay(1000);
  
}
