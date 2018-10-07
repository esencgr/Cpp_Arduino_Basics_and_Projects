/*
   Parametre alan ve değer döndürmeyen fonksiyonlar 
   Fonksiyonlar -3   /  Kod 1
   
*/
const int led = 7; // led pini tanıtıldı

int tur_sayisi; // tur sayisi isimli değişke tanımlandı

void fonksiyon3(int a) // fonksiyon3 isimli fonksiyon
{
  for (int i = 0; i < a ; i++)
  {
    digitalWrite(led , HIGH);
    delay(100);
    digitalWrite(led ,  LOW);
    delay(100);
  }
}

void setup()
{
  Serial.begin(9600); // seri haberleşme başladı
}

void loop()
{
  Serial.println("Algoritma calismaya basliyor");
  delay(2500);
  tur_sayisi = 10; // tur sayisi değişkenine 10 değeri atıldı
  fonksiyon3(tur_sayisi); // tur sayisi değişkeni ile fonksiyon çağırıldı
  Serial.println("Algoritma Bitti");
  while (1);
}

