#include <DHT.h>
#include <DHT_U.h>
#include "DHT11.h"

DHT dht(DHT11_PIN, DHT11);

void setupDHT11(){
  dht.begin();
}

float getTemperatureDHT11(void){
  float temp_DHT = dht.readTemperature();
  return temp_DHT;
}

float getHumidityDHT11(void){
  float hum_DHT = dht.readHumidity();
  return hum_DHT;
}
