#include "DHT11.h"
#include "DS18B20.h"
#include "analog_temp.h"
#include <LowPower.h>

float currentTemperature, currentHumidity;
unsigned int dayHours = 4, nightHours = 16, counterDayNight = 0;
unsigned int sleepCounter;

//function MCUsleep makes Arduino sleep for hours, however, this needs to be tuned periodically as it takes time for Arduino
//to wake up too + delay(2000) for avoiding conflicts with DHT11 sensor

void MCUsleep(float hours) {
  int unitsOfSeconds = (hours * 60 * 60) / 8;
  for (sleepCounter = unitsOfSeconds; sleepCounter > 0; sleepCounter--)
  {
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  }
}

void setup() {
  Serial.begin(9600);
  setupDHT11();
  setupDS18B20();
}

void loop() {
  //turn on Arduino at 10AM
  if (counterDayNight == 2) {
    MCUsleep(nightHours);
    counterDayNight = 0;
  }
  else {
    counterDayNight++;
    MCUsleep(dayHours);
  }
  
  currentHumidity = getHumidityDHT11();
  while (isnan(currentHumidity)) { //DHT11 sometimes gets tricky and throws us nan values
    currentHumidity = getHumidityDHT11();
  }
  currentTemperature = getTemperatureDS18B20();
  Serial.println(currentHumidity);
  Serial.println(currentTemperature);
  delay(2000);
}
