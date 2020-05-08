#include <SoftwareSerial.h>
SoftwareSerial bt( 7, 6 ); // RX,TX
char data;

void setup(){     
    // Open serial commmunication 
    Serial.begin( 9600 );
    bt.begin( 9600 );
}

void loop(){
    // read device output if available 
    if( bt.available() ){
        data = bt.read();
        Serial.print( command );
    } 
}
