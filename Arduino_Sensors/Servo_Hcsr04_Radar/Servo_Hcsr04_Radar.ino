#include <Servo.h>
const int trig = 8;
const int echo = 9;
Servo sg;
int deg ;

void setup(){
    sg.attach( 11 );
    Serial.begin( 9600 );
    pinMode( trig, OUTPUT );
    pinMode( echo, INPUT );
}

float distance( ){
    digitalWrite( trig, LOW );
    delayMicroseconds(5);
    digitalWrite( trig, HIGH );
    delayMicroseconds(5);
    digitalWrite( trig, LOW );

    int sure = pulseIn( echo, HIGH );
    float dist = sure / 29.1 / 2;
    if( dist > 200 )
        dist = 200;
    return dist;
}

void wrt( int dg, float dis ){
    Serial.print( "degree = " );
    Serial.println( dg );
    Serial.print( "distance = " );
    Serial.println( dis,3 );
}

void servo( ){
    for( deg=0; deg<180; deg+=20 ){
        sg.write( deg );
        delay( 1000 );
        wrt( deg, distance());        
    }
    for( deg=180; deg>0; deg-=20 ){
        sg.write( deg );
        delay( 1000 );
        wrt( deg, distance());        
    }
}


void loop(){
    //sg.write(0);
    servo();
}
