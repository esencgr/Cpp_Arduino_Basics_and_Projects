const int x_eksen = A0;
const int y_eksen = A1;
const int buton = 7;

int x_durum;
int y_durum;
int b_durum;

void setup() 
{

Serial.begin (9600);
pinMode(buton , INPUT);

}

void loop() 
{

   x_durum=analogRead(x_eksen);
   y_durum=analogRead(y_eksen);
   b_durum =digitalRead (buton);
   Serial.print ("buton durum=");
   Serial.println(b_durum);
   Serial.print ("x durum=");
   Serial.println(x_durum);
   Serial.print ("y durum=");
   Serial.println(y_durum);
   Serial.println ("********");
   delay(500);

}
