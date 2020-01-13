#define pot A0
#define led 3
void setup(){
    pinMode( led, OUTPUT );
}

void loop(){
    int value = analogRead( pot );
    value = map( value, 0, 1023, 0, 255 );
    analogWrite( led, value);
}
