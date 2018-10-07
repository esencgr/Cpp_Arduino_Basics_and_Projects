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
  for (pos = 0; pos <= 180; pos += 1)  // derece her arttiğinda 180 dereceye kadar 15 ms aralıklarla servo birere derece döner.
  {
    sg90.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1)
  {
    sg90.write(pos);
    delay(15);
  }
}
