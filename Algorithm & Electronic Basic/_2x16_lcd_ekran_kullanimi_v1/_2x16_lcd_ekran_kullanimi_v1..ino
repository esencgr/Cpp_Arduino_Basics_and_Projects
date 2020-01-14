#include<LiquidCrystal.h>

//LiquidCrystal lcd (rs,e,d4,d5,d6,d7); //rw pini toprakta ise devrede tanıtmaya gerek yok 

LiquidCrystal lcd (8,7,6,5,4,3); //lcd nesnesini oluşturmuş oluyoruz..
void setup() 
{
lcd.begin(16,2); // önce sütun(karakter) sonra satır 
lcd.print ("KEYIFLI PROJE");
delay (500);
}

void loop() 
{
}
