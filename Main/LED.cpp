#include "Arduino.h"
#include "LED.h"

#include "mbed.h"
using namespace mbed;

LED::LED(PinName redPin, PinName greenPin, PinName bluePin): _redLed(redPin), _greenLed(greenPin), _blueLed(bluePin)
{
}

void LED::state(bool R, bool G, bool B){
  _redLed = R;
  _greenLed = G;
  _blueLed = B;
}
