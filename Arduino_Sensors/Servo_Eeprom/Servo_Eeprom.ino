#include <Servo.h>
#include <EEPROM.h>

Servo sg;

int deg;
int direct = 0; /* 0 ise servo ileri, 1 ise geri yönde dönmektedir. */

void setup(){
  sg.attach(9); /* Servo Arduinonun 9 numaralı pinine takıldı */
   
  deg = EEPROM.read(1); /* Servonun kaldığı yer EEPROMdan alınıyor */
  if( deg < 1 || deg > 179 ){ /* EEPROMda servo açısı yerine başka bir veri varsa */
    deg = 1; /* Motor ilk konumuna donsun */
  }
  direct = EEPROM.read(0);
  if( direct != 1 && direct != 0 ){ /* EEPROMda dönüş yönü yerine başka bir veri varsa */
    direct = 0;  /* Motor ileri yönde donsun */
 }
}

void loop(){                         
  sg.write( deg ); /* Servo motoru kontrol ediyoruz */              
  EEPROM.write( 1, deg ); /* Son açıyı EEPROMa kaydediyoruz */
  
  if( direct == 0 ){ /* Motor ileri önde donuyorsa */
    deg = deg + 10; /* 5 derece döndürelim */
    if( deg > 179 ){ /* Motor ileri yönde sona ulaştıysa */
       deg = 179;
       direct = 1; /* Geri yönde dönmeye basla */   
       EEPROM.write( 0, direct ); /* Yon bilgisi EEPROMa kaydedildi */
    }
  }
  else{ /* Motor geri yönde donuyorsa */
    deg = deg - 10; /* 5 derece geri don */
    if( deg < 1 ){ /* Motor geri yönde sona ulaştıysa */
       deg = 1;
       direct = 0; /* ileri yönde dönmeye basla */
       EEPROM.write( 0, direct ); /* Yon bilgisi EEPROMa kaydediliyor */
    }
  }
  
  delay(300); /* Motorun konumunu alması için biraz bekleme */
}
