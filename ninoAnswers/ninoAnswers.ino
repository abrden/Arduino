#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Setting lcd pins

const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int answerNum;

void setup() {
  
  lcd.begin(16, 2);
  pinMode(switchPin, INPUT);
  
  lcd.print("Hi! I'm Nino");

  lcd.setCursor(0, 1);
  lcd.print("Ask me anything");
  
  Serial.begin(9600);
}

String answers[] = {"Yes", "Most likely", "Certainly", "Outlook good", "Unsure", "Ask again", "Doubtful", "No"};

void loop() {
  
  switchState = digitalRead(switchPin);
  
  Serial.print(switchState);
  
  if (switchState != prevSwitchState) {
    
    if (switchState == LOW) {
      answerNum = random(8);
      
      //Make clear function
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Mmm...");
      lcd.setCursor(0, 1);
      
      lcd.print(answers[answerNum]);
      
    }
    
  }
  
  prevSwitchState = switchState;
  
}


