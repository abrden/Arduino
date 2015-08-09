void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  // Blink red LEDs
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  
  delay(250);
}

void loop() {
  
  if (digitalRead(2) == LOW) {
    
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
  } else {
    
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    
    delay(250);
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    delay(250);
  }
  
}
