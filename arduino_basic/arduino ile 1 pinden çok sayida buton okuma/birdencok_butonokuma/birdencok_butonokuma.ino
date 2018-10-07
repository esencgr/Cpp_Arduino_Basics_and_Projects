#define buton A0

byte buton_bul(int x)
{
  int buton_numarasi = 0;
  if (x > 950)
    buton_numarasi = 1;
  else if (x > 880 && x < 980)
    buton_numarasi = 2;
  else if (x > 800 && x < 900)
    buton_numarasi = 3;
  else if (x > 750 && x < 820)
    buton_numarasi = 4;
  else if (x > 700 && x < 800)
    buton_numarasi = 5;
  else
    buton_numarasi = 0;

  return buton_numarasi;
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int buton_deger = analogRead(buton);
  Serial.print("okunan_deger = ");
  Serial.println(buton_deger);
  Serial.print("basilan buton = ");
  byte basilan_buton = buton_bul(buton_deger);
  Serial.println(basilan_buton);
  Serial.println("-------------------------");
  delay(500);
}
