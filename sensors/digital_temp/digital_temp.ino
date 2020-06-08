#include "digital_temp.h"
float d_value;
float a_value;

void setup() {
  Serial.begin(9600);
  setupSensor();
}

void loop() {
  d_value = getDigitalValue();
  a_value = getAnalogValue();
  Serial.print("Digital Value - ");
  Serial.println(d_value);
  Serial.print("Analog Value - ");
  Serial.println(a_value);
  delay(1000);
}
