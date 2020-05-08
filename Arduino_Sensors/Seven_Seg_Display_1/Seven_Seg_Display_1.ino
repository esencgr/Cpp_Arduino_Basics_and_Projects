#include <SevenSeg.h>

/* gostergenin LED pinleri sirasi ile tanimlaniyor */
SevenSeg gosterge(2,3,4,5,6,7,8);

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  /* gösterge kuruluyor */
  const int haneSayisi = 1;
  /* hanerli kontrol edecek transistörlerin pinleri */
  int haneler[haneSayisi] = { 9 };
    gosterge.setDigitPins(haneSayisi,haneler);

}

unsigned long timer=0;
int i = 0;

void loop()
{
  if( millis()-timer > 1000 ){
    i++;
    timer = millis();
    if( i>9 )
      i=0;
  }
  gosterge.write(i);
}
