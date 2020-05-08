#include <LCD5110_Basic.h> // 48-84
LCD5110 lcd( 8, 9, 10, 11, 12 ); 

extern uint8_t SmallFont[];

const int pot = A0;
int pot_val;

void setup(){
    Serial.begin(9600);
    lcd.InitLCD();
    lcd.setFont( SmallFont );
}

void loop(){
    pot_val = analogRead( pot );
    pot_val = map( pot_val, 0, 1023, 0, 12 );
    Serial.println ( pot_val ); 
    for( int i=0; i<=( pot_val*7); i+=7 ){
        lcd.print( "*", LEFT+i, 16 );           
    }
    delay( 250 );
    lcd.clrScr();
}
