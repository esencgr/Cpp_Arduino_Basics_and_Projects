const int button = 2;
int state;
//int number = 10;

void func_0( );
void func_1( int )
void func_2( int );

void setup() {
    Serial.begin( 9600 );
    pinMode( button, INPUT );
}

void loop() {
  
    func_0( );
    func_1( 5 );
    func_2( 10 );
    
    while( 1 );
}

void func_0(){
    for( int i = 1; i <= 10; i++ ){
        Serial.println( i );
        delay( 500 );
        
        state = digitalRead( button );
        if( state == HIGH )
            break;
    }
    
    Serial.println( "END OF LOOP_0.." );
}

void func_1( int no ){
    for( int i = 1; i <= 10; i++ ){
        if( i == no )
            continue;
            
        Serial.println( i );
        delay( 500 );

        state = digitalRead( button );
        if( state == HIGH )
            break;
    }
    
    Serial.println( "END OF LOOP_1.." );
}

void func_2( int number ){
    while( number > 0 ){
       Serial.println( number );
       delay( 500 );  
        
       number --; 
        
       state = digitalRead( button );
       if( state == HIGH )
           break;  
    }
    
    Serial.println( "END OF LOOP_2.." );
}
