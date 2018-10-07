void setup()
{
  pinMode(2 , OUTPUT); // pinler output atandı
  pinMode(3 , OUTPUT);
  pinMode(4 , OUTPUT);
  pinMode(5 , OUTPUT);
  pinMode(6 , OUTPUT);
  pinMode(7 , OUTPUT);
}
void loop()
{
  for (int b = 2; b < 8 ; b++) // dor döngüsü şartı
  {
    digitalWrite(b, HIGH); // ilgili ledi yak
    delay(50);
    digitalWrite(b, LOW); // ilgili ledi söndür
  }
}

