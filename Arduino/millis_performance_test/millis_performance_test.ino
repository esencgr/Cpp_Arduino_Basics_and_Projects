unsigned long timer_now, timer_past, sum=0;
int work_time;

void loop_sum( ){
    sum = 0;
    for( int i=0; i<=999; i++ ){
         sum += i;
         delay( 10 );             
    }
    Serial.println( sum );
}
void setup(){
    Serial.begin( 9600 );
}

void loop(){
  
    timer_past = millis();
    loop_sum();
    timer_now = millis();
    
    work_time = timer_now - timer_past;
    Serial.print( "Work Time : " );
    Serial.println( work_time );
    
}
