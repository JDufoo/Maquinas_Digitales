#define LED_PIN 33

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED_PIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_PIN, HIGH);  
  delay(1000);                      
  digitalWrite(LED_PIN, LOW);   
  delay(1000);                      
}