#include <SoftwareSerial.h>
#include <String.h>
SoftwareSerial bt(7, 6); // RX,TX

String s = "";
char data;

void setup(){
    Serial.begin( 9600 );
    bt.begin( 9600 );
}
void loop(){
   if( bt.available() > 0 ) {
        delay( 5 );
        while( bt.available() > 0 ){
             data = bt.read();   
             s += data;
        }
        if( s != 0 ){
            Serial.println( s );;
        }
    }                   
    s = "";
} 
