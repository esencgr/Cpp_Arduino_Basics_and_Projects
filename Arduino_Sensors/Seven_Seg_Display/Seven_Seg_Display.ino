int buton=12;

int a=2; // her pine displaydeki bir led bağlı
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;
int x=9;  //Displaydeki nokta led

int sayi=0; // Modu alınacak sayi

void setup () {
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(x,OUTPUT);
  pinMode(buton,INPUT_PULLUP);
  Serial.begin (9600);}  // Sayi değerini monitörde görmek için
  
  void loop () {
    int butondurumu=digitalRead(buton); // buton durumu okuyoruz
    
    if (butondurumu==1){  //butona her basıldığında; 
        sayi=sayi+1;     
        
        Serial.println(sayi); //Bilgisayardaki değere bakarak
        delay(100);           //displayin doğru olup olmadığını
                        //anlayabiliriz.
        while( butondurumu == HIGH ){
            butondurumu=digitalRead(buton);
        } 
    }          
    

                        
    if (sayi%10==0)         //sayinin moduna göre display ledleri
    {digitalWrite(a,1-HIGH);  //yanacak
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-HIGH);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-LOW);    
     }
     else if (sayi%10==1)
     {digitalWrite(a,1-LOW);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-LOW);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-LOW);
     digitalWrite(g,1-LOW);     
     }
     else if (sayi%10==2){
     digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-LOW);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-HIGH);
     digitalWrite(f,1-LOW);
     digitalWrite(g,1-HIGH);    
     }
     else if (sayi%10==3)
     {digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-LOW);
     digitalWrite(g,1-HIGH);    
     }
     else if (sayi%10==4)
     {digitalWrite(a,1-LOW);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-LOW);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     }
     else if (sayi%10==5)
     {digitalWrite(a,1-HIGH);
     digitalWrite(b,1-LOW);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     }
     else if (sayi%10==6)
     {digitalWrite(a,1-HIGH);
     digitalWrite(b,1-LOW);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-HIGH);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     }
     else if (sayi%10==7)
     {digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-LOW);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-LOW);
     digitalWrite(g,1-LOW);    
     }
     else if (sayi%10==8)
     {digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-HIGH);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     }
     else if (sayi%10==9)
     {digitalWrite(a,1-HIGH);
     digitalWrite (b,1-HIGH);
     digitalWrite (c,1-HIGH);
     digitalWrite (d,1-HIGH);
     digitalWrite (e,1-LOW);
     digitalWrite (f,1-HIGH);
     digitalWrite (g,1-HIGH);    
     }

 
}
