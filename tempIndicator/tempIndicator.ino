const int sensorPin = A0;
const float baselineTemp = 19.0;

void setup() {
  Serial.begin(9600);
  
  for (int pinNumber = 2; pinNumber <= 4; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);
  
  // TMP36 reads from 0 to 1023
  // 1023 _________ 5 V
  // senorVal _____ voltage
  
  // Maping
  float voltage = (sensorVal/1023.0) * 5.0;
  
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  // TMP36 datasheet says 10 mV equals 1 C
  // 0.01 _________ 1 C
  // voltage _____ temperature
  
  // Maping
  float temperature = (voltage - 0.5) * 100;
  
  Serial.print(", Degrees [C]: ");
  Serial.println(temperature);
  
  if (temperature >= baselineTemp && temperature < baselineTemp + 2) {
    
    for (int pinNumber = 2; pinNumber <= 4; pinNumber++) {
        digitalWrite(pinNumber, LOW);
    }
    
  } else if (temperature >= baselineTemp + 2 && temperature < baselineTemp + 4) {
    
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    
  } else if (temperature >= baselineTemp + 4 && temperature < baselineTemp + 6) {
    
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    
  } else if (temperature >= baselineTemp + 6) {
        for (int pinNumber = 2; pinNumber <= 4; pinNumber++) {
        digitalWrite(pinNumber, HIGH);
    }
    
  }
  
  delay(1);
  
}

