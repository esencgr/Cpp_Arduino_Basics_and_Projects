int a = 0; // a isimli, int veri tipinde değişken oluşturuldu, ilk değeri 0.

void setup()
{
  Serial.begin(9600); //seri haberleşme başladı.
}
void loop()
{
  Serial.println(a); // serial monitöre a karakteri yazıldı.
  while ( a <= 50) // eğer a değeri 50 küçük ise while çalışsın.
  {
    a = a + 1; // a'yı 1 arttır.
    delay(200); // 200 ms bekle
    Serial.println(a); // a değerini ekrena yaz
    Serial.println("while dongusu calisiyor"); // ekrana "while döngüs calisiyor" yaz.
  }
  Serial.println("DONGUDEN CIKTIK"); // ekrana "donguden cıktık" yaz
  while (1); // sonsuz döngü
}
