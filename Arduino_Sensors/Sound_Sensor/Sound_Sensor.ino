const int SensorPin = 3;
//const int SensorPin = A0;
int state;

void setup() {
  Serial.begin(9600);
  pinMode(SensorPin, INPUT);
}

void loop() {
    state = digitalRead(SensorPin);
    //state = analogRead(SensorPin);
    Serial.println( state );
    delay( 1000 );
}
