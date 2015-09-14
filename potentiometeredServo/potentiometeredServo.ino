#include <Servo.h>

Servo servo;
const int servoPin = 9;

const int potentiometerPin = A0;
int potentiometerValue;
int angle;

void setup() {
  
  servo.attach(servoPin);
  
  // Serial connection to check values from the potentiometer
  Serial.begin(9600);

}

void loop() {

  potentiometerValue = analogRead(potentiometerPin);
  
  Serial.print("potentiometer: ");
  Serial.print(potentiometerValue);
  
  // Change value between 0-1023 to value between 0-179
  angle = map(potentiometerValue, 0, 1023, 0, 179);
  
  Serial.print(", angle: ");
  Serial.println(angle);
  
  servo.write(angle);
  delay(15);
  
}

