#include <SoftwareSerial.h>
#include <String.h>

SoftwareSerial bt(7, 6); // RX,TX
const int led = 9;
char data;
unsigned int digit;
String s = "";

void setup(){
    pinMode( led ,OUTPUT );
    Serial.begin( 9600 );
    bt.begin( 9600 );
}

void loop(){
    if( bt.available() > 0 ){
        digit = 0;
        s ="";
        delay( 2 );
        while( bt.available() > 0 ){
            data = bt.read();   
            s += data;
            digit *= 10;
            digit += ( (int)(data) - 48 );
        }
    } 
    Serial.println( digit );
    analogWrite( led, digit );
} 
