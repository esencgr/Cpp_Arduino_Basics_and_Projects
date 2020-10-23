const int led = 7;

void led_function( int tour, int timer ){
    Serial.println( tour );
    Serial.println( timer );
    
    for( int i=0; i<tour; i++ ){
        digitalWrite( led, HIGH );
        delay( timer );
        digitalWrite( led, LOW );
        delay( timer );
    }
}

void setup(){
    Serial.begin( 9600 );
    randomSeed( analogRead(0) );
    pinMode( led, OUTPUT );
}

void loop(){ 
    int r_time = random( 500 );
    led_function( random( 20 ), r_time );
    delay( 2000 );
}
