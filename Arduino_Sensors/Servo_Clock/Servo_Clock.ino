#include <Servo.h>

Servo sg1;            // create a servo object
Servo sg2;
int minute = 0;

void setup(){
    sg1.attach( 9 );  // defined servo pin 
    sg2.attach( 11 );
    Serial.begin(9600);
}

void loop(){
    sg1.write(0);
    for( int pos=3; pos<=180; pos+=3 ){
        sg1.write( pos );
        Serial.println( "sec : " );
        Serial.println( pos/3 );
        delay( 1000 ); 
        
        if( pos == 174 ){
           minute++;
           sg2.write( minute*20 );
           Serial.println( "min : " );
           Serial.println( minute );
        }
    }
}
