float sicaklik, volt;
void setup(){
  Serial.begin(9600); /* Haberleşme başlatıldı */
}

void loop(){
  volt = analogRead(A0); /* A0daki gerilim ölçüldü */
  volt = ( volt / 1023 ) * 5000; /* mV cinsinden gerilim + = * 0.48828125 Ölçülen gerilim sıcaklığa çevrildi */
  sicaklik = volt / 10.0;
  
  Serial.print("SICAKLIK = ");
  Serial.print(sicaklik);
  Serial.println(" C");
  
  delay(500);
}
