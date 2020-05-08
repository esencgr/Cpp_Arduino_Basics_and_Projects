const int x = A0;
const int y = A1;
const int button = 7;

int x_state;
int y_state;
int button_state = 0;

void setup(){
    Serial.begin(9600);
    pinMode( button, INPUT );
}

void loop(){
     button_state = digitalRead( button );
     x_state = analogRead( x );
     y_state = analogRead( y );

     Serial.print("button state = ");
     Serial.println( button_state );
     Serial.print("x state = ");
     Serial.println( x_state );
     Serial.print("y state = ");
     Serial.println( y_state );

     delay( 750 );
}
