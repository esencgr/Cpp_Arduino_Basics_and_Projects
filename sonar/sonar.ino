#include<Servo.h>
Servo sg90;
const byte button = 4;
const byte buzzer = 7;
const byte echo = 2;
const byte trig = 3;
const byte led1 = 8;
const byte led2 = 9;
const byte led3 = 10;
const byte led4 = 11;
const byte led5 = 12;
const byte pot = A0;
int pot_val = 0;
int pot_val_frst = 0;
int time = 0;
int distance = 0;
int alarm_distance = 0;
int pos = 0;
void setup()
{
  sg90.attach(5);
  sg90.write(90);
  pinMode(button , INPUT);
  pinMode(buzzer , OUTPUT);
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);
  pinMode(led4 , OUTPUT);
  pinMode(led5 , OUTPUT);
  pinMode(echo , INPUT);
  pinMode(trig , OUTPUT);
  Serial.begin(9600);

  pot_val_frst = analogRead(pot);
  while (1)
  {
    for (int i = 8; i < 13; i++)
    {
      digitalWrite(i, 1);
      delay(50);
      digitalWrite(i, 0);
    }
    pot_val = analogRead(pot);
    if (pot_val_frst > pot_val + 10 || pot_val_frst < pot_val - 10)
      break;
  }
  while (1)
  {
    pot_val = analogRead(pot);
    pot_val = map(pot_val , 100 , 900, 1, 5);
    if (pot_val == 1)
    {
      alarm_distance = 10;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 0);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
      digitalWrite(led5 , 0);
    }
    else if (pot_val == 2)
    {
      alarm_distance = 20;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 0);
      digitalWrite(led4 , 0);
      digitalWrite(led5 , 0);
    }
    else if (pot_val == 3)
    {
      alarm_distance = 30;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 0);
      digitalWrite(led5 , 0);
    }
    else if (pot_val == 4)
    {
      alarm_distance = 40;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
      digitalWrite(led5 , 0);
    }
    else if (pot_val == 5)
    {
      alarm_distance = 50;
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
      digitalWrite(led5 , 1);
    }

    if (digitalRead(button) == 1)
      break;
  }
}

void loop()
{
  for (pos = 0; pos <= 180; pos++)
  {
    sg90.write(pos);
    delay(15);
    distance = distance_olc();
    if (distance <= alarm_distance)
    {
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
      digitalWrite(led5 , 1);
      digitalWrite(buzzer , 1);
    }
    if (digitalRead(button) == 1)
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
    distance = distance_olc();
    if (distance <= alarm_distance)
    {
      digitalWrite(led1 , 1);
      digitalWrite(led2 , 1);
      digitalWrite(led3 , 1);
      digitalWrite(led4 , 1);
      digitalWrite(led5 , 1);
      digitalWrite(buzzer , 1);
    }
    if (digitalRead(button) == 1)
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
int distance_olc()
{
  digitalWrite(trig , HIGH);
  delay(1);
  digitalWrite(trig , LOW);
  time = pulseIn(echo , HIGH);
  distance = (time / 2) / 28.5;
  return distance;
}
