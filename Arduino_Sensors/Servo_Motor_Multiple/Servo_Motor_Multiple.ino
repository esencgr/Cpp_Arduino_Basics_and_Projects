#include <Servo.h>
const int pot = A0;
Servo sg2;
int pos = 0;

int value, deg;

void setup(){
    sg2.attach( 11 );
    Serial.begin(9600);
    sg2.write(0);
}

void loop(){
    
    for( int pos=0; pos<=180; pos++ ){
        sg2.write( pos );
        delay(10); 
    }
    for( int pos=180; pos>=0; pos-- ){
        sg2.write( pos );
        delay(10); 
    }
}
