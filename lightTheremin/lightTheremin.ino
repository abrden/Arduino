int noteDuration = 20;

int piezoPin = 8;

int sensorPin = A0;
int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

// Arduino UNO integrated led's pin
const int ledPin = 13;

void setup() {
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
  // Calibration
  while (millis() < 5000) {
    
    sensorValue = analogRead(sensorPin);
    
    if (sensorValue > sensorHigh) {
      
      sensorHigh = sensorValue;
      
    }
    
    if (sensorValue < sensorLow) {
      
      sensorLow = sensorValue;
      
    }
  
  }
  
  digitalWrite(ledPin, LOW);

}

void loop() {
  
  sensorValue = analogRead(sensorPin);
  
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  
  tone(piezoPin, pitch, noteDuration);
  
  delay(10);
  
}

