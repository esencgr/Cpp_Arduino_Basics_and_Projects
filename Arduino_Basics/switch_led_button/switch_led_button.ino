const int button1 = 2;
const int button2 = 3;
const int key = 4;
const int led = 7;

int button1_up = 0;
int button2_down = 0;
int key_state = 0;
int count = 0;
int tour_number = 0;
    
int tour( );

void setup(){
  
    Serial.begin( 9600 );
    pinMode( button1, INPUT );
    pinMode( button1, INPUT );
    pinMode( key, INPUT );
    pinMode( led, OUTPUT );
    
}

void loop(){
  
    tour_number = tour();
    
    key_state = digitalRead(key);
    if( key_state == HIGH ){
      
        for( int i=0; i<tour_number; i++ ){
            digitalWrite( led, HIGH );
            delay( 500 );
            digitalWrite( led, LOW );
            delay( 500 );
            
            key_state = digitalRead(key);
            if( key_state ==  LOW )
                break;
        }
              
        while( 1 ){
            key_state = digitalRead(key);
            if( key_state == LOW )
                break;           
        }
        
    }
    
}

int tour( ){
  
    button1_up = digitalRead( button1 );
    button2_down = digitalRead( button2 );

    if( button1_up == HIGH ){
        count++;
        delay( 10 );
        Serial.println( count );
       
        while( button1_up == HIGH )
             button1_up = digitalRead( button1 );

        delay( 10 );
    }
    
    if( button2_down == HIGH ){
        count--;
        delay( 10 );
        Serial.println( count );
       
        while( button2_down == HIGH )
             button2_down = digitalRead( button2 );

        delay( 10 );
    }  
    
    return count;          
}
