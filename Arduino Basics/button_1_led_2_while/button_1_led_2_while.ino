const int green = 8;
const int red = 9;
const int button = 2;
int button_counter = 0;

void setup(){
    Serial.begin( 9600 );
    pinMode( green, OUTPUT );
    pinMode( red, OUTPUT );
    pinMode( button, INPUT );
}

void loop(){
  
    int button_state = digitalRead( button );

    while( button_state == 1 ){
        ++button_counter;
        Serial.println( button_counter );

        if(( button_counter / 10 ) % 2 == 0 ){
            digitalWrite( green, HIGH );
            digitalWrite( red, LOW );
        }
        else{
            digitalWrite( red, HIGH );
            digitalWrite( green, LOW );
        }
        
        button_state = digitalRead( button );
        delay( 200 );
    }
}
