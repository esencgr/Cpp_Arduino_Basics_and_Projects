const int trig = 8;
const int echo = 9;
const int lm = A0;

void setup(){
    Serial.begin( 9600 );
    pinMode( trig, OUTPUT );
    pinMode( echo, INPUT );
}
<
void loop(){   
    float volt = analogRead( lm ); 
    volt = ( volt / 1023 ) * 5000;  // mV unit voltage + = (* 0.48828125)
    float temp = volt / 10.0; 
    
    Serial.print( "Temperature = " );
    Serial.print( temp, 4 );
    Serial.println(" C^");

    float v_sound = 331 * sqrt( 1 + (temp / 273) );    // v_sound --> ( meter / second )
    v_sound = v_sound * 100 / 1000000;                 // v_sound --> ( cantimeter / microsecond )
    Serial.println( v_sound, 4 );

    float constant = 1 / v_sound;                      // constant --> ( microsecond / cantimeter ) 
    Serial.println( constant, 4 );
       
    digitalWrite( trig, LOW );                         // sensor is passive 
    delayMicroseconds(5); 
    digitalWrite( trig, HIGH );                        // generate soundwave and activated sensor
    delayMicroseconds(5);
    digitalWrite( trig, LOW );                         // sensor is passive

    int timer = pulseIn( echo, HIGH );
    float distance = ( timer/2 ) / constant;           // constant = 29.1 --> microsecond / cantimeter 

    Serial.print( "Distance = " );
    Serial.println( distance, 4 );
  
    delay(2000);
}
