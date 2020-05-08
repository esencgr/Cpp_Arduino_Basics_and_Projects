#include <LedControl.h>                 // Add library 

const int CLK = 5, CS = 6, DIN = 7;
const int MAX = 1, DLY = 50;           // MAX DOT MATRIX NUMBER AND DELAY
LedControl led = LedControl( DIN, CLK, CS, MAX );

byte image[ 8 ] = { 0x00, 0x66, 0xFF, 0xFF, 0x7E, 0x3C, 0x18, 0x00 };

/*
byte image[ 8 ] = {
     B00000000,                     // HEART
     B01100110,
     B11111111,
     B11111111,
     B01111110,
     B00111100,
     B00011000,
     B00000000
};
*/
byte images[ 2 ][ 8 ] = { 
     { B00111100,                    // SAD
       B01000010,
       B10100101,
       B10000001,
       B10011001,
       B10100101,
       B01000010,
       B00111100 },
       
     { B00111100,                    // HAPPY
       B01000010,
       B10100101,
       B10000001,
       B10000001,
       B10100101,
       B01011010,
       B00111100 }  
};

void setup(){ 
    Serial.begin( 9600 );
    led.setIntensity(0, 5);          // CONTRAST
    led.shutdown(0, false);          // MATRIX ACTIVATED
    led.clearDisplay(0);
}

void contrast(){
    for( int i=0; i<5; i++ ){        // CONTRAST EFFECT MIN TO MAX
        led.setIntensity( 0, i );
        delay( 5 );
    }
}

void bin_to_hex( byte im[ 8 ] ){
    for( int i=0; i<8; i++ ) {
        Serial.print( "0x" );
        Serial.print( im[ i ] , HEX );
        Serial.print( ", " );
    }
    delay( 1000 );
    while(1);
}

void bin_to_hex_2( byte ch[ 2 ][ 8 ] ){  
    for( int i=0; i<2; i++ )
      for( int j=0; j<8; j++ )
          Serial.println( ch[ i ][ j ] , HEX );
    delay( 1000 );
    while(1);
}
void matrix_print( byte img[ 8 ] ){ 
    for( int i=0; i<8; i++ )
        led.setRow( 0, i, img[ i ] );                     // INT ADRESS, INT ROW, BYTE VALUE
    contrast();
}

void shifted_matrix( byte img[ 8 ] ){
    for( int k=0; k<16; k++ ){
        for( int i=0; i<8; i++ )
            led.setRow( 0, i,( img[ i ] << 7 ) >> k );   //  INT ADRESS, INT ROW, BYTE VALUE
        contrast();
        delay( DLY );
    }
} 

void matrix_print_2( byte ch[2][8] ){
    for( int i=0; i<2; i++ ){   
        for( int j=0; j<8; j++ )
            led.setRow( 0, j, ch[ i ][ j ] );            // INT ADRESS, INT ROW, BYTE VALUE
        contrast();
        delay( DLY );
    } 
}

void shifted_matrix_2( byte ch[2][8] ){
    for( int i=0; i<2; i++ ){   
        for( int k=0; k<16; k++ ){
            for( int j=0; j<8; j++ )
                led.setRow( 0, j, (ch[ i ][ j ] << 7 ) >> k );   // INT ADRESS, INT ROW, BYTE VALUE
        contrast();
        delay( DLY );
        }
    } 
}

void loop(){
    // matrix_print( image );
    // shifted_matrix( image );
    // bin_to_hex( image );
    
    // matrix_print_2( images )
    // shifted_matrix_2( images );

    // led.clearDisplay(0);
    // delay( DLY );
}
