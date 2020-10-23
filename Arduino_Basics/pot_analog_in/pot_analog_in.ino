const int pot = A0;

void setup(){
    Serial.begin( 9600 );
}

void loop(){
    float value = analogRead( pot );
    value = ((float)5/1023 ) * value * 100;
    Serial.print( "POT: " );
    Serial.println( value );
    delay( 500 );
}
