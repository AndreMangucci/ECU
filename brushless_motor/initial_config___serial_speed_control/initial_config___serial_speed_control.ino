/*
Coded by Marjan Olesch
Sketch from Insctructables.com
Open source - do what you want with this code!
*/
#include <Servo.h>


int value = 0; // set values you need to zero

Servo firstESC, secondESC; //Create as much as Servoobject you want. You can controll 2 or more Servos at the same time

void setup() {

  firstESC.attach(9);    // attached to pin 9 I just do this with 1 Servo
  Serial.begin(9600);    // start serial at 9600 baud
  delay(100);
//  firstESC.writeMicroseconds(2000);
//  Serial.println("full throtle");
//  delay(2000);
  firstESC.writeMicroseconds(700);
//  Serial.println("min throtle");
//  delay(1000);
}

void loop() {
  bool controle = true;
  
  if(Serial.available()){
    int vl = Serial.parseInt();
    
    while(controle == true){
      
      firstESC.writeMicroseconds(vl);  
      delay(100);
      
      if (Serial.available()){
          int rd = Serial.parseInt();
          if(rd == 1){
            controle = false;
            firstESC.writeMicroseconds(700);
          }
        }
    }
    
    }
  
}
