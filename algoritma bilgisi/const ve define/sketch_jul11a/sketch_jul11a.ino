char karakter1 = 'L'; //char veritipinde değişkenler oluşturduk ve her birinde bir harf sakladık.
char karakter2 = 'E';
char karakter3 = 'Z';
char karakter4 = 'Z';
char karakter5 = 'E';
char karakter6 = 'T';
char karakter7 = 'L';
char karakter8 = 'I';

#define Bekleme_suresi 1500 // define olarak bekleme süresi atandı.

void setup()
{
  Serial.begin(9600);// seri haberleşme başladı
}

void loop()
{
  Serial.println(karakter1);// 1. karakter ekrana yazıldı
  delay(Bekleme_suresi); // bekleme_suresi değeri kadar bekledi, kodun kalanıda bu şekilde.
  Serial.println(karakter2);
  delay(Bekleme_suresi);
  Serial.println(karakter3);
  delay(Bekleme_suresi);
  Serial.println(karakter4);
  delay(Bekleme_suresi);
  Serial.println(karakter5);
  delay(Bekleme_suresi);
  Serial.println(karakter6);
  delay(Bekleme_suresi);
  Serial.println(karakter7);
  delay(Bekleme_suresi);
  Serial.println(karakter8);
  delay(Bekleme_suresi);
}

