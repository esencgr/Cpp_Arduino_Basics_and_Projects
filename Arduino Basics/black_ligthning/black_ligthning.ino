const int leds[ 5 ] = { 8, 9, 10, 11, 12 };
const int d = 200;

void setup() {
    for( int i=0; i<5; i++ )
        pinMode( leds[ i ], OUTPUT ); 
}

void loop() {
    for( int i=0; i<4; i++ ){
        digitalWrite( leds[ i ], HIGH );
        delay( d );
        digitalWrite( leds[ i+1 ], HIGH );
        delay( d );     
        digitalWrite( leds[ i ], LOW );
        delay( d*2 );
    }    
    for( int i=4; i>0; i-- ){
        digitalWrite( leds[ i ], HIGH );
        delay( d );
        digitalWrite( leds[ i-1 ], HIGH );
        delay( d );     
        digitalWrite( leds[ i ], LOW );
        delay( d*2 );
    }
}
