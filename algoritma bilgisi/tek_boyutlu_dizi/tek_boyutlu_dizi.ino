/*
   
   Tek boyutlu diziler
   
*/
int ogrenciler[10] = {15, 20, 30, 05, 60, 02, 03, 01, 25, 15};
int y;
char klavye[5] = {'a', 'b', 'c', 'd', 'f'};
char fare = 't';

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  klavye[1] = fare;
  y = ogrenciler[0];
  ogrenciler [8] = 100;
  Serial.println("9 cu ogrenciye atanan not 100 ");
  Serial.println(ogrenciler[8]);
  delay(1000);
  Serial.println("y degiskenine atanan not 15");
  Serial.println(y);
  delay(1000);
  Serial.println("klavye dizisinin 0 cu degeri");
  Serial.println(klavye[0]);
  delay(1000);
  for (int i = 0 ; i < 10 ; i++)
  {
    Serial.print("ogrenci = ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.println(ogrenciler[i]);
    delay(500);
  }
  while (1);
}
