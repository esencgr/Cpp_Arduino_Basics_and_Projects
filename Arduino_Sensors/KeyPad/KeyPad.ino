#include <Keypad.h>
const byte row = 4, col = 4;
char key;

// Keypad map 
char suit[ row ][ col ] = {
     {'1','2','3','A'}, 
     {'4','5','6','B'}, 
     {'7','8','9','C'}, 
     {'*','0','#','D'},
     };

byte row_pins[] = { 13, 12, 11, 10 };
byte col_pins[] = { 9, 8, 7, 6 };

Keypad key_map = Keypad( makeKeymap( suit ), row_pins, col_pins, row, col ); 

void setup(){    
    Serial.begin(9600);
}

void loop(){
  
    key = key_map.getKey( );
    if( key )
        Serial.println( key );
    
        
}
