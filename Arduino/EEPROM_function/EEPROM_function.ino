#include<EEPROM.h>

void setup(){
    Serial.begin( 9600 );
}

void function( int adress_w, int value_w ){    
    EEPROM.write( adress_w, value_w );
    delay( 10 );
    
    int value_read = EEPROM.read( adress_w);
    delay( 10 );

    Serial.print( "adress : " );
    Serial.println( adress_w );
    Serial.print( "value : " );
    Serial.println( value_read );    
}

void loop(){    
    int value = 15000, adress = 1023; // Between 0-1023. 10 bit microcontroller 
    function( adress, value );    
    while( 1 );
}
