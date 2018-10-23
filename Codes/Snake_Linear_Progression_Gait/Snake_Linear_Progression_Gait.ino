/* Snake Robot Linear Progression gait
 
 Snake performs Linear Progression motion with this piece of code. We can change 
 the amplitude and frequency of the gait 
 
               Compatibility
 CM900                  O
 OpenCM9.04             O
 
                  Dynamixel Compatibility
               AX    MX      RX    XL-320    Pro
 CM900          O      O      O        O      X
 OpenCM9.04     O      O      O        O      X
**** OpenCM 485 EXP board is needed to use 4 pin Dynamixel and Pro Series **** 
 
 created 16 Nov 2012
 by ROBOTIS CO,.LTD.
 */
/* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define ID_NUM1 1
#define ID_NUM2 2
#define ID_NUM3 3
#define ID_NUM4 4
#define ID_NUM5 5
#define ID_NUM6 6
#define ID_NUM7 7
#include <math.h>
/* Control table defines */
#define GOAL_SPEED 32
#define GOAL_POSITION 30

Dynamixel Dxl(DXL_BUS_SERIAL1);

float t = 0 ;
float pi = 3.14;
char n = 'p', n_prev;

void setup() {
  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  
  Dxl.begin(3);
  n = millis();
  Dxl.writeWord(ID_NUM1, GOAL_SPEED, 100);  //Dynamixel ID 1 Speed Control (Address_data : 0~1024)
  Dxl.writeWord(ID_NUM2, GOAL_SPEED, 100);
  Dxl.writeWord(ID_NUM3, GOAL_SPEED, 100);
  Dxl.writeWord(ID_NUM4, GOAL_SPEED, 100);
  Dxl.writeWord(ID_NUM5, GOAL_SPEED, 100);
  Dxl.writeWord(ID_NUM6, GOAL_SPEED, 100);
  Dxl.writeWord(ID_NUM7, GOAL_SPEED, 100);
  
  Dxl.jointMode(ID_NUM1); //jointMode() is to use position mode
  Dxl.jointMode(ID_NUM2);
  Dxl.jointMode(ID_NUM3);
  Dxl.jointMode(ID_NUM4);
  Dxl.jointMode(ID_NUM5);
  Dxl.jointMode(ID_NUM6);
  Dxl.jointMode(ID_NUM7);

  Dxl.writeWord(ID_NUM1, GOAL_POSITION, 366);  // Code for STRAIGHT LINE FORMATION  
  Dxl.writeWord(ID_NUM2, GOAL_POSITION, 350);
  Dxl.writeWord(ID_NUM3, GOAL_POSITION, 358);
  Dxl.writeWord(ID_NUM4, GOAL_POSITION, 357);
  Dxl.writeWord(ID_NUM5, GOAL_POSITION, 370);
  Dxl.writeWord(ID_NUM6, GOAL_POSITION, 370);
  Dxl.writeWord(ID_NUM7, GOAL_POSITION, 360);
  delay(20); 

}

void loop() {
    
  // Code for LINEAR PROPAGATION
  
 
  Dxl.writeWord(ID_NUM1, GOAL_POSITION, 370);
  Dxl.writeWord(ID_NUM2, GOAL_POSITION, 350+60*sin((1*(3.14*t)/6)+((2*3.14))/3));
  Dxl.writeWord(ID_NUM3, GOAL_POSITION, 358);
  Dxl.writeWord(ID_NUM4, GOAL_POSITION, 357+60*sin((1*(3.14*t)/6)+((4*3.14))/3));
  Dxl.writeWord(ID_NUM5, GOAL_POSITION, 370);
  Dxl.writeWord(ID_NUM6, GOAL_POSITION, 360+60*sin((1*(3.14*t)/6)+((6*3.14))/3));
  Dxl.writeWord(ID_NUM7, GOAL_POSITION, 360);
  delay(50);
 
t = t + 0.5;
}


