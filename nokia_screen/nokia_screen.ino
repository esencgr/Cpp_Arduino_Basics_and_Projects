#include <LCD5110_Basic.h>

LCD5110 myGLCD(8,9,10,11,12);

extern uint8_t arduino_logo[];
extern uint8_t oshw_logo[];

void setup()
{
  myGLCD.InitLCD();
}

void loop()
{
  myGLCD.drawBitmap(0, 0, arduino_logo, 84, 48);
  delay(4000);
  for (int i=0; i<2; i++)
  {
    myGLCD.invert(true);
    delay(500);
    myGLCD.invert(false);
    delay(500);
  }
  delay(4000);

  myGLCD.clrScr();
  myGLCD.drawBitmap(14, 0, oshw_logo, 56, 48);
  delay(4000);
  for (int i=0; i<2; i++)
  {
    myGLCD.invert(true);
    delay(500);
    myGLCD.invert(false);
    delay(500);
  }
  delay(4000);
}
