const int Dugme = 2; /* düğmenin bağlı olduğu pin */
const int LED = 3; /* LEDin bağlı olduğu pin */

int LEDDurumu = 0; /* birinci yöntem için LED durumu */

void setup(){
    pinMode(LED, OUTPUT);            /* LED pini çıkış olarak ayarlandı */
    pinMode(Dugme, INPUT);           /* düğme pini giriş olarak ayarlandı */
}

void loop(){
    
    int dugmeDurumu = digitalRead(Dugme);  /* düğmenin durumu okundu ve değişkene aktarıldı */
   
    if(dugmeDurumu == HIGH){          /* düğmeye basılmış ise */    
        delay(10);                     /* dalgalanmalar için biraz bekleyelim */
        if(LEDDurumu == 0){                /* LED yanmıyorsa */
           digitalWrite(LED, HIGH);       /* LEDi yak */
           LEDDurumu = 1;
        }
        else{                             /* LED yanıyorsa */
           digitalWrite(LED, LOW);        /* LEDi sondur */
           LEDDurumu = 0;  
        }   
          
        while(dugmeDurumu == HIGH){           /* düğmeye basili olduğu surece bekle */
           dugmeDurumu = digitalRead(Dugme); /* düğmenin durumunu kontrol et */
        }
        delay(10);                            /* dalgalanmalar için biraz bekleyelim */
     } 
}
