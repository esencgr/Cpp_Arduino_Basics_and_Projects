const int trig = 3;
const int echo = 4;

void setup(){
    Serial.begin( 9600 );
    pinMode( trig, OUTPUT );
    pinMode( echo, INPUT );
}

void loop(){
    digitalWrite( trig, LOW );                         // sensor is passive 
    delayMicroseconds(5); 
    digitalWrite( trig, HIGH );                        // generate soundwave and activated sensor
    delayMicroseconds(5);
    digitalWrite( trig, LOW );  
    
    int timer = pulseIn( echo, HIGH );
    float distance = ( timer/2 ) / 29.1;
    
    if( distance > 200 )
        distance = 200;
        
    Serial.print( "distance = " );
    Serial.print( distance );
    Serial.println( " cm "  );
    
    delay( 300 );
}
