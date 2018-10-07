const int arttir = 3; // artirma isini yapan buton 3. pine bağlı
const int azalt  = 4; // azatlma isini yapan buton 4. pine bağlı

const int dongu  = 2; // donguyu ayarlaya swtich 2. pine bağlı

int durum_arttir; // değişken tanımlandı
int durum_azalt ;// değişken tanımlandı
int durum_dongu ;// değişken tanımlandı

int sayac = 0;// değişken tanımlandı ilk değeri 0 verildi

void setup()
{
  pinMode(arttir , INPUT); // arttir butonu giriş pini olarak ayarlandı.
  pinMode(azalt  , INPUT); // arttir butonu giriş pini olarak ayarlandı.
  pinMode(dongu  , INPUT); // arttir butonu giriş pini olarak ayarlandı.

  Serial.println(9600); // seeri haberleşme başladı

}
void loop()
{
  durum_dongu = digitalRead(dongu); // dongu switchini oku durumu durum_dongu ye kaydet
  while (dongu == HIGH) // dongu Hıgh ise while döngüsüne gir
  {
    durum_arttir = digitalRead(arttir); // arttir butonunu oku durumunu durum_arttira kaydet
    durum_azalt  = digitalRead(azalt ); // azalt butonunu oku durumunu durum_azalta kaydet

    if (durum_arttir == HIGH) // eğer durum arttır hıgh ise çalış
    {
      sayac++; // sayacı arttır
      Serial.println("sayac = " ); // ekrana sayac kelimesini yaz
      Serial.println(sayac); // ekrana sayacın değerini yaz
      delay(200); // 200ms bekle
    }
    else if ( durum_azalt == HIGH)
    {
      sayac--; // sayacı azalt
      Serial.println("sayac = " ); // ekrana sayac kelimesini yaz
      Serial.println(sayac); // ekrana sayacın değerini yaz
      delay(200); // 200 ms bekle
    }
    durum_dongu = digitalRead(dongu); // dongu switcini tekrar oku (aksi halde while döngüsü sonsuz döngü olur(
  }
  switch (sayac) // sayaca göre switch kodunu çalıştır
  {
    case 1: // sayaca 1 ise
      Serial.println(" 1. motor calisiyor "); // ekrana cümleyi yaz
      break; // swtich den çık

    case 2: // sayaca 2 ise
      Serial.println("2. motor calisiyor "); // ekrana cümleyi yaz
      break;// swtich den çık

    case 3: // sayaca 3 ise
      Serial.println("3. motor calsiyor"); // ekrana cümleyi yaz
      break;// swtich den çık

    case 4: // sayaca 5 ise
      Serial.println("Tüm motorlar calsiyor"); // ekrana cümleyi yaz
      break;// swtich den çık

    default: // sayaca başka bir değer ise
      Serial.println("yanlis deger girildi "); // ekrana cümleyi yaz
  }
}

