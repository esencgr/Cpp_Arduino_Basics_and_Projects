#include <Keypad.h>
#include <String.h>

const byte row = 4, col = 4;
const char pswd[4] = {'1','2','3','A'};
char guess[3];
String p = "123", g = "123";
char key;
int i=0;

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
        guess[i++] = key;
        Serial.print("*");
        
    }
    if( i==4 ){
        delay( 750 );
        if( strcmp( pswd, guess ) == 1 ){
            Serial.println("Pswd is correct.\n");
            i=0;
            Serial.println( "Enter password:" );
        }
        else{
            Serial.println("Pswd is not correct!\n");
            i=0;
            Serial.println( "Enter password again:" );
        }
    }
}
void loop(){
    get_password(); 
}
