#include "Adafruit_BMP280.h"

Adafruit_BMP280 bmp;

char payload [80];

void setup() {
  // put your setup code here, to run once:
  bmp.begin(0x76);
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  sprintf(payload,"%6.2f,%3.2f",bmp.readPressure(),bmp.readTemperature());

  Serial.println(payload);
  
  delay(200);

}
