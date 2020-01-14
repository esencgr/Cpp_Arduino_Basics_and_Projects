// bit( n ) =  2^n;
void bit_function(){
    String str;
    for( int bt=0; bt<8; bt++ ){
         str = String( bt ) + ". bit digit value " + bit( bt );
         Serial.println( str );
    }
}

// bitset( x, n ) --> which variable --> n : which bit will be 1 
// bitclear( x, 0 ) --> which variable --> n : n. bit is zero
void bitset_bitclear(){
    byte number = 97;
    
    Serial.print( "decimal number : " );
    Serial.println( number, DEC );
    
    Serial.print( "binary number : " );
    Serial.println( number, BIN );
    
    bitSet( number, 7 );
        
    Serial.print( "decimal new_number : " );
    Serial.println( number, DEC );
    
    Serial.print( "binary new_number : " );
    Serial.println( number, BIN );
        
    bitClear( number, 7 );
        
    Serial.print( "decimal new_number : " );
    Serial.println( number, DEC );
    
    Serial.print( "binary new_number : " );
    Serial.println( number, BIN );
    
    while( 1 );
}
void setup(){
    Serial.begin( 9600 );
}

void loop(){
    //bit_function();
    bitset_bitclear();
}
