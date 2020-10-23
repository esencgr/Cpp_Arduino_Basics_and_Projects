const int led[4]={7,8,9,10};

void setup() {
    for(int i=0; i<=3; i++){
        pinMode(led[i], OUTPUT);     
    }
}

void loop() {
    for(int i=0; i<=3; i++){
        digitalWrite(led[i],1);    
        delay(250);
        digitalWrite(led[i],0);     
    }    
    for(int i=3; i>=0; i--){
        digitalWrite(led[i],1);    
        delay(250);
        digitalWrite(led[i],0);     
    }   
}
