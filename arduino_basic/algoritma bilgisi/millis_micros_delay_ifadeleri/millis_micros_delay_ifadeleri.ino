/*

   millis kullanımı
   
*/
const int led = 3;
unsigned long SimdikiZaman = 0;
unsigned long OncekiZaman = 0;
int aralik = 1000;

boolean durum = HIGH;
void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  SimdikiZaman = millis();
  if  (SimdikiZaman - OncekiZaman >= aralik)
  {
    OncekiZaman = SimdikiZaman;
    if  (durum == HIGH)
      durum = LOW;
    else if  ( durum == LOW)
      durum = HIGH;
    digitalWrite(led , durum);
  }
}


