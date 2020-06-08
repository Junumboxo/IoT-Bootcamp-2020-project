#include "DS18B20.h"
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire      oneWire(DS18B20_PIN);  
DallasTemperature sensor(&oneWire);

float temp;

void setupDS18B20(){  
  sensor.begin(); 
}

float getTemperatureDS18B20(void){
  sensor.requestTemperatures(); // Send the command to get temperature readings
  temp = sensor.getTempCByIndex(0);
  return temp;
}
