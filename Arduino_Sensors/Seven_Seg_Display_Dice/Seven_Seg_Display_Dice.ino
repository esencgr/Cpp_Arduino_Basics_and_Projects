#include <SevenSeg.h>

SevenSeg disp( 2, 3, 4, 5, 6, 7, 8 ); // A B C D E F G .
const int button = 13;
int button_state = 0, rand_num;

void setup(){
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);    
    pinMode(10, OUTPUT); 
    pinMode(button, INPUT );

    const int digit_num = 1;
    int digits[digit_num] = { 9 };
    disp.setDigitPins(digit_num,digits);
    
    Serial.begin( 9600 );
    randomSeed( analogRead(0) );
}

void loop(){
    button_state = digitalRead( button ); 
    if ( button_state == LOW ){
        digitalWrite( 10, 0 );
        delay ( 100 );
        digitalWrite( 10, 1 );     
        delay ( 100 );    
    }  
    else{   
        rand_num = random( 1,7 );
        disp.write( rand_num );
        delay( 100 );
        button_state = digitalRead( button ); 
        while( button_state == LOW ){
            disp.write( rand_num );  
            button_state = digitalRead( button );
            if( button_state == HIGH ) 
                break;
        }
    }
}
