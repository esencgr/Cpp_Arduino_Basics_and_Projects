#include <Servo.h>

Servo sg90;      // servo  motor nesnesi oluşturduk

int pos = 0;
int pozisyon = 0;
void setup()
{
  sg90.attach(9);    //servo motoru başlatmış oluyoruz ve 9 bağlı olduğu pin oluyor

}

void loop()
{
  sg90.write (180);   // motoru 180 derce döndürür
} 
