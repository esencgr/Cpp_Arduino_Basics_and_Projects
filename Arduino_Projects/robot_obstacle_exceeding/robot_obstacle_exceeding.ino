const int trig = 10; //sensör pinleri tanımlandı
const int echo =  8;

const int sol_i = 2; // motor sürücü pinleri tanımlandı
const int sol_g = 3;
const int sag_i = 4;
const int sag_g = 5;

int  sure = 0; // mesafe hesabından kullanılacak olan değişkenler tanımladı
int mesafe = 0;

void setup(){
    pinMode(trig , OUTPUT); // sensörün trigger pini çıkış olarak ayarlandı
    pinMode(echo , INPUT ); // sensörün echo pini giriş olarak ayarlandı
  
    pinMode(sol_i, OUTPUT); // motor sürücü pinleri çıkış olarak ayarlandı
    pinMode(sol_g, OUTPUT);
    pinMode(sag_i, OUTPUT);
    pinMode(sag_g, OUTPUT);
}

void loop(){
    digitalWrite(trig , HIGH); // hc-sr04 kullanılarak mesafe hesaplandı
    delayMicroseconds(1000);   //  
    digitalWrite(trig ,  LOW); //
  
    sure = pulseIn(echo , HIGH);
    mesafe = (sure / 2) / 28.5;

    if (mesafe < 30 ){ // mesafe 30cm den küçük ise robotu geri al ve döndür
        digitalWrite(sol_i ,  LOW);
        digitalWrite(sol_g , HIGH);
        digitalWrite(sag_i ,  LOW);
        digitalWrite(sag_g , HIGH);
        delay(150);

        digitalWrite(sol_i ,  LOW);
        digitalWrite(sol_g , HIGH);
        digitalWrite(sag_i , HIGH);
        digitalWrite(sag_g ,  LOW);
        delay(250);
    }
    else{ // mesafe 30cm den büyük ise düz git
        digitalWrite(sol_i , HIGH);
        digitalWrite(sol_g ,  LOW);
        digitalWrite(sag_i , HIGH);
        digitalWrite(sag_g ,  LOW);
    }
}
