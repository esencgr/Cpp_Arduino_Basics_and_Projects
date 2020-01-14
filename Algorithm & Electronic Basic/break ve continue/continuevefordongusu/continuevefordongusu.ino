void setup()
{
  Serial.begin(9600); 
}
void loop()
{
  for (int a = 0; a < 20; a++)
  {
    if (a == 6)
    {
      continue;   
    }
    Serial.println(a);
    delay(500);
  }
}

