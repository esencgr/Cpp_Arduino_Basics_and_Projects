#include <LiquidCrystal.h>
const int t = 3000;
const int echo = 6;
const int trig = 7;

LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 


void setup(){
    Serial.begin( 9600 );
    lcd.begin( 16, 2 );                    // 2 x 16  col x row
    pinMode( echo, INPUT );
    pinMode( trig, OUTPUT );
 }

void loop(){
    digitalWrite( trig, LOW );                         // sensor is passive 
    delayMicroseconds(5); 
    digitalWrite( trig, HIGH );                        // generate soundwave and activated sensor
    delayMicroseconds(5);
    digitalWrite( trig, LOW ); 
    
    int timer = pulseIn( echo, HIGH );
    float distance = ( timer/2 ) / 29.1;

    lcd.clear();
    lcd.print( "distance: " );
    lcd.setCursor( 0,1 );
    lcd.print( distance );
    lcd.print( "cm" );

    delay( 300 );
    
}
