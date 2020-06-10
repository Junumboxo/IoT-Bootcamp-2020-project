#include <DHT.h>
#include <DHT_U.h>
#include "DHT11.h"

DHT dht(DHT11_PIN, DHT11);

void setupDHT11(){
  dht.begin();
}

float getTemperatureDHT11(void){
  float temp = dht.readTemperature();
  return temp;
}

float getHumidityDHT11(void){
  float hum = dht.readHumidity();
  return hum;
}
