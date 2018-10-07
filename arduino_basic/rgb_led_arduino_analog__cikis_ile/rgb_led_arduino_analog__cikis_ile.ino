int i;
const int k_led =11;
const int y_led =10;
const int m_led =9;
void setup() 
{
  for (i=9; i<=11; i++)
  {
    pinMode (i, OUTPUT);
  }
}

void loop() 
{
  analogWrite (k_led , 255-255);// ortak anotlu ledde yakmak istediğine 0(-) gönder 
  analogWrite (y_led , 255-0);     //bu üç satırda kırmızı yanar 
  analogWrite (m_led , 255-0);
  delay (200);
  analogWrite (k_led , 255-0);// ortak anotlu ledde yakmak istediğine 0(-) gönder 
  analogWrite (y_led , 255-255);     //bu üç satırda yeşil yanar 
  analogWrite (m_led , 255-0);
  delay (200);
  analogWrite (k_led , 255-0);// ortak anotlu ledde yakmak istediğine 0(-) gönder 
  analogWrite (y_led , 255-0);     //bu üç satırda mavi yanar 
  analogWrite (m_led , 255-255);
  delay (200);
}
