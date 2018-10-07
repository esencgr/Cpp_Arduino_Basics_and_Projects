#include<Servo.h>
Servo sg90;
const byte buton = 4;
const byte buzzer = 7;
const byte echo = 2;
const byte trig = 3;
const byte led1 = 8;
const byte led2 = 9;
const byte led3 = 10;
const byte led4 = 11;
const byte led5 = 12;
const byte pot_pini = A0;
int pot_deger = 0;
int pot_deger_ilk = 0;
int sure = 0;
int mesafe = 0;
int alarm_mesafesi = 0;
int pos = 0;
void setup()
{
  sg90.attach(5);
  sg90.write(90);
  pinMode(buton , INPUT);
  pinMode(buzzer , OUTPUT);
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);
  pinMode(led4 , OUTPUT);
  pinMode(led5 , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(trig , OUTPUT);
  Serial.begin(9600);

  pot_deger_ilk = analogRead(pot_pini);
  while (1)
  {
    for (int i = 8; i < 13; i++)
    {
      digitalWrite(i, 1);
      delay(50);
      digitalWrite(i, 0);
    }
    pot_deger = analogRead(pot_pini);
    if (pot_deger_ilk > pot_deger + 10 || pot_deger_ilk < pot_deger - 10)
      break;
  }
  while (1)
  {
    pot_deger = analogRead(pot_pini);
    pot_deger = map(pot_deger , 100 , 900, 1, 5);
    if (pot_deger == 1)
    {
      alarm_mesafesi = 10;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 0);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
      digitalWrite(led5 , 0);
    }
    else if (pot_deger == 2)
    {
      alarm_mesafesi = 20;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
      digitalWrite(led5 , 0);
    }
    else if (pot_deger == 3)
    {
      alarm_mesafesi = 30;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 0);
      digitalWrite(led5 , 0);
    }
    else if (pot_deger == 4)
    {
      alarm_mesafesi = 40;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
      digitalWrite(led5 , 0);
    }
    else if (pot_deger == 5)
    {
      alarm_mesafesi = 50;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
      digitalWrite(led5 , 1);
    }

    if (digitalRead(buton) == 1)
      break;
  }
}

void loop()
{
  for (pos = 0; pos <= 180; pos++)
  {
    sg90.write(pos);
    delay(15);
    mesafe = mesafe_olc();
    if (mesafe <= alarm_mesafesi)
    {
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
      digitalWrite(led5 , 1);
      digitalWrite(buzzer , 1);
    }
    if (digitalRead(buton) == 1)
    {
      digitalWrite(led1 , 0);
      digitalWrite(led2 , 0);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
      digitalWrite(led5 , 0);
      digitalWrite(buzzer , 0);
    }
  }
  for (pos = 180; pos >= 0; pos--)
  {
    sg90.write(pos);
    delay(15);
    mesafe = mesafe_olc();
    if (mesafe <= alarm_mesafesi)
    {
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
      digitalWrite(led5 , 1);
      digitalWrite(buzzer , 1);
    }
    if (digitalRead(buton) == 1)
    {
      digitalWrite(led1 , 0);
      digitalWrite(led2 , 0);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
      digitalWrite(led5 , 0);
      digitalWrite(buzzer , 0);
    }
  }
}
int mesafe_olc()
{
  digitalWrite(trig , HIGH);
  delay(1);
  digitalWrite(trig , LOW);
  sure = pulseIn(echo , HIGH);
  mesafe = (sure / 2) / 28.5;
  return mesafe;
}

