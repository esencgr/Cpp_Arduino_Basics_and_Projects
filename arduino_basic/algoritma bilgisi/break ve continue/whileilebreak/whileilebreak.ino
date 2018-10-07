int durum;
int b = 0;
void setup()
{
  pinMode(8, INPUT);
  Serial.begin(9600);
}
void loop()
{
  while (1)
  {
    b++;
    Serial.println(b);
    delay(500);
    durum = digitalRead(8);
    if ( b == 10)
    {
      break;
    }

  }
  Serial.println("donguden cikildi");
}

