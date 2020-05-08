#include <LedControl.h>                 // Add library 

const int CLK = 5, CS = 6, DIN = 7;
const int MAX = 1, DLY = 500;           // MAX DOT MATRIX NUMBER AND DELAY
LedControl led = LedControl( DIN, CLK, CS, MAX );
unsigned long  timer_past = 0;
int k = 0;
byte object[ 1 ][ 8 ] = { B11000000 };
byte block [ 1 ][ 8 ] = { B11000000, 0, 0, 0, 0, 0 ,0, 0}; 
byte del   [ 1 ][ 8 ] = {  }; 

void setup(){ 
    Serial.begin( 9600 );
    randomSeed( analogRead(0) );
    led.setIntensity(0, 3);          // CONTRAST
    led.shutdown(0, false);          // MATRIX ACTIVATED
    led.clearDisplay(0);
}

void print_object( byte obj[ 1 ][ 8 ] ){
    for( int j=0; j<8; j++ )
        led.setRow( 0, j, obj[ 0 ][ j ] );            // INT ADRESS, INT ROW, BYTE VALUE 
    //delay(DLY);
}

void shift_block_timer( byte blck[ 1 ][ 8 ] ){
    unsigned long timer_now = millis();   // --> milliseconds unit 
    int rnd = random( 7 );
    for( int a=0; a<8; a++ ){
         if( timer_now - timer_past > 1000 ){
             //Serial.println( rnd );
             led.setRow( 0, k++, blck[ 0 ][ 0 ] );   // INT ADRESS, INT ROW, BYTE VALUE
             timer_past = timer_now;
         }  
         led.setRow( 0, k-2, del[ 0 ][ 0 ]  );   // INT ADRESS, INT ROW, BYTE VALUE
    }
}

void loop(){
     //print_object( object );  
     shift_block_timer( block );   
}
