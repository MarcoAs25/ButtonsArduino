#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

class Buttons{
private:
  int buttonPressed;
  int lastPressed;
public:
  static const short NOTPRESSED = 0;
  static const short UP = 1;
  static const short DOWN = 2;
  static const short RIGHT = 3;
  static const short LEFT = 4;
  static const short SELECT = 5;
  Buttons();
  int getButtonPressed();
  bool newInput();
  void setButtonPressed(int buttonPressed);
  void readButtons(int pin);
  void setLastPressed(int LastPressed);
  void clear();

};

#endif // BUTTONS_H
