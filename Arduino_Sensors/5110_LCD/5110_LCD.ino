 #include <LCD5110_Basic.h>
LCD5110 lcd( 8, 9, 10, 11, 12 ); //

extern uint8_t SmallFont[];      // extern harici bir değişken tanımlaması demek uint 8 == unsigned char 
extern uint8_t MediumNumbers[];  // ancak extern tanımlayıcı ile uint 8 daha stabil çalışıyor.// '-' , '.'
extern uint8_t BigNumbers[];  // '-' , '.'

void setup(){
    lcd.InitLCD();
}

void loop(){
    
    // lcd.print( "xxx", 50, 0 ) -> 50. piksel başlangıç
    // (LEFT - RIGHT - CENTER)( 0->1. satır ||  7->2.satır ..15 - 23 - 31 - 39 )
  
    lcd.setFont( SmallFont );
    String s = { "SmallFonts" };
    lcd.print( s, CENTER, 0);
    //lcd.print( "CGR", LEFT, 8 );  
    
    // lcd.print( text or number, x_axes , y_axes );
    // lcd.printNumI( number, x_axes, y_axes, digit_number, --111 );
    // lcd.printNumF( number, float_digit_num,, x_axes, y_axes, ',', digit_number, '-'); -> ---10,5 . yerine ,

    lcd.setFont( SmallFont );
    lcd.printNumI( 867, CENTER, 8, 5, '-');  // "10"
    lcd.printNumI( 10, CENTER, 16, 5, '_' ); // I -> integer 
    lcd.printNumF( -10.5, 1, CENTER, 24, '.', 7, '_' );
    lcd.clrScr();
}
