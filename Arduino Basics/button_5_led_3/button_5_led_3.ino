const int buton[ 5 ] = { 2,3,4,5,6 };
const int led[ 3 ] = { 8,9,10 };

void setup(){
    for( int i=0; i<=2; i++ )
        pinMode( led[ i ], OUTPUT );
        
    for( int b=0; b<=4; b++ )
        pinMode( buton[ b ], INPUT );  

    Serial.begin( 9600 );
}

void loop(){
  
    int buton_state[ 5 ];
  
    for( int b=0; b<=4; b++ )
        buton_state[ b ] = digitalRead( buton[ b ] );

    if( buton_state[ 0 ] == 1 ){
        digitalWrite( led[ 0 ], HIGH );
        Serial.println( "led1 on." );
    }
            
    else if( buton_state[ 1 ] == 1 ){
        digitalWrite( led[ 0 ], HIGH );
        digitalWrite( led[ 1 ], HIGH );
        Serial.println( "led1 - led2 on." );
    }
            
    else if( buton_state[ 2 ] == 1 ){
        for( int l=0; l<=2; l++ ){
            digitalWrite( led[ l ], HIGH );
        }
        Serial.println( "led1 - led2 - led3 on." );
    }     
            
    else if( buton_state[ 3 ] == 1 ){
        for( int l=0; l<=2; l++ ){
            digitalWrite( led[ l ], HIGH );
            delay( 250 );
            digitalWrite( led[ l ], LOW );   
            delay( 250 );       
        }
    }   
     
    else if( buton_state[ 4 ] == 1 ){
        for( int l=0; l<=2; l++ ){
            digitalWrite( led[ l ], HIGH );
        }
        delay( 250 );
        for( int l=0; l<=2; l++ ){
            digitalWrite( led[ l ], LOW );   
        }    
        delay( 250 );
    }    
    
    else
        for( int l=0; l<=2; l++ )
            digitalWrite( led[ l ], LOW );      
            
}
