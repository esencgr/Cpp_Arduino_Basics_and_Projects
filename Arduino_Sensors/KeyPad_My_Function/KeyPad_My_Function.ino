#include <Keypad.h>
#include <String.h>

const byte row = 4, col = 4;
char *pswd = "1234";
int pos=0;

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
    Serial.println( "Enter password : " );
}
void get_password(){ 
    char key = key_map.getKey( );
    if( key == pswd[ pos ] ){
        pos++;
    }
    else{ 
        Serial.println("invalid key" );
        pos=0;
        Serial.println("enter password again :")
    }
    if( pos == 4 ){
        Serial.println("verified password");
        pos = 0;
        delay( 500 );
    }   
}

void loop(){
    get_password();
}
