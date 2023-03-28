#define PIN_LED 33
#define PIN_LDR 35
#define PIN_POT 32
#define PIN_BUTTON 34

bool change = 0;
uint32_t lastMillis = 0;

void IRAM_ATTR isrButtonChange(){
  if(millis() - lastMillis > 10){
      change = 1 - change;
      lastMillis = millis();
  }

}

int pwm_in=0;

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);

  attachInterrupt(PIN_BUTTON, isrButtonChange, RISING);

}

void loop() {
  if(change == 0){
    pwm_in = analogRead(PIN_POT);
  }
  else if(analogRead(PIN_LDR) > 2047){
  pwm_in = 0;
  }
  else{
    pwm_in = 4095 - 2*analogRead(PIN_LDR);
  }
    

  Serial.println(pwm_in);

  analogWrite(PIN_LED, pwm_in/16);

  delay(100);

}
