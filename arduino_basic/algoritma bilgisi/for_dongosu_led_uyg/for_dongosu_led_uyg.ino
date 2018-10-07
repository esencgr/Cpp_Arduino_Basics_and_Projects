int i;
int j;

void setup() 
{
    for (i=2; i<=11; i++){
    pinMode (i, OUTPUT);
    }
}

void loop() 
{
  int i;
  int j=11;
  for (i=2; i<=11 ;i++) // burada i degeri 6 e giderse aynı işlem tersine 
  {
    digitalWrite (i,HIGH);
    digitalWrite (j,HIGH);
    delay (100);
    digitalWrite (i, LOW);
    digitalWrite (j, LOW);
    delay (100);
    j=j-1;
  }
}
 
   
