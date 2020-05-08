#include <Servo.h>
#include <SoftwareSerial.h>
#include <String.h>

SoftwareSerial bt(7, 6); // RX,TX
Servo sg;
char data;
unsigned int pos, npos;
String s = "";

void setup(){
    sg.attach( 9 );
    Serial.begin( 9600 );
    bt.begin( 9600 );
    //sg.write( 0 );
}

void loop(){
    if( bt.available() > 0 ){
        pos = 0;
        s = "";
        while( bt.available() > 0 ){
            data = bt.read();   
            s += data;
            pos *= 10;
            pos += ( (int)(data) - 48 );
        }
    } 
    npos = map( pos, 0, 255, 0, 180 );
    Serial.println( npos );
    sg.write( npos );
}
