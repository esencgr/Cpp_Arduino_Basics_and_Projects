 #include <LCD5110_Basic.h>
LCD5110 lcd( 8, 9, 10, 11, 12 ); 

extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];

const int echo = 4, trig = 3, button = 5;
bool state = 0, button_state = 0;

void animation(){
    lcd.setFont( SmallFont );
    lcd.print(" ARDUINO ", CENTER, 16 );
    for( int i=0; i<2; i++ ){
        lcd.invert( false );
        delay( 500 );
        lcd.invert( true );
        delay( 500 );
    }
    lcd.invert( false );
    lcd.clrScr();
}

float distance( ){
    digitalWrite( trig, LOW );
    delayMicroseconds(5);
    digitalWrite( trig, HIGH );
    delayMicroseconds(10);
    digitalWrite( trig, LOW );

    int sure = pulseIn( echo, HIGH );
    float dist = ( sure / 2 ) / 29.1;
    if( dist > 50 )
        dist = 50;
    if( dist <=0 )
        dist = 0;
    return dist;
}

void wake_sleep(){
    lcd.print( "DISTANCE", CENTER, 8 );
    lcd.printNumF( distance(), 2, LEFT+20, 24 );
    lcd.print( "cm", LEFT+53, 24 );  
    delay( 1000 );
    
    button_state = digitalRead( button );
    if( button_state == HIGH && state == 0 ){
        lcd.enableSleep();
        state = 1;
        while( button_state == HIGH )
            button_state = digitalRead( button );
        delay( 300 );  
    }
    button_state = digitalRead( button );
    if( button_state == HIGH && state == 1 ){
        lcd.disableSleep();
        state = 0;
        while( button_state == HIGH )
            button_state = digitalRead( button );
        delay( 300 );
    }
}

void setup(){
    Serial.begin(9600);
    pinMode( trig, OUTPUT);
    pinMode( echo, INPUT );
    pinMode( button, INPUT );
    lcd.InitLCD();
    animation();
}
void loop(){
    wake_sleep(); 
}
