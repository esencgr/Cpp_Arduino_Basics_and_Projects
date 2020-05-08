#include <SoftwareSerial.h>
#include <String.h>

SoftwareSerial bt(7, 6); // RX,TX
const int led = 9;
char data;
int number = 0, count = 0;
String s = "";

void setup(){
    pinMode( led ,OUTPUT );
    Serial.begin(9600);
    bt.begin(9600);
}

void loop(){
    while( bt.available() > 0 ){ 
        data = bt.read();   
        if ( data == '#' ){ 
            number = 0; 
            s = "";
        }
        else{
            s += data;
            number *= 10;
            number += ( (int)(data) - 48 );
        }
    }
    Serial.print( s );
    Serial.print( "-->" );
    Serial.println( number );
    analogWrite( led, number );
    delay( 1000 );

} 
