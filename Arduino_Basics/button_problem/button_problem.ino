const int button = 12;
const int led = 13;
bool led_state = 0, button_state = 0; 
int count = 0;
void setup(){
    Serial.begin( 9600 );
    pinMode( led, OUTPUT );
    pinMode( button, INPUT );
}

void loop(){
    int pressed = button_read( button );
    if( pressed == 1 ){
        count++;
        if( led_state == 0 ){
            digitalWrite( led, HIGH );
            led_state = 1;
        }
        else{
            digitalWrite( led, LOW );
            led_state = 0;
        }
    }
    Serial.println( count );
    delay ( 30 );
}

bool button_read( int button_pin ){
    int read_value = digitalRead( button_pin );
    delay(30);
    if( read_value == digitalRead( button_pin ))
        return read_value;
    else 
        return false;     
}
