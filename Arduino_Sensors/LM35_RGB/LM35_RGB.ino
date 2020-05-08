const int r = 11, g = 10, b = 9;
const int lm = A1;
float x, value = 255; 
void setup(){
    Serial.begin( 9600 );
}

float map_f ( float temp, float x, float y, float a, float b ){
    float st = ( b - a ) / ( y - x ); 
    st /= 2;
    return ( temp - x ) * st;
}

void loop(){
  
    float volt = analogRead( lm );  // voltage in A0
    volt = ( volt / 1023 ) * 5000;  // mV unit voltage + = * 4.8828125 
    float temp = volt / 10;         // Convert volt value to temperature. Each 10 mV is 1 C degree
    Serial.println( temp );
    
    float ch_red = map_f( temp, 25, 30, 0, 255 );
    float ch_green = map_f( temp, 20, 25, 0, 255 );
    float ch_blue = map_f( temp, 15, 20, 0, 255 );
    
    if( temp > 25.00 ){
        analogWrite( r, 255 - ch_red );
        analogWrite( g, 255 - 0 );        
        analogWrite( b, 255 - 0 ); 
        Serial.println( ch_red );
    }
    else if( temp >= 20 && temp <= 25 ){
        analogWrite( r, 255 - 0 );
        analogWrite( g, 255 - ch_green );        
        analogWrite( b, 255 - 0 );   
        Serial.println( ch_green );
    }
    else{
        analogWrite( r, 255 - 0 );
        analogWrite( g, 255 - 0 );        
        analogWrite( b, 255 - ch_blue  );   
        Serial.println( ch_blue );
    }
    
    Serial.println(  );
    delay( 1000 );
}
