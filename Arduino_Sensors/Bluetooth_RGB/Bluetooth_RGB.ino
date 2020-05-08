#include <SoftwareSerial.h>
SoftwareSerial bt(7, 6); // RX,TX

const int r = 9, g = 10, b = 11;
char data;

void setup(){
    pinMode( r, OUTPUT );
    pinMode( g, OUTPUT );  
    pinMode( b, OUTPUT );
    Serial.begin(9600);
    bt.begin(9600);
}

void loop(){
    if( bt.available() ){
        data = bt.read();
        switch( data ){
           case 'r': 
               digitalWrite( r, 1-HIGH );
               digitalWrite( g, 1-LOW );
               digitalWrite( b, 1-LOW );
           break;
           case 'g': 
               digitalWrite( r, 1-LOW );
               digitalWrite( g, 1-HIGH );
               digitalWrite( b, 1-LOW );
           break;
           case 'b': 
               digitalWrite( r, 1-LOW );
               digitalWrite( g, 1-LOW );
               digitalWrite( b, 1-HIGH );
           break;
        }   
    }
}
