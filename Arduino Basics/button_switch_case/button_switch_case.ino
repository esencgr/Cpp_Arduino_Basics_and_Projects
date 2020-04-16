const int button_up = 4;
const int button_down = 3;
const int key = 2;

int key_state = 1;
int up_state = 0;
int down_state = 0;

int counter = 0;

void setup(){
    Serial.begin( 9600 );
    pinMode( button_up, INPUT );
    pinMode( button_down, INPUT );
    pinMode( key, INPUT );
}

void loop(){
    key_state = digitalRead( key );

    if( key_state == LOW ){        
        up_state = digitalRead( button_up );        
        down_state = digitalRead( button_down );
        
        if( up_state == HIGH ){
            counter++;
            Serial.println( counter );  
            delay( 200 );
        }
        // In this loops, make changes button value while each pressed on buttons.
        while( up_state == HIGH )
            up_state = digitalRead( button_up );   
            
        if( down_state == HIGH ){
            counter--;
            Serial.println( counter );  
            delay( 200 );
        }        
        // In this loops, the changes button value while each pressed on buttons.
        while( down_state == HIGH )
            down_state = digitalRead( button_down );
    }
    
    else{
        switch( counter ){
            case 1:
                Serial.println( "1. motor is active.." );
                delay( 1000 );
            break;
            
            case 2:
                Serial.println( "2. motor is active.." );
                delay( 1000 );
            break; 
                       
            case 3:
                Serial.println( "3. motor is active.." );
                delay( 1000 );
            break;
            
            default:
                Serial.println( "Motors 1-2-3 are passive!\nSet the buttons and select motors that you want to work:" );
                delay( 1000 );
            break;
        }     
    }
}
