const int Sensor = A0;
const int led = 2;
int state;
const int thres = 800;

void setup() {
  Serial.begin(9600);
  pinMode( led, INPUT);
}

void loop() {
    state = analogRead( Sensor );
    if( state > thres ){
        digitalWrite( led, HIGH );
        delay( 1000 );
        digitalWrite( led, LOW );
    }
    else 
        digitalWrite( led, LOW );
} 
