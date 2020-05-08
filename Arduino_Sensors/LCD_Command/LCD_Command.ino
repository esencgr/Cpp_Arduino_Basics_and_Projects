#include <LiquidCrystal.h>
const int t = 3000;

LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 

void setup(){
    Serial.begin( 9600 );
    lcd.begin( 16, 2 );                    // 2 x 16  col x row
 }

void loop(){
  
    // lcd.blink();
    // lcd.noBlink();
        
    lcd.cursor();
    // lcd.noCursor();
    
    lcd.setCursor( 4, 0 );
    lcd.display();
    lcd.print( "opened!" );
    delay( t );

    lcd.clear();

    lcd.setCursor( 5, 0 );
    lcd.print( "data" );
    delay( t );
    
    lcd.clear();
    
    lcd.setCursor( 4, 0 );
    lcd.print( "closed!" );
    delay( t );
    lcd.noDisplay();
   
    lcd.clear();

    while( 1 );
}
