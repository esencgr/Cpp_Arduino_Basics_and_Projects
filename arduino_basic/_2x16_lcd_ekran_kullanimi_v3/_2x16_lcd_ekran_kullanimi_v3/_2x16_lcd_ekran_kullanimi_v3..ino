#include<LiquidCrystal.h>

//LiquidCrystal lcd (rs,e,d4,d5,d6,d7); //rw pini toprakta ise devrede tanıtmaya gerek yok 

LiquidCrystal lcd (8,7,6,5,4,3); //lcd nesnesini oluşturmuş oluyoruz..
void setup() 
{
lcd.begin(16,2); // önce sütun(karakter) sonra satır 

}

void loop() 
{
  /*
  lcd.print ("*");
  for (int a=1 ; a<100 ; a++)
    {
      lcd.scrollDisplayRight();
      delay (500);
    }
  */  
  /*
      lcd.print ("*");   // bu durumda önceki yıldız silinmeden yanına eklenecek 
      lcd.scrollDisplayRight();
      delay (500);
   */ 
     lcd.setCursor (1,15); // alt ve en sağdaki karakterden başlar 
     lcd.print ("*");
  for (int a=1 ; a<100 ; a++)
    {
      lcd.scrollDisplayLeft(); // sağdan sola doğru basmamızı sağlar
      delay (500);
    }

}
