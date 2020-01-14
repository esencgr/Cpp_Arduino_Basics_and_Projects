int x=5;
int y=6;
void setup() 
{
 Serial.begin(9600);
}

void loop() 
{
int z=10;
Serial.print("x=");
Serial.println(x);
Serial.println("----------");
Serial.print("y=");
Serial.println(y);
Serial.println("----------");
Serial.print("z=");
Serial.println(z);
Serial.println("----------");
delay (2000);
}
