#include <EEPROM.h>

const int led = 3;
unsigned long timer_now, timer_past;
bool led_state = LOW;

void setup(){
    pinMode( led, OUTPUT );
    Serial.begin( 9600 );
}

void loop(){
  
    //led_p();
    timer_now = millis();
    Serial.println( timer_now );
    if( timer_now - timer_past >= 1000 ){
        if( led_state == LOW ){
            digitalWrite( led, led_state );
            led_state = HIGH;
        }
        else{
            digitalWrite( led, led_state );
            led_state = LOW;
      }
        timer_past = timer_now;
    }
    Serial.println( "A different process doing in the same time by Arduino.." );
    delay( 100 );
}
