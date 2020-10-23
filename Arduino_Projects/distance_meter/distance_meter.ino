#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trig = 9;
const int echo = 8;

int mesafe ;
int sure;

void setup(){
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  lcd.begin(16, 2);
}

void loop(){
  digitalWrite(trig , HIGH);
  delay(1);
  digitalWrite(trig , LOW);
  sure = pulseIn (echo, HIGH);
  mesafe = (sure / 2) / 28.5;

  lcd.home();
  lcd.print("mesafe = ");
  lcd.setCursor(0, 1);
  lcd.print(mesafe);
  lcd.print("cm");
  lcd.clear();
  delay(250);
}
