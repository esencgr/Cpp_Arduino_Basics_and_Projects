int but1 = 2; // buton pinlerini atadık
int but2 = 3;
int but3 = 4;
int but4 = 5;
int but5 = 6;

int led1 = 8;   // Led pinlerini atadık
int led2 = 9;
int led3 = 10;

int b1d;// Buton 1 okunan değerini kaydetmemiz için db1 adında değişken atayoruz...ve diğerleri için
int b2d;
int b3d;
int b4d;
int b5d;

void setup()
{
  Serial.begin(9600); // seri haberleşme başladı
  pinMode(but1 , INPUT); // Buton pinlerini giriş olarak atadık
  pinMode(but2 , INPUT);
  pinMode(but3 , INPUT);
  pinMode(but4 , INPUT);
  pinMode(but5 , INPUT);

  pinMode(led1 , OUTPUT); // Led pinlerini çıkış olarak atadık
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);
}

void loop()
{
  b1d = digitalRead(but1);  // butonları oku ve durum bilgilerini değişkenlere kaydet
  b2d = digitalRead(but2);
  b3d = digitalRead(but3);
  b4d = digitalRead(but4);
  b5d = digitalRead(but5);

  if (b1d == HIGH) // b1d HIGH ise ( bu bağlantıda 1. butona basılmış ise)
  {
    digitalWrite(led1 , HIGH);// led1'i yak
    Serial.println(" led 1 yandi"); // ekrana yazıyı yaz
    delay(100); // 100 ms bekle
  }

  else if (b2d == HIGH)  // b1d HIGH değil, b2d HIGH ise ( yani 2. butona basılmış ise)
  {
    digitalWrite(led1 , HIGH); //led1'i yak
    digitalWrite(led2 , HIGH); //led2'yi yak
    Serial.println(" led 1 ve led 2 yandi"); // ekrana yazıyı yaz
    delay(100); // 100 ms bekle
  }

  else if (b3d == HIGH)      //3. butona basılmı ise
  {
    digitalWrite(led1 , HIGH);  // but3'e basıldığında led1 led2 ve led3 yakacak
    digitalWrite(led2 , HIGH);
    digitalWrite(led2 , HIGH);
    Serial.println(" Tüm ledler yandı "); // ekrana yazıyı yaz
    delay(100); // 100 msn bekle
  }
  else if (b4d == HIGH)        // 4. butona basılmış ise
  {
    digitalWrite(led1 , HIGH);  //ledler sırasi ise yanıp sönecekler
    delay(250);
    digitalWrite(led1 ,  LOW);
    digitalWrite(led2 , HIGH);
    delay(250);
    digitalWrite(led2 ,  LOW);
    digitalWrite(led3 , HIGH);
    delay(250);
    digitalWrite(led3 ,  LOW);
    Serial.println(" Karaşimşek "); // ekrana yazıyı yaz
    delay(100); // 100 ms bekle
  }
  else if (b5d == HIGH)        // 5. butona basılmış ise
  {
    digitalWrite(led1 , HIGH);  // but5'e basıldığında led1 led2 ve led3 yakacak ve 250 ms sonra söndürecek.
    digitalWrite(led2 , HIGH);
    digitalWrite(led3 , HIGH);
    delay(250);
    digitalWrite(led1 ,  LOW);
    digitalWrite(led2 ,  LOW);
    digitalWrite(led3 ,  LOW);
    delay(250);
    Serial.println(" Uyarı ver "); // ekrana yazıyı yaz
    delay(100); // 100 ms bekle
  }
  else          // eğer hiç bir butona basılmamış ise
  {
    digitalWrite(led1 ,  LOW); // tüm ledleri söndür.
    digitalWrite(led2 ,  LOW);
    digitalWrite(led3 ,  LOW);
    Serial.println(" Butonlara Basılmıyor"); // ekrana yazıyı yaz
    delay(100); // 100 ms bekle
  }
}


