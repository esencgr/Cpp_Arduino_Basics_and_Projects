/*
   parametre alan ve değer döndürmeyen fonksiyonlar 
   Fonksiyonlar -3  /  Kod 2
*/
int a ; // kullanılan değişkenler tanımladı
int b ;
int toplam;
int cikartma;

void topla (int h , int g) // toplama isimli fonksiyon
{
  toplam = h + g ;
}

void cikart (int z , int y) // cikart isimli fonksiyon
{
  cikartma = b - a;
}

void setup()
{
  Serial.begin(9600); // ser haberleşme başladı
}

void loop()
{
  a = 5;
  b = 6;
  topla(a, b); // topla fonksiyonu parametre ile çağırıldı
  Serial.print("toplam = ");
  Serial.println(toplam);
  cikart(b, a); // cikart fonksiyonu parametre ile cağırıldı
  Serial.print("sonuc = ");
  Serial.println(cikartma);
  while (1);// sonsuz döngü ile programı kitledik
}

