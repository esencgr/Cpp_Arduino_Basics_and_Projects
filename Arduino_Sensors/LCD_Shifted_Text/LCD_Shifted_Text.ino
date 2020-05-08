#include <LiquidCrystal.h>
const int t = 3000;

LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 

void function(){
    for( int k=0; k<5; k++ ){
        lcd.setCursor( k,0 );
        delay( 500 );
        lcd.print("x");
        delay( 250 );
    }
    lcd.clear();
}

void setup(){
    Serial.begin( 9600 );
    lcd.begin( 16, 2 );                    // 2 x 16  col x row
 }

void loop(){
      
    lcd.print("function_1");
    delay( 1000 );
    lcd.clear();
    
    lcd.print("R");
    //delay( 500 );
    for( int k=0; k<10; k++ ){
          lcd.scrollDisplayRight( );
          delay( 500 );
    }
    lcd.clear();
    
    lcd.print("function_2");
    delay( 1000 );
    lcd.clear();
    
    lcd.setCursor( 15,1 );
    lcd.print("L");
    //delay( 500 );
    for( int k=0; k<10; k++ ){
          lcd.scrollDisplayLeft( );
          delay( 500 );
    }
    lcd.clear();
    
    lcd.print("function_3");
    delay( 1000 );
    lcd.clear();
    
    function();

    while(1);
}
