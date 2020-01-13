const int led1=9, led2=10, led3=11;
int p1=255, p2=0, p3=0;
int random_p[ 10 ]={ 100, 0, 100, 0, 100, 0, 100, 0, 100, 0 };
void setup(){
    pinMode( led1, OUTPUT );
    pinMode( led2, OUTPUT );
    pinMode( led3, OUTPUT );
}

void loop(){
    
    analogWrite( led1, p1);
    delay( 300 );
    p1-=51;
    if( p1 <= 0 )
       p1 = 255;

    analogWrite( led2, random_p[ p2 ]);
    delay( 300 );
    p2++;
    if( p2 >= 9 )
       p2 = 0;
       
    analogWrite( led3, p3 );
    delay( 300 );
    p3+=51;
    if( p3 >= 255 )
       p3 = 0;
   
}
