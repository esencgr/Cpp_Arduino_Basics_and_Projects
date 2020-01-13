const int buton = 2; /* Butonun bağlı olduğu pin */
const int led[] = {3,4,5,6,7}; /* Butonun bağlı olduğu pin */
int sayac = 0; /* butona basılma sayısını tutacak değişken */
int butonDurumu = 0; /* Butonun durumu */  

void setup(){
    pinMode( buton, INPUT );
    for( int i=0; i<=sayac; i++ ){
       pinMode( led[i],OUTPUT );     
    }
    Serial.begin(9600);
}

void loop(){
    butonDurumu = digitalRead(buton);
    
    if (butonDurumu == HIGH) {
      
       delay(10); /* dalgalanmalar için biraz bekleyelim */
       sayac++; /* sayaç = sayaç + 1 yani sayaç değeri bir arttırıldı */
       
       Serial.println(sayac); /* sayaç değerimizi ekrana yazdırıyoruz */
       
       for( int i=0; i<sayac; i++){
           digitalWrite( led[i], HIGH );     
       }
       delay( 100 );
       
       if( sayac == 5 ){
           for( int i=0; i<sayac; i++){
              digitalWrite( led[i], LOW );     
           }
           delay( 100 );
           sayac = 0;
       }

       while(butonDurumu == HIGH){ /* Butona basili olduğu surece bekle */
           butonDurumu = digitalRead(buton); /* Butonun durumunu kontrol et */
       }
       delay(10); /* dalgalanmalar için biraz bekleyelim */
 
    }
}
