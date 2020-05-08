#include <LiquidCrystal.h>
const int t = 3000;
byte x[8][5] = { B00000
                 B00000
                 B01010
                 B00100
                 B01010
                 B00000
                 B00000
                 B00000 };
                 
LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 

void setup(){
    Serial.begin( 9600 );
    lcd.begin( 16, 2 );                    // 2 x 16  col x row
    lcd.createChar( 1, x );                // ( character_no, character_name ) 
 }

void loop(){
      
    lcd.home();
    lcd.write( byte(1)); 

    while(1);
}
