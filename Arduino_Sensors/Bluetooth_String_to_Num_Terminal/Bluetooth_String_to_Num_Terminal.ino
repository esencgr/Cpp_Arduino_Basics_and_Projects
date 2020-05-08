#include <SoftwareSerial.h>
#include <String.h>

SoftwareSerial bt(7, 6); // RX,TX
char data;
unsigned int num = 0;
String s = "";

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
             num *= 10;
             num += ( (int)( data ) - 48 );
        }
        if( num != 0 ){
            Serial.print( s );
            Serial.print( "-->" );
            Serial.println( num );
        }
    }                   
    num = 0;
    s = "";
} 
