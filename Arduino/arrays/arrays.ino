int array_1[ 5 ] = { 1, 2, 3, 4, 5 };
int array_2[ 2 ][ 5 ] = {{ 1, 2, 3, 4, 5 }, 
                         { 9, 8, 7, 6, 0 }};

void setup(){
    Serial.begin( 9600 );
}

void loop(){ 
    Serial.println( "array 1" );
    for( int i=0; i<5; i++ ){
        Serial.print( array_1[ i ] );
        Serial.print( "  " );  
    }
    
    Serial.println();
    Serial.println();
    
    Serial.println( "array 2" );
    for( int r=0; r<2; r++ ){
        for( int c=0; c<5; c++ ){
            Serial.print( array_2[ r ][ c ] );
            Serial.print( "  " );  
        }
        Serial.println();
    }
    
    Serial.println();
    Serial.println();
    
    Serial.println( "array 2 -> 1st row" );
    for( int i=0; i<5; i++ ){
        Serial.print( array_2[ 0 ][ i ] );
        Serial.print( "  " );  
    }
    
    Serial.println();
    Serial.println();
    
    Serial.println( "array 2 -> 2nd col" );
    for( int i=0; i<2; i++ ){
        Serial.println( array_2[ i ][ 1 ] );
    }
   
    while( 1 );  
}
