#include <Servo.h>
const int pot = A0;
Servo sg;            // create a servo object
int value, deg;

void setup(){
    sg.attach( 9 );  // defined servo pin 
    Serial.begin(9600);
}

void loop(){
  
    value = analogRead( pot );
    deg = map( value, 0, 1023, 0, 180 );   

    Serial.println( deg );
    
    sg.write( deg );
    delay( 10 );
}
