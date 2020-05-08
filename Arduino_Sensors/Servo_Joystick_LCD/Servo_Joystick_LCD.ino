#include <Servo.h>
#include <LiquidCrystal.h>
Servo sg1, sg2;
const int pot=A0;
LiquidCrystal lcd( 12, 11, 5, 4, 3, 2 );

const byte x = A0, y = A1;
int x_state, y_state, pot_st;
void setup(){
  sg1.attach( 9 );
  sg2.attach( 10 );
  lcd.begin( 16, 2 );
}

void loop(){ 
  x_state = analogRead( x );
  y_state = analogRead( y );
  x_state = map( x_state, 0, 1023, 0, 180);
  y_state = map( y_state, 0 , 1023, 0, 180 );
  pot_st = analogRead( pot );
  Serial.println( pot_st );
  

  sg1.write( x_state );
  sg2.write( y_state );

  lcd.home();
  lcd.print( "1. motor = " );
  lcd.print( x_state );
  
  lcd.setCursor( 0, 1 );
  lcd.print( "2. motor = " );
  lcd.print( y_state );
  
  delay( 100 );
  lcd.clear();


} 
