#include "DHT11.h"
#include "DS18B20.h"
#include "analog_temp.h"

float currentTempDHT11, currentTempDS18B20, currentTempThermistor;

void setup() {
  Serial.begin(9600);
  setupDHT11();
  setupDS18B20();
}

void loop() {
  currentTempDHT11 = getTemperatureDHT11();
  currentTempDS18B20 = getTemperatureDS18B20();
  //currentTempThermistor = getTempThermistor();
  Serial.print("Current temperature on DHT11 - ");
  Serial.println(currentTempDHT11);
  Serial.print("Current temperature on DS18B20 - ");
  Serial.println(currentTempDS18B20);
  //Serial.print("Current temperature on Analog Temp Module (Thermisor) - ");
  //Serial.println(currentTempThermistor);
  Serial.println(".......");
  delay(1500);
}
