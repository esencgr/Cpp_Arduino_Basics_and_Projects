#include<EEPROM.h>

// Hand written functions by me for lowbyte and highbyte.. 
byte low( int number ){
    byte l = number & ( 255 );
    return l;
}

int high( int number ){
    int h = number & ( 255 << 8 );
    return ( h >> 8 );
}

int num = 32760;
byte lsb = low( num ); // Arduino functions lowByte( number );
int msb = high( num ); // Arduino functions highByte( number );
    int lsb_r, msb_r;

void setup(){
    Serial.begin( 9600 );
}

void loop(){
    //int lsb_r, msb_r;
    
    EEPROM.write( 10, lsb );
    EEPROM.write( 11, msb );
     
    lsb_r = EEPROM.read( 10 );
    msb_r = EEPROM.read( 11 );

    Serial.print( "lsb_r : " );
    Serial.println( lsb_r, BIN );
    Serial.print( "msb_r : " );
    Serial.println( msb_r, BIN );
    

    
    int number = ( msb_r << 8 ) + lsb_r;
    
    Serial.print( "sum: " );
    Serial.println( number );
    Serial.print( "sum_binary : " );
    Serial.println( number, BIN );
    
    while( 1 );
}
