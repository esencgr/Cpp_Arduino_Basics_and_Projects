
int a=2; // her pine displaydeki bir led bağlı
int b=3;
int c=4;
int d=5;
int e=6;
int f=7;
int g=8;
int x=9;  //Displaydeki nokta led

void setup(){
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);

}

void show( int number ){
  
    switch( number ){
     case 0:         //sayinin moduna göre display ledleri
     digitalWrite(a,1-HIGH);  //yanacak
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-HIGH);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-LOW); 
     break;   
    
     case 1:
     digitalWrite(a,1-LOW);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-LOW);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-LOW);
     digitalWrite(g,1-LOW);     
     break;
     
     case 2:
     digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-LOW);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-HIGH);
     digitalWrite(f,1-LOW);
     digitalWrite(g,1-HIGH);    
     break;
     
     case 3:
     digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-LOW);
     digitalWrite(g,1-HIGH);      
     break;
     
     case 4:
     digitalWrite(a,1-LOW);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-LOW);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     break;
     
     case 5:     
     digitalWrite(a,1-HIGH);
     digitalWrite(b,1-LOW);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     break;
     
     case 6:
     digitalWrite(a,1-HIGH);
     digitalWrite(b,1-LOW);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-HIGH);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     break;
     
     case 7:
     digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-LOW);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-LOW);
     digitalWrite(g,1-LOW);    
     break;
     
     case 8:
     digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-HIGH);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     break;
     
     case 9:
     digitalWrite(a,1-HIGH);
     digitalWrite(b,1-HIGH);
     digitalWrite(c,1-HIGH);
     digitalWrite(d,1-HIGH);
     digitalWrite(e,1-LOW);
     digitalWrite(f,1-HIGH);
     digitalWrite(g,1-HIGH);    
     break;
     }
}
  
void loop(){
    for( int k=0; k<=9; k++ ){
        show(k);    
        delay(1000);
    }                  
}
