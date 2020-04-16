#include<EEPROM.h>

int adress_w = 1023; // Between 0-1023. 10 bit microcontroller 
int value_w = 10;
int adress_r = adress_w;
int value_r;

void setup(){
    Serial.begin( 9600 );
}

void loop(){
  
    //adress_w = 10;
    //value_w;
    
    EEPROM.write( adress_w, value_w );
    delay( 10 );
    
    //adress_r = 10;
    value_r = EEPROM.read( adress_w );
    delay( 10 );
    
    Serial.print( "adress : " );
    Serial.println( adress_w );
    Serial.print( "value : " );
    Serial.println( value_r );
    
    while( 1 );
}
