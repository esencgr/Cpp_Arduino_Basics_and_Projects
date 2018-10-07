#include<LiquidCrystal.h>

//LiquidCrystal lcd (rs,e,d4,d5,d6,d7); //rw pini toprakta ise devrede tanıtmaya gerek yok 

LiquidCrystal lcd (8,7,6,5,4,3); //lcd nesnesini oluşturmuş oluyoruz..
int a = 6;
char b = 't';
void setup() 
{
//Serial.begin(9600); // 9600 baud rate hızında seri hab başlatıyorduk 

lcd.begin(16,2);
//lcd.print(130208076);
//lcd.print(156,BIN); // Sayının ikilik tabandaki gösterimi 
//lcd.print(156,OCT); // Sayının sekizlik tabandaki gösterimi
//lcd.print(156,HEX); // Sayının onaltılık tabandaki gösterimi
//lcd.print(a);
//lcd.print(b);
}

void loop() 
{  //lcd.cursor(); //lcd imlecini göster 
  //lcd.blink();  //lcd imleci ikiyi gösterir 
  //lcd.setCursor
  lcd.setCursor (0,0); // bu komut ile yazının hangi satır ve sütununda gösterileceği söylenir
   //lcd.setCursor (0,1);// ikinci satırda yazar
  lcd.print("KEYIFLI PROJELER");
  delay (5000);
  lcd.clear (); //her yazdırdığımızda ekranı temizler ve yeniden dönünce yazar 
  lcd.print("LCD KAPANACAK");
  delay (1000);
  lcd.noDisplay();
  delay (1000);
  lcd.display();
  lcd.clear();
  lcd.print("LCD ACILDI");
  delay(5000);
}
