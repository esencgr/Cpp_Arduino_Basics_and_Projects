
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 5, 4, 3, 2);

const int lm35 = A3;

float voltaj_deger = 0;
float sicaklik = 0;
int gelen_veri = 0;

void setup()
{

  lcd.begin (16, 2);                           // önce sutun sonra satır ile lcd aktif ediliyor (2x16)

}

void loop()
{
  gelen_veri = analogRead(lm35);
  voltaj_deger = (gelen_veri / 1023.0) * 5000; // bunun sonucunda mv cinsinden değer elde ediliyor
  sicaklik = voltaj_deger / 10.0;              // lm35 de her 10 mv için 1 santigrat ölçtüğü için bu mv lu değeri 10 a bölerek
                                               // santigrat cinsinden sıcaklık ölçülmüş olur

  lcd.clear(); 
  lcd.home();                                  // bunun diğer yazımı lcd.setCursor(0,0);
  lcd.print("sicaklik =");
  lcd.setCursor(0, 1);                         // lcd nin ilk satırından ikinciye geçtik
  lcd.print(sicaklik);
  lcd.print(" derece");
  delay(1000);

}
