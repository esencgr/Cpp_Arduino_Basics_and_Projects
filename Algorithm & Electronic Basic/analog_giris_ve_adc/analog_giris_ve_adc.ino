const int pot_pini = A0; // potansiyometrenin bağlı olduğu pini sabit olarak tanımladık

int okunan_deger; // okunan değerin saklanacağı değişkeni tanımadık
float voltaj; // hesaplanan voltaj değerinin saklanacağı değişkeni tanımladık

void setup()
{
  Serial.begin(9600);// seri haberleşme başladı
}

void loop()
{
  okunan_deger = analogRead(pot_pini); // potansiyometreden gelen bilgi okundu değişkene kaydedildi
  Serial.print("okunan deger = "); // ekrana okunan değer kelimeleri yazıldı
  Serial.println(okunan_deger); // ekrana okunan değer adlı değişkenin değeri yazıldı
  Serial.print("Voltaj"); // ekrana volaj kelimesi yazıldı
  Serial.println((okunan_deger * 5) / 1023.0); // voltaj değer hesaplanıp ekrana yazıldı
  // dilerseniz voltaj =  (okunan_deger * 5) / 1023.0 ; yapıp daha sonra ekrana voltaj isimli değişkenide basabilirsiniz.
  delay(250);
}

