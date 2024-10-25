#include "mbed.h"
using namespace mbed;

I2C i2c(P0_31, P0_2);

const char mux_addr = 0xEE;
char mux_cmd;
const char IR_addr = 0x80;
char conversionArray[0];
int conversionInt=0;

int IR(int sensor){
  
  char cmd[2];
  cmd[0] = 0x5E;
  cmd[1] = 0x00;

  //Front Left
  if (sensor==0)
  {
  mux_cmd = 0x01;
  }
  //Front Right
  if(sensor==1)
  {
  mux_cmd = 0x02;
  }
  //Side Left
  if(sensor==2)
  {
  mux_cmd = 0x08;
  }
  //Side Right
  if(sensor==3)
  {
  mux_cmd = 0x04;
  }
  
  i2c.write(mux_addr, &mux_cmd, 1);
  i2c.write(IR_addr, cmd, 1);
  wait_us(500000);
  i2c.read(IR_addr, cmd, 2);

  conversionArray[0] = cmd[0],cmd[1];
  return conversionInt=conversionArray[0]*0.2;  
}