#include <Keypad.h>

const byte satir = 4;
const byte sutun = 4;

char tus;
char tus_takimi[satir][sutun] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte satir_pinleri[satir] = {13, 12, 11, 10};
byte sutun_pinleri[satir] = {9, 8, 7, 6};

Keypad tuslar = Keypad(makeKeymap(tus_takimi) , satir_pinleri , sutun_pinleri , satir , sutun);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  tus = tuslar.getKey();
  if (tus)
  {
    Serial.print(tus);
  }

}
