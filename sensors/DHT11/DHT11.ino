#include "DHT11.h"

float currentTemp;
float currentHum;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setupDHT11();
}

void loop() {
  currentTemp = getTemperatureDHT11();
  currentHum = getHumidityDHT11();
  Serial.print("Current temperature - ");
  Serial.println(currentTemp);
  Serial.print("Current humidity - ");
  Serial.println(currentHum);
  delay(1000);  
}
