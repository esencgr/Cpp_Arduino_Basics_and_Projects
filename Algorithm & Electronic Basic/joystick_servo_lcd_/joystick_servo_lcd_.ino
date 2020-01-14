#include <Servo.h>
#include <LiquidCrystal.h>
Servo birinci_motor;
Servo ikinci_motor;
LiquidCrystal ekran(13, 12, 11, 10, 9, 8);
const byte x_pini = A0;

const byte y_pini = A1;

int x_durum;
int y_durum;

void setup()
{

  birinci_motor.attach(3);
  ikinci_motor.attach(5);
  ekran.begin(16, 2);
}

void loop()
{ 
  x_durum = analogRead(x_pini);
  y_durum = analogRead(y_pini);
  x_durum = map(x_durum , 0 , 1023, 0, 180);
  y_durum = map(y_durum , 0 , 1023, 0, 180);

  birinci_motor.write(x_durum);
  ikinci_motor.write(y_durum);

  ekran.home();
  ekran.print("1. motor = ");
  ekran.print(x_durum);
  ekran.setCursor(0, 1);
  ekran.print("2. motor = ");
  ekran.print(y_durum);
  delay(50);
  ekran.clear();


}
