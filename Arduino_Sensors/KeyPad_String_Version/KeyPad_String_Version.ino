#include <Keypad.h>
#include <String.h>

const byte row = 4, col = 4; 
String p = "1234", g = "";
char key; 
int digit =0;

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
    Serial.println( "Enter password:" );
}

void get_password(){ 
    key = key_map.getKey( );
    if( key ){
        g += key;
        Serial.print( key );
        digit++;
    }
    if( digit==4 ){
        delay( 750 );
        if( p == g ){
            Serial.println("\nPswd is correct.\n");
            digit = 0;
            Serial.println( "Enter password:" );
        }
        else{
            Serial.println("\nPswd is not correct!\n");
            digit = 0;
            Serial.println( "Enter password:" );
        }
        g = "";
    }
}
void loop(){
    get_password(); 
}
