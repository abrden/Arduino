const int swithPin = 2;
const int motorPin = 9;
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
