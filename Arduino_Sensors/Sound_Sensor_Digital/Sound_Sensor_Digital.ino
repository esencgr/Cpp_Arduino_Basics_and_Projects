const int SensorPin = 3;
const int motor = 2;
//const int SensorPin = A0;
int state;
int motor_state;

void setup() {
  Serial.begin(9600);
  pinMode(SensorPin, INPUT);
}

void loop() {
    state = digitalRead(SensorPin);
    //state = analogRead(SensorPin);
    if( state == HIGH ){
        if( motor_state == LOW )
            motor_state == HIGH;
        else
            motor_state == LOW;

        digitalWrite( motor, motor_state );
    }
    
    delay( 1000 );
} 
