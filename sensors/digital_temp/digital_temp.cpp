#include "digital_temp.h"
#include "Arduino.h"

void setupSensor(){
  pinMode(DIGITAL_DT_PIN, INPUT);
}

int getDigitalValue(void){
  int temp = digitalRead(DIGITAL_DT_PIN);
  return temp;
}

float getAnalogValue(void){
  float temp = analogRead(ANALOG_DT_PIN);
  return temp;
}
