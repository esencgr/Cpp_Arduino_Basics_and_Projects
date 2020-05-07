const int trigger_pin = 12;
const int echo_pin = 13;
const int buzzer = 2;
const int mled= 3;
const int yled= 4;
const int sled= 5;
const int kled= 6;

int sure ;
int mesafe ;

void setup(){
    Serial.begin(9600);
    pinMode (kled , OUTPUT);
    pinMode (sled , OUTPUT);
    pinMode (yled , OUTPUT);
    pinMode (mled , OUTPUT);
    pinMode (buzzer , OUTPUT);
    pinMode (trigger_pin , OUTPUT);
    pinMode (echo_pin , INPUT);
}

void loop(){
    digitalWrite (trigger_pin , HIGH);
    delay (1);
    digitalWrite (trigger_pin , LOW);
    sure =pulseIn(echo_pin , HIGH);
    mesafe =(sure /2)/28.5;
    Serial.println(mesafe);
    if (mesafe <=5){
        digitalWrite(kled , HIGH);
        digitalWrite(sled , HIGH);
        digitalWrite(yled , HIGH);
        digitalWrite(mled , HIGH);
        digitalWrite(buzzer , HIGH);
        delay(50);
        digitalWrite(kled , LOW);
        digitalWrite(sled , LOW);
        digitalWrite(yled , LOW);
        digitalWrite(mled , LOW);
        digitalWrite(buzzer , LOW);
        delay (100);
    }
    else if (mesafe <= 10){
        digitalWrite(kled , HIGH);
        digitalWrite(buzzer ,HIGH);
        delay (50);
        digitalWrite(kled , LOW);
        digitalWrite(buzzer ,LOW);
        delay (250);
    }
    else if (mesafe <= 25){
        digitalWrite(sled , HIGH);
        digitalWrite(buzzer ,HIGH);
        delay (50);
        digitalWrite(sled , LOW);
        digitalWrite(buzzer ,LOW);
        delay (500);
    }
    else if (mesafe <= 50){
        digitalWrite(yled , HIGH);
        digitalWrite(buzzer ,HIGH);
        delay (50);
        digitalWrite(yled , LOW);
        digitalWrite(buzzer ,LOW);
        delay (750);
    }
    else{
        digitalWrite(mled , HIGH);
        delay (50);
        digitalWrite(mled , LOW);
        delay (1000);
    }
}
