#include<LiquidCrystal.h>

byte xdsurat[8] = {B00000,
                   B01010,
                   B00100,
                   B01010,
                   B00000,
                   B10001,
                   B01110,
                   B00000
                   };
//LiquidCrystal lcd (rs,e,d4,d5,d6,d7); //rw pini toprakta ise devrede tanıtmaya gerek yok

LiquidCrystal lcd (8, 7, 6, 5, 4, 3); //lcd nesnesini oluşturmuş oluyoruz..
void setup()
{
  lcd.createChar(1,xdsurat); //karakterimizi bytelerdan oluşturuyoruz ve 1 değerine atıyoruz
  lcd.begin(16, 2); //önce sütun(karakter) sonra satır

}

void loop()
{
  lcd.home ();
  lcd.write(byte(1));
}
