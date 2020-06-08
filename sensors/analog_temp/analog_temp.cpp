#include "analog_temp.h"
#include "Arduino.h"

int voltage;
float R1 = 10000;
float logR2, R2, temp;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;

float getTempThermistor(void){
  voltage = analogRead(THERMISTOR_PIN);
  R2 = R1 * (1023.0 / voltage - 1.0);
  logR2 = log(R2);
  temp = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  temp -= 273.15;
  return temp;
}
