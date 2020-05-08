#include <LiquidCrystal.h>

char character;
int count = 0;
String text = "";
String shifted_text = "";

LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 

void setup(){
    Serial.begin( 9600 );
    lcd.begin( 16, 2 );                    // 2 x 16  col x row
    lcd.home();
}
 
void shift( String text ){
    int c;
    for( int i=0; i<13; i++ ){
      lcd.scrollDisplayRight();
      delay( 150 );
    }
}

void loop(){
    Serial.println( "welcome!" );
    count = Serial.available();
    if( count > 0 ){
        while( Serial.available() > 0 ){
            character = Serial.read();
            if( character != '\n' )
                text += character;
            else{
                shifted_text = text;
                lcd.clear();
                lcd.print( text );
                text = "";   
            }
        }
    }   
    shift( shifted_text );
}
