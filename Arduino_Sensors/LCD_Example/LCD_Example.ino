#include <LiquidCrystal.h>
const int t = 3000;
LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 

void setup(){
    lcd.begin( 16, 2 );                    // 2 x 16  col x row
}

void loop(){
  
    lcd.clear( );  
    lcd.home();
    lcd.print( "ARDUINO" );  
    delay( 500 );
    
    for( int k = 0; k < 4; k++ ){
        lcd.scrollDisplayRight();
        delay( 500 );
    }
   
    lcd.clear( );  
    lcd.setCursor( 9, 1 );
    lcd.print( "ARDUINO" );  
    delay( 500 );  
    
    for( int k = 0; k < 4; k++ ){
        lcd.scrollDisplayLeft();
        delay( 500 );
    }  
    
//while( 1 );
}
