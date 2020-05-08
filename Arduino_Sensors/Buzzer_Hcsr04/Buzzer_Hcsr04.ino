const int buzzer = 7;
const int trig = 8;
const int echo = 9;

void setup(){
    Serial.begin( 9600 );
    pinMode( trig, OUTPUT );
    pinMode( echo, INPUT );
    pinMode( buzzer, OUTPUT );
}

float measure(){
  
    digitalWrite( trig, LOW );                         // sensor is passive 
    delayMicroseconds(5); 
    digitalWrite( trig, HIGH );                        // generate soundwave and activated sensor
    delayMicroseconds(5);
    digitalWrite( trig, LOW );  
    
    int timer = pulseIn( echo, HIGH );
    float distance = ( timer/2 ) / 29.1;
    
    if( distance > 200 )
        distance = 200;

    return distance;    
}

int melody( int dist ){
    tone( buzzer, 440 );
    delay( dist*10 );
    noTone( buzzer);
    delay( dist*10 );
}

void loop(){ 
    float d = measure();
    
    Serial.print( "distance = " );
    Serial.print( measure() );
    Serial.println( " cm "  );

    melody(d);
}
