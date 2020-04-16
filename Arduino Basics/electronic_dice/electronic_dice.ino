const int buton = 2; 
const int led[] ={3,4,5,6,7};
void setup(){
    Serial.begin( 9600 );
    randomSeed( analogRead(0) );
}

void loop() {
    int buton_state = buton_read( buton );
    
    if ( buton_state == HIGH ){  
        int rand_num = random( 5 );
        for( int i=0; i<rand_num; i++){
            digitalWrite( led[i], HIGH );
        }   
        Serial.println( rand_num );
        delay( 1000) ;
    }
    else{
        for( int i=0; i<=4; i++ )
           digitalWrite( led[i], LOW);
    }
}

boolean buton_read (int buton ){
    int value = digitalRead( buton );
    delay( 30 );
    if ( value == digitalRead( buton ))
       return value;
    else 
       return false;
}
