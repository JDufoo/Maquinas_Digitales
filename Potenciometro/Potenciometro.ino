#define PIN_LED 33
#define PIN_POT 32
#define UMB_POT 2050

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_POT,INPUT);
  pinMode(PIN_LED,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int pot_signal = analogRead(PIN_POT);

  Serial.println(pot_signal);

  if(pot_signal>UMB_POT){
    digitalWrite(PIN_LED,HIGH);
  }
  else{
    digitalWrite(PIN_LED,LOW);
  }

  delay(50);
}
