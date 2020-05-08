const int forward = 10;
const int backward = 9;
const int buton = 13;
bool way = 0, st =0;

void setup(){ 
    Serial.begin( 9600 );
    pinMode( forward, OUTPUT );
    pinMode( backward, OUTPUT );
}

void loop(){
    //change_way_buton_1( way );
    change_way_pin( way );
}

void change_way_pin( bool w ){
    digitalWrite( forward, !w  );
    digitalWrite( backward, w ); 
}

void change_way_buton( bool w ){
    w = digitalRead( buton );
    if( w == HIGH ){
        st = !st;
        while( w == HIGH )
            w = digitalRead( buton );
    }
    digitalWrite( forward, st );
    digitalWrite( backward, !st ); 
}

void change_way_buton_1( bool w ){
    w = digitalRead( buton );
    digitalWrite( forward, w );
    digitalWrite( backward, !w ); 
}
