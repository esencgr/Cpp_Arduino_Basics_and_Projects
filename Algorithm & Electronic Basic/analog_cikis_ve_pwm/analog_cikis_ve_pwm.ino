const int pot_pini = A0;  // pin atamalarını yaptık
const int buzzer = 11;

int durum = 0;   // pot pininden alınan değeri kaydetmek için değişkenimiz
int cikti = 0;

void setup()
{
  pinMode(buzzer, OUTPUT);   // Buzzer pinini çıkış olarak kullanacağımız için pini çıkış olarak atıyoruz
  Serial.begin(9600);   // Seri haberleşmeyi başlatıyoruz
}

void loop()
{
  durum = analogRead(pot_pini);  // pot pininden gelen verileri burada durum değişkenine kaydettik
  Serial.println(durum);    // kaydedilen veri ekrana yazıldı
  cikti = map (durum , 0, 1023, 0, 255);   // durum değişkeninde olan 0-1023 arası verilen 0-255 arasına uyarlanıp cikti isimli değişkene kaydedildi
  analogWrite(buzzer , cikti );    //cikti değişkenindeki veri buzzera yazıldı.
}



