#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "Adafruit_BMP280.h"

#define LED_PIN 33
#define LDR_PIN 35

File readings;
Adafruit_BMP280 bmp;

char payload[80];

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(115200);
  bmp.begin(0x76);
  if(!SD.begin()){
    Serial.println("Card Mount Failed"); 
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  sprintf(payload,"%6.2f,%3.2f,%d",bmp.readPressure(),bmp.readTemperature(),analogRead(LDR_PIN));

  digitalWrite(LED_PIN,HIGH);
    readings = SD.open("/lecturas_sensor.csv",FILE_APPEND);
    readings.println(payload);
    readings.close();

    Serial.println(payload);
  digitalWrite(LED_PIN,LOW);

  delay(500);

}
