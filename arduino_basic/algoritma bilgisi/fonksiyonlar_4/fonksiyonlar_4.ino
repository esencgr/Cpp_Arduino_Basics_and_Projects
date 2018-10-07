/*
   parametre alan ve değer döndüren videolar..
   Fonksiyonlar-4
  
*/
int toplam;                               // Sonuçların kayıt edildiği değişkenlerimiz
int cikarma;
float bolme;
int carpma;

int fonksiyonarti( int t, int y)          // Toplama fonksiyonumuz
{
  int z = t + y ;
  return z;
}

int fonksiyoneksi( int k , int l)         // Çıkartma fonksiyonumuz
{
  int m = k - l ;
  return m;
}

int fonksiyoncarpma( int s , int n)     // Çarpma fonksiyonumuz
{
  int w = s * n;
  return w ;
}

float fonksiyonbolme( float s , float g)      // Bölme fonksiyonumuz
{
  float tt = s / g;
  return tt;
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int a = 5;
  int b = 6;

  toplam  = fonksiyonarti(a, b);            // Toplama fonksiyonumuzu çağırdık ve ilgili değişkene kaydettik
  cikarma = fonksiyoneksi(a, b);            // Çıkartma fonksiyonumuzu çağırdık ve ilgili değişkene kaydettik
  carpma = fonksiyoncarpma(a, b);           // Çarpma fonksiyonumuzu çağırdık ve ilgili değişkene kaydettik
  bolme = fonksiyonbolme(a, b);             // bölme fonksiyonumuzu çağırdık ve ilgili değişkene kaydettik

  Serial.print(" toplam = ");               // Seri monitör de görmek için istediğimiz sonuçları yazdırıyoruz
  Serial.println(toplam);
  Serial.print(" cikarma = ");
  Serial.println(cikarma);
  Serial.print(" carpma = ");
  Serial.println(carpma);
  Serial.print(" Bolme = ");
  Serial.println(bolme);
  while (1);                                // Yapılan işlerim sadece bir kere yapılması için "While(1)" ile döngümüzü kilitledik
}

