float sicaklik;

void setup()
{
  Serial.begin(9600); /* Haberleşme başlatıldı */
}

void loop()
{
  sicaklik = analogRead(A0); /* A0daki gerilim ölçüldü */
  sicaklik = sicaklik * 0.48828125;/* Ölçülen gerilim sıcaklığa çevrildi */
  
  Serial.print("SICAKLIK = ");
  Serial.print(sicaklik);
  Serial.println(" C");
  
  delay(500);
}
