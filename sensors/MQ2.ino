#include "MQ2.h"

void setup() {
  Serial.begin(9600);
  InitGasSensor();
   
}

void loop() {
  float value =  GetGasSensorValue();
  Serial.println(value);
  delay(1000);
  
}
