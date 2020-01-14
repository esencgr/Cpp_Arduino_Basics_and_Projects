int led   = 4; // Ledin bağlı olduğu pin bilgisi
int buton = 5; // butonun bağlı olduğu pin bilgisi
int butondurumu; // Butonunun basılma bilgisinin kayıt altına alındığı değişten

void setup() 
{
pinMode(led,OUTPUT);  // led pini çıkış pini olarak ayarlandı
pinMode(buton,INPUT); // buton pini giriş pini olarak ayarlandı 
}

void loop() 
{
butondurumu=digitalRead(buton); // buton okundu, durum bilgisi değişkene kaydedildi
if( butondurumu == HIGH)        // Eğer butondurmu HIGH ise ( bu bağlantıya göre yani butona basılmışsa) 
digitalWrite(led,HIGH);         // Ledi yak ( led pinini HIGH yap)
else                            // Eğer butona basılmamışsa 
digitalWrite(led,LOW);          // Ledi söndür ( led pinini LOW yap)
}

