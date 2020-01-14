const int led = 3;

void setup(){
    Serial.begin( 9600 );
    pinMode( led, OUTPUT );
}

void loop(){ 
        digitalWrite( led, HIGH );
        delay( 100 );
        digitalWrite( led, LOW );
        delay( 100 );
}
