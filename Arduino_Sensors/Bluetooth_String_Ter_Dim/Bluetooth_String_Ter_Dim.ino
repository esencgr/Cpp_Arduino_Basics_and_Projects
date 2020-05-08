#include <SoftwareSerial.h>
SoftwareSerial bt( 7, 6 ); // RX,TX
String command = ""; 
char data;

void setup(){     
    // Open serial commmunication 
    Serial.begin( 9600 );
    bt.begin( 9600 );
}

void loop(){
    // read device output if available 
    if( bt.available() > 0 ){
        command = "";
        delay(2);
        while( bt.available() > 0 ){
            data = bt.read();
            command += data;
        }
    } 
    Serial.println( command );  
}
