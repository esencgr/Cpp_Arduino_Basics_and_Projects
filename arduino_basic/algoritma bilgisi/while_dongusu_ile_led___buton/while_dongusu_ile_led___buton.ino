const int buton = 5 ;
const int led = 4 ;

int durum ; 
void setup() 
{
Serial.begin (9600);
pinMode (buton, INPUT );
pinMode (led ,OUTPUT);
}

void loop() {

durum =digitalRead(buton);

    while (durum == HIGH );
    {
      digitalWrite (led , HIGH);
      delay (50);
      digitalWrite (led , LOW);
      delay (50);
      durum =digitalRead(buton);
    }
 Serial.println("butona basilmiyor..");
 delay (500);
}
