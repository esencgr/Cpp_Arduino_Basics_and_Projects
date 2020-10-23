const int ldr_pin = A0;
const int led_pin = 3;

void setup() {
    Serial.begin( 9600 );
    pinMode( led_pin, OUTPUT );
}
/*
void loop() {
    int ldr_value = analogRead( ldr_pin );
    Serial.println( ldr_value );
    delay( 500 );
    if( ldr_value < 20 )
       digitalWrite ( led_pin, HIGH );
    if( ldr_value > 60 )
       digitalWrite ( led_pin, LOW );
}*/
void loop() {
    int ldr_value = analogRead( ldr_pin );
    Serial.println( ldr_value );
    
    ldr_value = map( ldr_value, 0, 610, 0, 255 );
    Serial.println( 255 - ldr_value );
    
    analogWrite( led_pin, 255 - ldr_value );
    delay( 2000 );
}
