#include <LCD5110_Basic.h>
LCD5110 lcd( 8, 9, 10, 11, 12 ); 

extern uint8_t SmallFont[];      

void setup(){
    lcd.InitLCD();
    lcd.setContrast( 70 );   // 70 STANDART - 0-126 ARASI DEGER ALABILIR
    lcd.setFont( SmallFont );
}

void loop(){
    lcd.invertText( true );
    lcd.print( "HELLO", CENTER, 0 );
    delay( 2000 );    
    lcd.clrScr();
    delay( 1000 );
 
    lcd.invertText( false );
    lcd.print( "HELLO", CENTER, 8 );
    delay( 2000 );    
    lcd.clrScr();
    delay( 1000 );
    
    lcd.print( "HELLOHELLOHELLO", CENTER, 16 );
    lcd.clrRow( 2, 40, 53 );         // 2. SATIR 40-50 PIXEL ARASI SILER
    //lcd.clrRow( 3 )                // 3. SATIR KOMPLE
    delay( 2000 );
    lcd.clrScr();
    delay( 1000 );

    lcd.print( "SLEEP TIME", CENTER, 24 );
    delay( 1000 );
    lcd.enableSleep();
    delay( 2000 );

    lcd.disableSleep();
    lcd.print( "WAKE UP TIME", CENTER, 24 );
    delay( 2000 );
    lcd.clrScr();
}
