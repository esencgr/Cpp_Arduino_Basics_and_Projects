#include <LCD5110_Basic.h>
LCD5110 lcd( 8, 9, 10, 11, 12 ); 

extern uint8_t SmallFont[];
const int button = 5;
int button_state = 0;
bool state = 0;

void setup(){
    Serial.begin(9600);
    pinMode( button, INPUT );
    lcd.InitLCD();
    lcd.setFont( SmallFont );
}

void loop(){
    lcd.print( "DISTANCE", CENTER, 16);
    lcd.print( "VOLUME", CENTER, 24);
   
    button_state = digitalRead( button );
    if( button_state == HIGH && state == 0 ){
        lcd.clrRow( 3, 0, 15 );
        lcd.print( " > ", LEFT, 16 );
        state = 1;
        while( button_state == HIGH )
            button_state = digitalRead( button );
        delay( 100 );  
    }
           
    button_state = digitalRead( button );
    if( button_state == HIGH && state == 1 ){
        lcd.clrRow( 2, 0, 15 );
        lcd.print( " > ", LEFT, 24 );
        state = 0;
        while( button_state == HIGH )
            button_state = digitalRead( button );
        delay( 100 );  
    }
}
