#include <Servo.h>
#include <SoftwareSerial.h>
#include <String.h>

SoftwareSerial bt(7, 6); // RX,TX
Servo sg;
char data;
unsigned int pos;
String s = "";

void setup(){
    sg.attach( 9 );
    Serial.begin( 9600 );
    bt.begin( 9600 );
    sg.write( 0 );
}

void loop(){
    if( bt.available() > 0 ){
        delay( 5 );
        while( bt.available() > 0 ){
            data = bt.read();   
            s += data;
            pos *= 10;
            pos += ( (int)(data) - 48 );
        }  
        if( pos != 0 ){ 
            Serial.println( pos );
            sg.write( pos );     
        } 
    } 
    pos = 0;
    s = "";
}
