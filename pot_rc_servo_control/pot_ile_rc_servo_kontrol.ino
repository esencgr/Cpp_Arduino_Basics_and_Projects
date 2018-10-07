
/* Potansiyometre İle Servo Motor Kontrolü*/
#include<Servo.h>

Servo sg90;

const byte pot_pini = A0;

int pot_deger;

void setup()
{
  Serial.begin(9600);
  sg90.attach(3);
}

void loop()
{

  pot_deger = analogRead(pot_pini);
  int yeni_deger = map(pot_deger , 0, 1023, 0, 180);
  sg90.write(yeni_deger);
  Serial.print("Aci Degeri = ");
  Serial.println(yeni_deger);
  delay(15);
}
