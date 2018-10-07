int ledPin=8;
int butonPin=9;
int butonDurum=0;
void setup(){
  
  pinMode(ledPin,OUTPUT); //led pinimizi çıkıs ayarladık
  pinMode(butonPin,INPUT); // buton pinimizi giriş ayarladık
 
}
void loop(){
  
  butonDurum=digitalRead(butonPin); // dijital olarak okuduk 
  if(butonDurum==HIGH){
 
    digitalWrite(ledPin,HIGH);
 
  }else
  digitalWrite(ledPin,LOW);
 
}
