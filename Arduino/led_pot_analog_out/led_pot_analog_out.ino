const int pot = A0;
const int led = 9;
int p=0;
int output=0;
void setup()
{
  Serial.begin( 9600 );
  pinMode(led, OUTPUT);

}
void loop(){
  
  p = analogRead( pot );
  Serial.println( p );
  delay( 100 );
  
  output = map( p, 0, 1023, 0, 255 );
  Serial.println( output );
  delay( 100 );
  
  analogWrite(led, output);
  delay(100);
}
