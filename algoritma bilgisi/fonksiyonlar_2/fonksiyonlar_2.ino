/*
   Parametre almayan değer döndüren  fonksiyonlar
   Fonksiyonlar-2

*/
const int buton1 = 2;
const int buton2 = 3;
const int buton3 = 4;
const int led = 7;

int  arti ;
int  eksi ;
int durum ;
int sayac;
int tur_sayisi;

int fonksiyon2()
{
  durum = digitalRead(buton3);
  while (durum == HIGH)
  {
    arti = digitalRead(buton1);
    eksi = digitalRead(buton2);
    if (arti == HIGH)
    {
      sayac++;
      Serial.println("sayac = ");
      Serial.println(sayac);
      if (arti == HIGH)
      {
        while (1)
        {
          arti = digitalRead(buton1);
          if (arti == LOW)
            break;
        }
      }
    }
    else if (eksi == HIGH)
    {
      sayac--;
      Serial.println("sayac = ");
      Serial.println(sayac);
      if (eksi == HIGH)
      {
        while (1)
        {
          eksi = digitalRead(buton2);
          if (eksi == LOW)
            break;
        }
        durum = digitalRead(buton3);
      }
      return sayac;
    }
  }
}
void setup()
{
  pinMode(buton1 ,  INPUT);
  pinMode(buton2 ,  INPUT);
  pinMode(buton3 ,  INPUT);
  pinMode(led    , OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  tur_sayisi = fonksiyon2();

  for (int i = 0; i < tur_sayisi ; i++)
  {
    digitalWrite(led , HIGH);
    delay(100);
    digitalWrite(led ,  LOW);
    delay(100);
  }
  while (1)
  {
    durum = digitalRead(buton3);
    if (durum == HIGH)
      break;
  }
}

