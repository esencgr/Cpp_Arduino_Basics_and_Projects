#include <LCD5110_Basic.h>
LCD5110 lcd( 8, 9, 10, 11, 12 ); 

extern uint8_t arduino_logo[];      

void setup(){
    lcd.InitLCD();
}

void loop(){
    lcd.drawBitmap( 0, 0, arduino_logo, 79, 42 );   // 0,0 dan başlayacak ve 42x42 pixel
 }
