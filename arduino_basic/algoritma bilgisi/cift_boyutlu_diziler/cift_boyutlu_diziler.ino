int ogrenciler [3][5] = {{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15}}; // burada 3 satır ve 5 sütunlu dizi oluşur..
int satir;
int sutun;

void setup()
{

  Serial.begin(9600);

}

void loop()
{
  for (satir = 0 ; satir <= 2 ; satir++ )
  {

    for (sutun = 0 ; sutun <= 4 ; sutun ++)
    {

      Serial.print (ogrenciler [satir][sutun]);
      Serial.print (" ");

      if (sutun == 4)
        Serial.println(" ");
      
    }

  }
  while (1);
}
