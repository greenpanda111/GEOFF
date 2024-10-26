#include "mbed.h"
#include "Arduino.h"
#include "MotorClass.h"
#include "MotorController.h"
#include "LED.h"

using namespace mbed;

#define STD_DELAY 500000

Motor leftMotor(Left_Motor_PWM, Left_Motor_Direction);
Motor rightMotor(Right_Motor_PWM, Right_Motor_Direction);

MotorController motorControl(leftMotor, rightMotor);

LED led(GPIO_PIN_2, GPIO_PIN_3, GPIO_PIN_4);

int ultrasonicOffset = 0;

void sensorsOutput() {
  int IrOutputList[4] = { 0, 0, 0, 0 };
  IrOutputList[0] = IR(0);
  IrOutputList[1] = IR(1);
  IrOutputList[2] = IR(2);
  IrOutputList[3] = IR(3);

  Serial.print("IR:");
  for (int i = 0; i < 4; i++) {
    Serial.print(IrOutputList[i]);
    if (i < 3) {
      Serial.print(",");
    }
  }
  Serial.println("");

  int UsOutputList[2] = { 0, 0 };
  UsOutputList[0] = ultrasonic(0);
  UsOutputList[1] = ultrasonic(1);
  Serial.print("ultrasonic:");
  Serial.print(UsOutputList[0]);
  Serial.print(",");
  Serial.print(UsOutputList[1]);
  Serial.println("");
}

void setup() {
  ultrasonicOffset = ultrasonicCorrection();
  leftMotor.setup();
  rightMotor.setup();
}

void loop() {
  Serial.println("Loop Start --------------------------------");
  

/*
  motorControl.forward();
  wait_us(STD_DELAY);
  motorControl.reverse();
  wait_us(STD_DELAY);
  motorControl.rotateClockwise();
  wait_us(STD_DELAY);
  motorControl.rotateCounterClockwise();
  wait_us(STD_DELAY);
*/

  //sensorsOutput();
  Serial.println();
}
