#include "mbed.h"
using namespace mbed;

DigitalInOut ultrasonicSelect(P1_14);
Timer sonar;

int ultrasonicCorrection() {
  sonar.reset();
  sonar.start();
  ultrasonicSelect.input();
  while (ultrasonicSelect.read() == 2) {};
  sonar.stop();
  return sonar.read_us();
}

int ultrasonic(int sensor) {
  int distance = 0;
  //left
  if (sensor == 0) {
    ultrasonicSelect = P1_14;
  }
  //right
  if (sensor == 1) {
    ultrasonicSelect = P1_15;
  }
  sonar.reset();
  //send ping
  ultrasonicSelect.output();
  ultrasonicSelect = 1;
  //wait for set pulse width
  wait_us(10);
  //stop ping
  ultrasonicSelect = 0;
  //wait for echo high
  ultrasonicSelect.input();
  while (ultrasonicSelect.read() == 0) {};
  //start timer
  sonar.start();
  //wait for echo low
  while (ultrasonicSelect.read() == 1) {};
  //stop timer
  sonar.stop();
  //read timer and convert and correct
  distance = (sonar.read_us() - ultrasonicOffset) / 58;
  wait_us(500000);
  return distance;
}