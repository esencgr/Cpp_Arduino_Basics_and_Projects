/*
bluetooth controlled car
*/
#include<SoftwareSerial.h>
SoftwareSerial bt_communication(6, 7); // rx tx
#define left_fwd 8
#define left_back 9
#define left_speed 10

#define right_fwd 13
#define right_back 12
#define right_speed 11

int motors_speed = 255;
byte last_process;

void setup(){
    pinMode(left_fwd, OUTPUT);
    pinMode(right_fwd, OUTPUT);
    pinMode(left_back, OUTPUT);
    pinMode(right_back, OUTPUT);
    pinMode(left_speed, OUTPUT);
    pinMode(right_speed, OUTPUT);
  
    Serial.begin(9600);
    bt_communication.begin(9600);
}

void loop(){
    if (bt_communication.available()){
        char data = bt_communication.read();
        Serial.println(data);
        if (data == '1'){
            stop();
            delay(10);
            forward();
            last_process = 1;
        }
        else if (data == '2'){
            stop();
            delay(10);
            back();
            last_process = 2;
        }
        else if (data == '3'){
            stop();
            delay(10);
            left();
            last_process = 3;
        }
        else if (data == '4'){
            stop();
            delay(10);
            right();
            last_process = 4;
        }
        else if (data == '6'){
            stop();
        }
        else if (data == '0'){
            motors_speed = motors_speed + 25;
            if (motors_speed > 255){
               motors_speed = 255;
            }
            Serial.print("motors speed= ");
            Serial.println(motors_speed);
            continue_last_process();
        }
        else if (data == '5'){
            motors_speed = motors_speed - 25;
            if (motors_speed < 0){
               motors_speed = 0;
            }
            Serial.print("motors speed= ");
            Serial.println(motors_speed);
            continue_last_process();
        }
    }
}

void forward(){
    digitalWrite(left_fwd, 1);
    digitalWrite(right_fwd, 1);
    digitalWrite(left_back, 0);
    digitalWrite(right_back, 0);
    analogWrite(left_speed, motors_speed);
    analogWrite(right_speed, motors_speed);
}

void back(){
    digitalWrite(left_fwd, 0);
    digitalWrite(right_fwd, 0);
    digitalWrite(left_back, 1);
    digitalWrite(right_back, 1);
    analogWrite(left_speed, motors_speed);
    analogWrite(right_speed, motors_speed);
}

void left(){
    digitalWrite(left_fwd, 1);
    digitalWrite(right_fwd, 0);
    digitalWrite(left_back, 0);
    digitalWrite(right_back, 1);
    analogWrite(left_speed, motors_speed);
    analogWrite(right_speed, motors_speed);
}

void right(){
    digitalWrite(left_fwd, 0);
    digitalWrite(right_fwd, 1);
    digitalWrite(left_back, 1);
    digitalWrite(right_back, 0);
    analogWrite(left_speed, motors_speed);
    analogWrite(right_speed, motors_speed);
}

void stop(){
    digitalWrite(left_fwd, 0);
    digitalWrite(right_fwd, 0);
    digitalWrite(left_back, 0);
    digitalWrite(right_back, 0);
    analogWrite(left_speed, 0);
    analogWrite(right_speed, 0);
}

void continue_last_process(){
    if (last_process == 1)
      forward();
      
    else if (last_process == 2)
      back();
    
    else if (last_process == 3)
      left();
    
    else if (last_process == 4)
      right(); 
}
