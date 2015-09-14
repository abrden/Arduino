const int switchPin = 2;
const int motorPin = 8;
int switchState = LOW;

void setup() {
  
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
  
}

void loop() {
  
  switchState = digitalRead(switchPin);
  
  if (switchState == HIGH) {
    
    digitalWrite(motorPin, HIGH);
    
  } else {
    
    digitalWrite(motorPin, LOW);
    
  }

}
