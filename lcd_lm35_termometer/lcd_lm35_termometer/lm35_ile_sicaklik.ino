const int sensor = A3;
const int k_led = 5;
const int y_led = 4;
const int m_led = 3;

int sensor_deger = 0;
float voltaj_deger = 0;
float sicaklik_deger = 0;

void setup() 
{
 pinMode (k_led , OUTPUT);
 pinMode (y_led , OUTPUT);
 pinMode (m_led , OUTPUT);
    Serial.begin(9600);
}

void loop() 
{
sensor_deger = analogRead(sensor);
Serial.print("okunan deger =");
Serial.println (sensor_deger);
voltaj_deger=(sensor_deger / 1023.0) * 5000;
Serial.print("gelen voltaj =");
Serial.println (voltaj_deger);
sicaklik_deger=(voltaj_deger)/10.0;
Serial.print("sicaklik = ");
Serial.print (sicaklik_deger);
Serial.println (" derece ");
delay (1000);

  if (sicaklik_deger >=35 )
  {
    digitalWrite(k_led , LOW);
    digitalWrite(y_led , HIGH);
    digitalWrite(m_led , HIGH);
  }
  else if (sicaklik_deger < 35 && sicaklik_deger >=30 )
  {
    digitalWrite(k_led , LOW);
    digitalWrite(y_led , LOW);
    digitalWrite(m_led , HIGH);
    
  }
 else if (sicaklik_deger < 30 )
  {
    digitalWrite(k_led , HIGH);
    digitalWrite(y_led , HIGH);
    digitalWrite(m_led , LOW);
    
  }

  
}
