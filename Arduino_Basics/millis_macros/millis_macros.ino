
const int led = 3;
unsigned long timer_past = millis() ;
bool led_state = LOW;

void setup(){
    pinMode( led, OUTPUT );
    Serial.begin( 9600 );
}

void loop(){
  
    unsigned long timer_now = millis();   // --> milliseconds unit
    //timer_now = micros(); // --> microseconds unit    
    /*
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
    */
    if( timer_now - timer_past > 1000 ){
        Serial.println( "Timer work" );
        timer_past = timer_now;
    }
      Serial.println( "Delay work" );
      delay( 1000 );
}
