#include "DHT11.h"
#include "DS18B20.h"
#include "MQ2.h"
#include <LowPower.h>

float currentTemperature, currentHumidity, currentGasValue;
unsigned int minutes = 5, sleepCounter;

//function MCUsleep makes Arduino enter power-save mode for minutes

void MCUsleep(float minutes) {
  int unitsOfSeconds = (minutes * 60) / 8;
  for (sleepCounter = unitsOfSeconds; sleepCounter > 0; sleepCounter--)
  {
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
}

void setup() {
  Serial.begin(9600);
  setupDHT11();
  setupDS18B20();
  setupGasSensor();
}

void loop() {
  //Arduino sleeps for 5 minutes
  MCUsleep(minutes);  
  currentHumidity = getHumidityDHT11();
  while (isnan(currentHumidity)) { //DHT11 sometimes gets tricky and throws us nan values
    currentHumidity = getHumidityDHT11();
  }
  currentTemperature = getTemperatureDS18B20();
  currentGasValue = getGasSensorValue();
  Serial.println(currentHumidity);
  Serial.println(currentTemperature);
  Serial.println(currentGasValue);
  delay(2000);
}
