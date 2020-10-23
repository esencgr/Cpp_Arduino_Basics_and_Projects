int a = 0; 

void setup() {
    Serial.begin( 9600 ); 
}

void loop() {
    Serial.println( "loop is start." );
    do{
       Serial.println( a );
       a++;
       Serial.println( "loop is working." );
       delay( 500 );
    }while( a < 10 );
    
    Serial.println( "loop is finished." );
    delay( 1000 );
    //while( 1 );
}
