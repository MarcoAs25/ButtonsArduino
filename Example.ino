#include <LiquidCrystal.h>
#include "Buttons.h"

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
Buttons buttons;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  clearAndPrint();
}

void clearAndPrint(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("     Buttons     ");
  lcd.setCursor(0,1);
}
void loop() {
  buttons.readButtons(0);
  int btn = buttons.getButtonPressed();
  
  if(buttons.newInput()){
    clearAndPrint();
    if(btn == buttons.UP){
      lcd.print("UP PRESSED");
    }else if(btn == buttons.DOWN){
      lcd.print("DOWN PRESSED");
    }else if(btn == buttons.RIGHT){
      lcd.print("RIGHT PRESSED");
    }else if(btn == buttons.LEFT){
      lcd.print("LEFT PRESSED");
    }else if(btn == buttons.SELECT){
      lcd.print("SELECT PRESSED");
    }
  }
  
  buttons.clear();
  buttons.setLastPressed(btn);
  delay(50);
}
