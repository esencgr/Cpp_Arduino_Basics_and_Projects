const int led_pin = 3; 
const int buton_pin = 2;
const int buzzer_pin = 5;

int buton_durum = 0; 
int counter = 0;

int buton(){
  
    buton_durum = digitalRead( buton_pin );
    
    if( buton_durum == HIGH ){  
        counter += 10;
        if( counter > 50 )
            counter -= 10;
        Serial.println( counter );
        delay( 100 );       
        buton_durum = digitalRead( buton_pin );
    }
    
    return counter;
}

void led( int c ){ 
  
  //for( int i=0; i<=250; i+=10 ){
      analogWrite(led_pin, c);
      delay(100);      
  //}
  //for( int i=250; i>=0; i-=10 ){
      //analogWrite(led_pin, c);
      //delay(100); //bekle    
  //}
  
}

void buzzer(int c ){ // değer döndürmeyen parametre almayan "baslama" fonskiyonu

// for( int i=0; i<=75; i++ ){
      analogWrite(buzzer_pin, c); // ledi yak
      delay(100); //bekle    
// }
//    for( int i=75; i>=0; i-- ){
        //analogWrite(buzzer_pin, c); // ledi yak
        //delay(100); //bekle    
//  }
}


void setup(){
  
  Serial.begin( 9600 );
  pinMode(led_pin , OUTPUT); // led pini çıkış atandı
  pinMode(buton_pin, INPUT); // bton pini giriş atandı
  pinMode(buzzer_pin, OUTPUT); // buzzer pini çıkış atandı
  
}

void loop(){

    led( buton() ); // basla adlı fonksiyonu çağır
    //buzzer( buton() );// baslama adlı fonksiyonu çağır
    //while( 1 );
      
}
