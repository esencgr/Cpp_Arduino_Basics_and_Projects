#include <LCD5110_Basic.h>

LCD5110 myGLCD(8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void setup()
{
  myGLCD.InitLCD();
}

void loop()
{
   
  myGLCD.setFont(SmallFont);
  myGLCD.print("LRT", CENTER, 0);
  for (int i=0; i<=10000; i++)
  {
    myGLCD.setFont(MediumNumbers);
    myGLCD.printNumF(float(i)/3, 2, RIGHT, 8);
    myGLCD.setFont(BigNumbers);
    myGLCD.printNumI(i, RIGHT, 24);
  }
  myGLCD.clrScr();
  delay(500);
}

