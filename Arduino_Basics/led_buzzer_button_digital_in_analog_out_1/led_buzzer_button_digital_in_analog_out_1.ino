const int led_pin = 3; //pinler atandı
const int buton_pin = 2;
const int buzzer_pin = 5;

int buton_durum = 0; //butonun durumunu saklayacak olan değişken

void led(){ // değer döndürmeyen parametre almayan "basla" fonskiyonu
  
    for( int i=0; i<=250; i+=10 ){
       analogWrite(led_pin, i); // ledi yak
       Serial.println( i );
       delay(200); //bekle 
         
    }
    for( int i=250; i>=0; i-=10 ){
       analogWrite(led_pin, i); // ledi yak
       Serial.println( i );
       delay(200); //bekle    
  }
  
}

void buzzer(){ // değer döndürmeyen parametre almayan "baslama" fonskiyonu

    for( int i=0; i<=75; i++ ){
        analogWrite(buzzer_pin, i++); // ledi yak
        Serial.println( i );
        delay(100); //bekle    
    }
    for( int i=75; i>=0; i-- ){
        analogWrite(buzzer_pin, i); // ledi yak
        Serial.println( i );
        delay(100); //bekle    
    }
  
}


void setup(){
    Serial.begin( 9600 );
    pinMode(led_pin , OUTPUT); // led pini çıkış atandı
    pinMode(buton_pin, INPUT); // bton pini giriş atandı
    pinMode(buzzer_pin, OUTPUT); // buzzer pini çıkış atandı
}

void loop(){
  
    buton_durum = digitalRead( buton_pin );
    if( buton_durum == HIGH ){
       led(); // basla adlı fonksiyonu çağır
       buzzer();// baslama adlı fonksiyonu çağır
    }
    
}
