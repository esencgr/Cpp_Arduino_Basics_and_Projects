
int i;

void setup() 
{
    for (i=2; i<=11; i++){
    pinMode (i, OUTPUT);
    }
}

void loop() 
{
  
    for (i=2; i<=11; i++)
    {
      digitalWrite (i ,HIGH);
      delay (50);
      digitalWrite (i, LOW);
      delay (50);
    }
  
    for (i=11; i>=2; i--)
    {
      digitalWrite (i ,HIGH);
      delay (50);
      digitalWrite (i, LOW);
      delay (50);
    }
   
    for (i=2; i<=11; i++)
    {
      digitalWrite (i ,HIGH);
      delay (100);
    }
    for (i=11; i>=2; i--)
    {
      digitalWrite (i ,LOW);
      delay (100);
    }
  }
