int durum;
int a;

void setup()
{
  Serial.begin(9600);
  pinMode(8 , INPUT);
}
void loop()
{
  while (1)
  {
    a++;
    durum = digitalRead(8);
    if ( durum == HIGH)
    {
      delay(200);
      continue;
    }
    Serial.println(a);
    delay(250);
  }
}
