const int green = 8;
const int red = 9;
const int button = 2;

void setup(){
    pinMode( green, OUTPUT );
    pinMode( red, OUTPUT );
    pinMode( button, INPUT );
}

void loop(){
    int button_counter = 0;
    int button_state = digitalRead( button );

    if( button_state == 1 )
       button_counter++;

    if( button_counter % 2 == 1 ){
       digitalWrite( green, HIGH );
       digitalWrite( red, LOW );
    }
    else{
       digitalWrite( red, HIGH );
       digitalWrite( green, LOW );
    }
    delay( 50 );
}
