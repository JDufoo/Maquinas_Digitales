#include "Adafruit_BMP280.h"
#include "BluetoothSerial.h"

#define LED_PIN 33
#define LDR_PIN 35

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;
Adafruit_BMP280 bmp;

char payload[80];

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(115200);
  bmp.begin(0x76);
  SerialBT.begin("Axolote_Julio");
  Serial.println("Bluetooth configurado");
}

void loop() {
  // put your main code here, to run repeatedly:
  sprintf(payload,"%6.2f,%3.2f,%d",bmp.readPressure(),bmp.readTemperature(),analogRead(LDR_PIN));

  digitalWrite(LED_PIN,HIGH);
    Serial.println(payload);
    SerialBT.println(payload);
  digitalWrite(LED_PIN,LOW);

  delay(500);

}
