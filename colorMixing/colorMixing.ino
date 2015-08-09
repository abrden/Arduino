const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int greenSensorPin = A2;
const int redSensorPin = A0;
const int blueSensorPin = A1;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(4800);
  
  pinMode(greenLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  
  // Arduino already knows the sensor pins are inputs
  
}

void loop() {
  
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);
  
  // Sensor reads from 0 to 1023
  // analogWrite receives an integer (from 0 to 255)
  // 1023 ______ 255
  // sensorValue _____ colorValue
  redValue = (redSensorValue * 255) / 1023;
  greenValue = (greenSensorValue * 255) / 1023;
  blueValue = (blueSensorValue * 255) / 1023;
  
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);
  
  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
  
}
