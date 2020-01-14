int durum; // durum adlı değişken tanımladn

void setup()
{
  pinMode(8, INPUT); // 8. pin input yapıldı
  Serial.begin(9600); // seri haberleşme başladı
}
void loop()
{
  for (int b = 0; b < 20 ; b++) // for döngüsü 0 dan 19 a kadar dönecek
  {
    Serial.println(b); // b değerini ekrana bas
    delay(500); // 500 ms bekle
    durum = digitalRead(8); // durum adlı değişkene 8. pinden gelen sonucu ata
    if (durum == HIGH) // durum hıgh ise
    {
      break; // döngüden çık
    }
  }
  Serial.println("Donguden cikildi"); // ekrana döngüden çıkıldı yaz
}

