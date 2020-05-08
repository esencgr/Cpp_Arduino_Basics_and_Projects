const int enable = 11;   // 1.pin( PWM pin ) 
const int forward = 10;  // 2.pin
const int backward = 9;  // 7.pin
const int buton = 13, pot = A0;
bool way = 0, st = 0;
int vel = 0;

void setup(){ 
    Serial.begin( 9600 );
    pinMode( forward, OUTPUT );
    pinMode( backward, OUTPUT );
    pinMode( enable, OUTPUT );
    pinMode( buton, INPUT );
}

void loop(){
    change_vel_way_pin( vel, way );
    //change_way_pin();        
    change_vel_way_buton( vel, way );
    //change_way_buton( way );
    //change_way_buton_1( way );
}

void change_vel_way_pin( int v, bool w ){
    v = analogRead( pot );
    v = map( v, 0, 1023, 0, 255 );
    analogWrite( enable, v );
    digitalWrite( backward, w );
    //change_way_pin(  );
}

void change_way_pin(  ){
    digitalWrite( forward, HIGH );
    digitalWrite( backward, LOW ); 
}

void change_vel_way_buton( int v, bool w ){
    v = analogRead( pot );
    v = map( v, 0, 1023, 0, 255 );
    analogWrite( enable, v );
    change_way_buton_1( w );
    //change_way_buton( w );
}

void change_way_buton( bool w ){
    w = digitalRead( buton );
    digitalWrite( forward, w );
    digitalWrite( backward, !w ); 
}

void change_way_buton_1( bool w ){
    w = digitalRead( buton );
    if( w == HIGH ){
        st = !st;
        while( w == HIGH )
            w = digitalRead( buton );
    }
    digitalWrite( forward, st );
    digitalWrite( backward, !st ); 
}
