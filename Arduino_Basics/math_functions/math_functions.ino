void pow_0_10(){
    for( int base=0; base<=10; base++ ){
         int s = pow( base, 2 ); 
         Serial.println( s );
         Serial.println( );
    }
}

void sqrt_0_10(){
    for( int base=0; base<=21; base++ ){
         float k = sqrt( base ); 
         Serial.println( k );
         Serial.println( );
    }
}

float map_f( float value, float x, float y, float a, float b ){
    float step_v = ( b-a ) /( y-x );
    return value * step_v;  
}

void rule(){
    for( int i=-1000; i<=1000; i+=100 ){
         Serial.print( " num = " );
         Serial.print( i );
         
         Serial.print( " max = " );
         Serial.print( max(i,100) );
         
         Serial.print( " min = " );
         Serial.print( min(i,100) );
                  
         Serial.print( " con = " );
         Serial.println( constrain(i,500,800) );
    }
    while(1);
}


void setup(){
    Serial.begin( 9600 );
}

void loop(){
    //pow_0_10();
    //sqrt_0_10();
    rule();
}
