#include <LedControl.h>                 // Add library 

const int CLK = 5, CS = 6, DIN = 7;
const int MAX = 1, DLY = 500;           // MAX DOT MATRIX NUMBER AND DELAY
LedControl led = LedControl( DIN, CLK, CS, MAX );

byte images[ 4 ][ 8 ] = {  { B00011000 }, { B00011000, B00011000 }, { B00010000, B00011000 } };
byte object[ 1 ][ 8 ] = {  B11000000,0,0,0,0,0,0,0 }; 

void setup(){ 
    Serial.begin( 9600 );
    randomSeed( analogRead(0) );
    led.setIntensity(0, 5);          // CONTRAST
    led.shutdown(0, false);          // MATRIX ACTIVATED
    led.clearDisplay(0);
}

void print_object( byte ch[ 1 ][ 8 ] ){
    for( int j=0; j<8; j++ ){
        led.setRow( 0, j, ch[ 0 ][ j ] );            // INT ADRESS, INT ROW, BYTE VALUE
        delay( DLY );
    }
}

void shifted_matrix( byte ch[ 4 ][ 8 ] ){
    int obj_rnd = random( 4 );
    //Serial.println( obj_rnd );
    for( int k=0; k<7; k++ ){
        //Serial.println( k );
        for( int j=0; j<8; j++ ){
            led.setRow( 0, j+k, ( ch[ obj_rnd ][ j ]));   // INT ADRESS, INT ROW, BYTE VALUE
            Serial.println( j );
        }
        delay( DLY );
        led.clearDisplay(0);
    }    
}

void loop(){
    shifted_matrix( images );
    //print_object( object );
}
