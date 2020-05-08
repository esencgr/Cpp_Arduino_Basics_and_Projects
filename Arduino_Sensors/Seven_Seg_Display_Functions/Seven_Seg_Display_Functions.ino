  #include <SevenSeg.h>

SevenSeg disp(2,3,4,5,6,7,8); // ABCDEFG
const int button = 12, button1 = 11;
int button_state = 0, button_state1 = 0, counter = 0, second = 0;
unsigned long timer = 0;

void setup(){
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);    
    pinMode(button, INPUT );

    const int digit_num = 1;
    int digits[digit_num] = { 9 };
    disp.setDigitPins(digit_num,digits);
}

void button_counter(){
    disp.write( counter );
    
    button_state = digitalRead( button );
    if( button_state == HIGH ){
        //delay( 10 );
        counter ++;
        Serial.println( counter );
        
        while( button_state == HIGH ){
            button_state = digitalRead( button );
        }
        //delay( 10 );
        if( counter > 9 )
           counter = 0 ;
        disp.write( counter );
     }   
      
     button_state1 = digitalRead( button1 );
     if( button_state1 == HIGH ){
         //delay( 10 );
         counter--;
         Serial.println( counter );
        
         while( button_state1 == HIGH ){
             button_state1 = digitalRead( button1 );
         }
         //delay( 10 );
         if( counter < 0 )
            counter = 0 ;
         disp.write( counter );
     }    
}

void timer_function( ){
    if( millis() - timer > 1000 ){
        second++;
        timer = millis();
    if( second > 9 )
        second = 0;
    }
    disp.write( second );
}

void loop(){
    timer_function();
    //button_counter(); 
}
