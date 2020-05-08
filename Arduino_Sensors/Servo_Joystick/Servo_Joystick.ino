#include <Servo.h>
Servo sg1;            // create a servo object
Servo sg2;
const int x = A0;
const int y = A1;
int x_val, y_val;

void setup(){
    sg1.attach( 9 );  // defined servo pin 
    sg2.attach( 11 );    
    sg1.write( 0 );
    sg2.write( 0 );
    Serial.begin(9600);
}

void loop(){
    x_val = analogRead( x );
    y_val = analogRead( y );
    x_val = map( x_val, 0, 1023, 0, 180 );
    y_val = map( y_val, 0, 1023, 0, 180 );
    
    Serial.println( x_val );
    Serial.println( y_val ); 
    sg1.write( x_val );
    sg2.write( y_val );

    delay(5);   
}
