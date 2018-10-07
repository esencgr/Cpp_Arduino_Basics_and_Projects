/*
   Lezzetli Robot Tarifleri
   Arduino İle Nasıl Kullanılır
   RFID Okuyucu
   VİDEO >>> http://lezzetlirobottarifleri.com/video/rfid-modulu-arduino-ile-nasil-kullanilir
*/

#include <SPI.h>
#include <RFID.h>

RFID lrt720(10, 5);

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  lrt720.init();

}

void loop()
{
  if (lrt720.isCard()) {

    
    if (lrt720.readCardSerial()) {

      Serial.println("Kart Bulundu ID : ");
      Serial.print(lrt720.serNum[0]);
      Serial.print(" , ");
      Serial.print(lrt720.serNum[1]);
      Serial.print(" , ");
      Serial.print(lrt720.serNum[2]);
      Serial.print(" , ");
      Serial.print(lrt720.serNum[3]);
      Serial.print(" , ");
      Serial.print(lrt720.serNum[4]);
      Serial.println(" ");
    }
  }
  lrt720.halt();
}
