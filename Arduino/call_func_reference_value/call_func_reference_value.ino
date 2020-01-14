int sum_value( int n1, int n2 ){
    int sum = n1 + n2;
    return sum ;
}

void sum_reference( int n1, int n2, int &sum ){
    sum = n1 + n2 ;
}

void setup(){
    Serial.begin( 9600 );
}

void loop(){
    int s = 0;
    for( int i=0; i<10; i++ ){
        s = sum_value( i,10 );
        Serial.println( s );
    }
    for( int i=0; i<10; i++ ){
        sum_reference( i, 10, s );
        Serial.println(s);
    }    
    while(1);


}
