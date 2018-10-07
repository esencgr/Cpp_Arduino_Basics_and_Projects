int  a = 0; // a isminde int veri tipinde değişken oluşturuldu, değeri 0.

void setup()
{
  Serial.begin(9600); // Seri haberleşme başladı.
}

void loop()
{
  Serial.println("Loop dongusu basliyor"); // Ekrana yazı yazıldı.
  Serial.println(a); // Ekrana a'nın değeri yazıldı.

  do // döngü başladı
  {
    a = a + 1; // a'yı 1 arrtır.
    Serial.println(a); // a'nın değerini ekrana yaz.
    Serial.println("Dongu Calisiyor"); // Ekrana yazıyı yaz.
  }
  while ( a < 50 ); // while döngüsü
  Serial.println("Donguden Cikildi"); // Ekrana yazıyı yaz.
  Serial.println("Loop dongusu bitti"); // Ekrana yazıyı yaz.
  delay(200); // Bekle.
}
