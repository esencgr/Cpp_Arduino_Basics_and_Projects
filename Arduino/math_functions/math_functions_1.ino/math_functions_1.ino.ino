void tr_90_90(){
    for( int bev=-90; bev<=90; bev++ ){
         float rad = bev * ( PI/180 ); 
         //float rad = bev * DEG_TO_RAD;
         
         Serial.print( " bevel = " );
         Serial.print( bev );
         
         Serial.print( "  sin = " );
         Serial.print( sin(rad),4 );
                  
         Serial.print( "  cos = " );
         Serial.println( cos(rad),4 );
    }
}

void floor_ceil(){
    for( float num=-1.0; num<1; num+=0.2 ){
         Serial.print( " num = " );
         Serial.print( num );
         
         Serial.print( " floor = " );
         Serial.print( floor(num) );
                  
         Serial.print( " ceil = " );
         Serial.println( ceil(num) );
    }
    while(1);
}


void setup(){
    Serial.begin( 9600 );
}

void loop(){
    //tr_90_90();
    floor_ceil();
}
