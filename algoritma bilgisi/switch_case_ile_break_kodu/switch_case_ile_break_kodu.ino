int durum;
int b = 1;

void setup()
{
  pinMode(8, INPUT);
  Serial.begin(9600);
}
void loop()
{
  switch (b)
  {
    case 1:
      Serial.println("ilk case degeri calisti");
      break;
    case 2:
      Serial.println("ikinci case degeri calisti");
      break;
  }
  Serial.println("donguden cikildi");
  delay(500);
}
