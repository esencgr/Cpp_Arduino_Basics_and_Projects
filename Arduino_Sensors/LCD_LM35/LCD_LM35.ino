#include <LiquidCrystal.h>
const int lm = A0;
LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 

void setup(){
    Serial.begin( 9600 );
    lcd.begin( 16, 2 );                    // 2 x 16  col x row
 }

void loop(){
    float volt = analogRead( A0 );
    volt *= 5000 / 1023; // mV unit voltage
    float temp = volt / 10;
    
    lcd.clear( );  
    lcd.home();
    lcd.print( "temp:" );  
    lcd.print( temp );
    delay( 500 );

}
