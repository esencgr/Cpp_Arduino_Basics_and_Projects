 #include <LCD5110_Basic.h>
LCD5110 lcd( 8, 9, 10, 11, 12 ); //

extern uint8_t SmallFont[];      // extern harici bir değişken tanımlaması demek uint 8 == unsigned char 
extern uint8_t MediumNumbers[];  // ancak extern tanımlayıcı ile uint 8 daha stabil çalışıyor.// '-' , '.'
extern uint8_t BigNumbers[];  // '-' , '.'

void setup(){
    lcd.InitLCD();
}

void loop(){
    
    lcd.setFont( SmallFont );
    String s = { "Hello" };
    lcd.print( s, CENTER, 0);
    delay( 1000 );
    lcd.clrScr();   
    lcd.setFont( SmallFont );
    String k = { "World" };
    lcd.print( k, CENTER, 0);
    delay( 1000 );
    lcd.clrScr();
}
