#ifndef DIGITAL_TEMP_H_
#define DIGITAL_TEMP_H_

#define ANALOG_DT_PIN A0
#define DIGITAL_DT_PIN 7

void setupSensor();
int getDigitalValue(void);
float getAnalogValue(void);

#endif
