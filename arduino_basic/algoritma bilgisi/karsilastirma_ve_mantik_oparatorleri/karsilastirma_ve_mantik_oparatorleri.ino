int a=20;
int b=10;
int c=20;
int d=30;
int sonuc;

void setup() 
{
Serial.begin(9600);
}

void loop() 
{
if ((a==b) && (c<d)) 
sonuc =1;
else if((a==b) && (d<c))
sonuc = 2;
else if((a!=b) || (d<c))
sonuc = 3;
else if((a!=b) || (a<b))
sonuc = 4;
else 
sonuc=5;
Serial.println(sonuc);
while (1); }
