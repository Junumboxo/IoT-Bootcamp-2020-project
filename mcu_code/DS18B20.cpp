#include "DS18B20.h"
#include <OneWire.h>
#include <DallasTemperature.h>

OneWire      oneWire(DS18B20_PIN);  
DallasTemperature sensor(&oneWire);

float temp_DS18B20;

void setupDS18B20(){  
  sensor.begin(); 
}

float getTemperatureDS18B20(void){
  sensor.requestTemperatures(); // Send the command to get temperature readings
  temp_DS18B20 = sensor.getTempCByIndex(0);
  return temp_DS18B20;
}
