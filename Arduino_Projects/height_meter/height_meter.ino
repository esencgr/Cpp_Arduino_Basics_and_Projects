#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int  trig = 6;
const int   echo = 7;
const int kalibButon = 8;
const int olcmeButon  =9;
int sure = 0;
int mesafe = 0;
int ilkmesafe;

void setup() {
  lcd.begin(16, 2);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(kalibButon, INPUT);
  pinMode(olcmeButon, INPUT);
  while (digitalRead(kalibButon) == LOW){
    lcd.setCursor(2, 0);
    lcd.print("KALiBRASYON iCiN");
    lcd.setCursor(2, 1);
    lcd.print(" BUTONA BASINIZ ");
    delay(100);
    if (digitalRead(kalibButon) == HIGH){
      delay(50);
      ilkmesafe = mesafeolc();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("KALiBRASYON");
      lcd.setCursor(0, 1);
      lcd.print("YAPILDI : ");
      lcd.print(ilkmesafe);
      delay(2000);
      lcd.clear();
      break;
    }
  }
}

void loop(){
  if (digitalRead(olcmeButon) == HIGH){
    lcd.setCursor(0, 0);
    lcd.print("BOYUNUZ");
    lcd.setCursor(0, 1);
    int boy = ilkmesafe - mesafeolc();
    lcd.print(boy);
    lcd.setCursor(0, 2);
    delay(2000);
    lcd.clear(); 
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("   OLCUM iCiN   ");
    lcd.setCursor(0, 1);
    lcd.print(" BUTONA BASINIZ ");
    delay(100);
    lcd.clear();
  }
}

int mesafeolc(){
    digitalWrite(trig, HIGH);
    delay(1);
    digitalWrite(trig, LOW);
    sure = pulseIn(echo, HIGH);
    mesafe = (sure / 2) / 27.6;
    return mesafe;
}
