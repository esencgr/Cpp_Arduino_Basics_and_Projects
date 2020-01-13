const int buton = 2; /* düğmenin bağlı olduğu pin */
const int led = 3; /* LEDin bağlı olduğu pin */

void setup(){
    Serial.begin( 9600 );
    pinMode( led, OUTPUT );            /* LED pini çıkış olarak ayarlandı */
    pinMode( buton, INPUT );           /* düğme pini giriş olarak ayarlandı */
}

void loop(){
    int buton_state = digitalRead( buton ); /* düğmenin durumu */  
    if( buton_state == 1 ){
       digitalWrite( led, 1 );
       Serial.println( "led on." );
       delay( 1000 );   
    }
    else{
        digitalWrite( led, 0 );
        Serial.println( "led off." );
        delay( 1000 );
    }    
}
