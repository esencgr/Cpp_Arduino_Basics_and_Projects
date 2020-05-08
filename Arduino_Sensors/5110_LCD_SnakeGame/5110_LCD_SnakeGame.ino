#include <LCD5110_Basic.h> // 48-84

LCD5110 lcd( 8, 9, 10, 11, 12 ); 

extern uint8_t SmallFont[];
const int x = A0, y = A1;
int x_val, y_val, dist_x = 0, dist_y = 0, x_dist, r_x, r_y , nrx; 
String s = "*", obj;
int l, len;

int rand_func( int num, int space ){
    int x = random( num );
    if( x % space == 0 )
       return x;
    else rand_func( num, space );
} 

String reverse( String t , String n ){
    l = t.length();
    for( int i=l-1; i>=0; i-- )
        n += t[i];    
    return n;
}

void setup(){
    Serial.begin(9600);
    lcd.InitLCD();
    lcd.setFont( SmallFont );
    randomSeed( analogRead(0) );
    r_x = rand_func( 80, 4 );
    r_y = rand_func( 48, 8 );
}

void loop(){
    x_val = analogRead( x );
    y_val = analogRead( y );      
    x_val = map( x_val, 170, 1023, 0, 20);
    y_val = map( y_val, 170, 1023, 0, 6);
    
    if( x_val > 10 ){  
        dist_x += 4;
        if( dist_x >= 80 )
            dist_x = 0;  
    }
    else if( x_val < 10 ){
        dist_x -= 4 ;
        if( dist_x < 0 )
            dist_x = 80 + dist_x; 
    }    
    if( y_val > 3 ){  
        dist_y += 8;
        if( dist_y >= 48 )
            dist_y = 0;  
    }
    else if( y_val < 3 ){
        dist_y -= 8;
        if( dist_y < 0 )
            dist_y = 48 + dist_y; 
    }       
    
    x_dist = LEFT + dist_x;
    lcd.print( "*", r_x, r_y );
    
    if( x_val > 10 ){
        Serial.println( "sağ" );
        Serial.print( "x_dist : " );
        Serial.println( x_dist );
        Serial.print( "R_x : " );
        Serial.println( r_x );
        Serial.print( "nrx : " );
        Serial.println( nrx );
        Serial.println();
        if( x_dist ==  r_x - (4*(len)) && dist_y == r_y ){
           s += "*";
           r_x = rand_func( 80, 4 ) ;
           r_y = rand_func( 48, 8 );
           lcd.print( "*", r_x, r_y );
        }
    }
    else if( x_val < 10 ){
        Serial.println( "sol" );
        Serial.print( "x_dist : " );
        Serial.println( x_dist );
        Serial.print( "R_x : " );
        Serial.println( r_x );
        Serial.print( "nrx : " );
        Serial.println( nrx );
        Serial.println();
        if( x_dist == r_x && dist_y == r_y ){
           s += "*";
           r_x = rand_func( 80, 4 ) ;
           r_y = rand_func( 48, 8 );
           lcd.print( "*", r_x, r_y );
        }
    }
    lcd.print( s , x_dist , dist_y ); 
   
    len = s.length();
    if( len > 10 )
        s = "***";
    
    delay( 300 );
    lcd.clrScr();
}
