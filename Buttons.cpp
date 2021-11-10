#include "Buttons.h"

Buttons::Buttons(){
  buttonPressed = 0;
}
  
int Buttons::getButtonPressed(){
  return buttonPressed;
}

void Buttons::setButtonPressed(int buttonPressed){
  this->buttonPressed = buttonPressed;
}
void Buttons::clear(){
  this->buttonPressed = NOTPRESSED;
}
void Buttons::setLastPressed(int buttonPressed){
  this->lastPressed = buttonPressed;
}
bool Buttons::newInput(){
  return (lastPressed != buttonPressed) && (buttonPressed != NOTPRESSED);
}
void Buttons::readButtons(int pin){
  int x = analogRead (pin);
  buttonPressed = 0;
  if (x < 100) {
    //right
    buttonPressed = 3;
  } else if (x < 200) {
    //Up
    buttonPressed = 1;
  } else if (x < 400){
    //Down
    buttonPressed = 2;
  } else if (x < 600){
    //left
    buttonPressed = 4;
  } else if (x < 800){
    //say
    buttonPressed = 5;
  }
}
