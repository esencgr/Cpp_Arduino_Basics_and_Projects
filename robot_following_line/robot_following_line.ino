const int sag_i = 4; // motor sürücü ve sensör pinleri tanımlandı
const int sag_g = 5;
const int sol_i = 7;
const int sol_g = 6;
const int sol_sensor = 2;
const int sag_sensor = 3;

int sol_durum, sag_durum; // sol ve sağ sensörün durum değişkenleri tanımlandı

void setup(){
    pinMode(sag_i, OUTPUT); // motor sürücü pinleri çıkış olarak atandı
    pinMode(sag_g, OUTPUT);
    pinMode(sol_i, OUTPUT);
    pinMode(sol_g, OUTPUT);
    
    pinMode(sag_sensor, INPUT); // sensör pinleri giriş pini olarak atandı
    pinMode(sol_sensor, INPUT);
}

void loop(){
    sol_durum = digitalRead(sol_sensor); // sol ve sağ sensör okunup değişkenlere kaydedildi.
    sag_durum = digitalRead(sag_sensor);
    if (sol_durum == LOW && sag_durum == LOW){ // iki sensör de siyah görmüyor ise motorlar ileri gidecek şekilde çalışıtırıldı.
        digitalWrite(sag_i, HIGH);
        digitalWrite(sag_g, LOW);
        digitalWrite(sol_i, HIGH);
        digitalWrite(sol_g, LOW);
    }
    else if (sol_durum == LOW && sag_durum == HIGH){ // sağ sensör siyah görüyor ise motorlar sağa dönecek şekilde çalıştırıldı.
        digitalWrite(sag_i, HIGH);
        digitalWrite(sag_g, HIGH);
        digitalWrite(sol_i, HIGH);
        digitalWrite(sol_g, LOW);
    }
    else if (sol_durum == HIGH && sag_durum == LOW){ // sol sensör siyah görüyor ise motorlar sola dönecek şekilde çalıştırıldı.
        digitalWrite(sag_i, HIGH);
        digitalWrite(sag_g, LOW);
        digitalWrite(sol_i, HIGH);
        digitalWrite(sol_g, HIGH);
    }
    else{ //eğer yukarıda şartların 3 üde değilse dur.
        digitalWrite(sag_i, LOW);
        digitalWrite(sag_g, LOW);
        digitalWrite(sol_i, LOW);
        digitalWrite(sol_g, LOW);
    }
    delay(25);                      // ivme kırıcı kodlar
    digitalWrite(sag_i, LOW); 
    digitalWrite(sag_g, LOW);
    digitalWrite(sol_i, LOW);
    digitalWrite(sol_g, LOW);
    delay(50);
}
