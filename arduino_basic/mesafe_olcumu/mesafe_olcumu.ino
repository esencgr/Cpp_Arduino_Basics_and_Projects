const int trigger_pin=8;
const int echo_pin=9;

float sure ;
float mesafe ;

void setup() 
{
pinMode (trigger_pin , OUTPUT); /*ses dalagaları göndereceği için çıkış atandı*/
pinMode (echo_pin , INPUT); /*ses dalgalarını algıladığığı için giriş atandı */
Serial.begin(9600);
}

void loop() 
{
 digitalWrite (trigger_pin, HIGH);
 delay (1); /* 1 milisaniye aralıklarla mesafe olçer*/
 digitalWrite (trigger_pin, LOW );
 sure = pulseIn (echo_pin, HIGH); /*echo pinini takip eder bu komut ve high olursa kronometre çalıştırır*/
 mesafe = (sure /2)/ 29.1;

Serial.print ("cisme olan uzaklik=");
Serial.println(mesafe);
Serial.println ("cm");
Serial.println("-------------");
delay (1000);
}

