 #include <LCD5110_Basic.h>
 
LCD5110 lcd( 8, 9, 10, 11, 12 ); //
int sec = 0, minute = 0, hour = 0; 
unsigned long timer_now, timer_past;
bool state = false;

extern uint8_t SmallFont[];      // extern harici bir değişken tanımlaması demek uint 8 == unsigned char 
extern uint8_t MediumNumbers[];  // ancak extern tanımlayıcı ile uint 8 daha stabil çalışıyor.// '-' , '.'
extern uint8_t BigNumbers[];  // '-' , '.'

void setup(){
    lcd.InitLCD();
    lcd.setFont( SmallFont );
    Serial.begin( 9600 );
}

void loop(){
    timer_now = millis();   // --> milliseconds unit    
    if( timer_now - timer_past >= 1000 ){
        if( state == false  ){
            lcd.print( ":", LEFT+32, 16 );     
            lcd.print( ":", LEFT+49, 16 ); 
            state = true;
        }
        else{
            lcd.clrScr();
            state = false;
        }
        timer_past = timer_now;
    }
    
    lcd.print( "CLOCK", CENTER, 0 );
    lcd.printNumI( hour, LEFT+20, 16, 2, '0' ); 
    lcd.printNumI( minute, LEFT+37, 16, 2, '0' ); 
    lcd.printNumI( sec, LEFT+54, 16, 2, '0' ); 
    delay( 1000 );
    sec++;
    if( sec == 59 ){
        sec = 0;
        minute++;
        if( minute == 59 ){
            minute = 0;
            hour++;
        }
    }
}
