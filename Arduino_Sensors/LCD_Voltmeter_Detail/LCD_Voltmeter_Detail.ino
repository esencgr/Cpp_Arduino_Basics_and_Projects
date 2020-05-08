#include <LiquidCrystal.h>
const int t = 1000;
byte digit[6][8]={{B00000, B00000, B00000, B00000, B00000, B00000, B00000, B00000},
                  {B00000, B00000, B00000, B00000, B00000, B00000, B00000, B11111},
                  {B00000, B00000, B00000, B00000, B00000, B00000, B11111, B11111},
                  {B00000, B00000, B00000, B00000, B00000, B11111, B11111, B11111},
                  {B00000, B00000, B00000, B00000, B11111, B11111, B11111, B11111},
                  {B00000, B00000, B00000, B11111, B11111, B11111, B11111, B11111}};
                  
LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );    // Rs E d4 d5 d6 d7 

void screen( int row, int char_no ){
    lcd.setCursor( 0, row ); 
    lcd.write( byte(char_no) );  
}

float map_f( float value, float x, float y, float a, float b ){
    float step_v = ( b-a ) /( y-x );
    return value * step_v;  
}

void change_digit( byte d[][8], int p ){

        for( int b=0; b<p; b++ ) 
            d[0][b] = ( d[0][b] | B11111 );
   
    Serial.print( "Binary : " );
    Serial.println( d[0][8], BIN );
}

void setup(){
    Serial.begin( 9600 );
    lcd.begin( 16, 2 );                    // 2 x 16  col x row
    
    //for( int i=0; i<6; i++ ){
        lcd.createChar( 0, digit[0] );         // ( character_no, character_name ) 
    //}
}

void loop(){
  
    lcd.clear();
    lcd.home();
    
    float value_float = analogRead( A0 );
    float volt_float = map_f( value_float, 0.0, 1023.0, 0.0, 5.0 );
    Serial.println( volt_float );
    
    int value = analogRead( A0 );    
    //float volt = ( value / 1023.0 ) * 5.0;
    value = map( value, 0, 1023, 0, 5 );
    screen( 0, value );

    
    lcd.setCursor( 1, 0 );
    lcd.print( "  V1 = " );
    lcd.print( volt_float );
    
    delay(t);
}
