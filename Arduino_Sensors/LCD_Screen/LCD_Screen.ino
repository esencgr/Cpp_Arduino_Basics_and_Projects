#include <LiquidCrystal.h>

LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 

void setup(){
     Serial.begin( 9600 );
     lcd.begin( 16, 2 );                    // 2 x 16  row x col
 }

void loop(){
  
     for( int i=0; i<10; i++ ){
         Serial.print( i );
         delay(1000);
         lcd.clear();
     }
     lcd.print( "HELLO WORLD !" );
     while(1);
}
