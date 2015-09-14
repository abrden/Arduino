const int switchPin = 8;

unsigned long previousTime = 0;

int switchState = 0;
int prevSwitchState = 0;

int nextLEDsPin = 2;

long interval = 3600;

int operation[] = {1, -1};

void setup() {
  
  Serial.begin(2400);
  
  for (int i = 2; i < 8; i++) {
    
    pinMode(i, OUTPUT);
    
  }
  
  pinMode(switchPin, INPUT);
  
}

void lightNextLED(int currentTime) {
  
  previousTime = currentTime;

  digitalWrite(nextLEDsPin, HIGH);
  nextLEDsPin = nextLEDsPin + operation[switchState];
  
}

void hourFinished() {
  
  // Do something!
  
}

void resetHourglass(int currentTime) {

  for (int i = 2; i < 8; i++) {
      
    digitalWrite(i, LOW);
    
  }
    
  if (nextLEDsPin == 2) nextLEDsPin = 2;
  else nextLEDsPin = 7;
  
  previousTime = currentTime;
  
}

void loop() {
  
  Serial.println(digitalRead(switchPin));
  
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime > interval) {
    
    lightNextLED(currentTime);
    
    if (switchState == 1 && nextLEDsPin == 7 || switchState == 0 && nextLEDsPin == 2) {
    
      hourFinished();
      
    }
    
  }
  
  switchState = digitalRead(switchPin);
  
  if (switchState != prevSwitchState) {
    
    resetHourglass(currentTime);
    
  }
  
  prevSwitchState = switchState;
  
}
