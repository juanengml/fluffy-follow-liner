   ////////////////////////////////////////////////////////
  //                LinoBot v1.0                        //             
 //               By Aarav Garg                        //
////////////////////////////////////////////////////////

//I have added the possibilities of testing
//The values of analogRead could be changed for trouble shooting

//including the libraries
#include <AFMotor.h>

//defining pins and variables
#define lefts A4 
#define rights A5 

//defining motors
AF_DCMotor motor1(4, MOTOR12_8KHZ); 
AF_DCMotor motor2(3, MOTOR12_8KHZ);

AF_DCMotor motor3(2, MOTOR12_8KHZ);
AF_DCMotor motor4(1, MOTOR12_8KHZ);

int calibragem = 990; // 990]

void setup() {
  //setting the speed of motors
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  Serial.begin(9600);
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.print("Sensor left: ");
  Serial.println(analogRead(lefts));
  Serial.print("Sensor right: ");
  Serial.println(analogRead(rights));
  //line detected by both
  if(analogRead(lefts)<=calibragem && analogRead(rights)<=calibragem){
    //stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
  }
  //line detected by left sensor
  else if(analogRead(lefts)<=calibragem && !analogRead(rights)<=calibragem){
    //turn left
    Serial.println("turn left");
    /* motor1.run(BACKWARD);
    motor3.run(BACKWARD);
    motor2.run(FORWARD);
    motor4.run(FORWARD);
    */
  }
  //line detected by right sensor
  else if(!analogRead(lefts)<=calibragem && analogRead(rights)<=calibragem){
    //turn right
    /*
    motor1.run(FORWARD);
    motor3.run(FORWARD);
    motor2.run(BACKWARD);
    motor4.run(BACKWARD);
    /*
    motor1.run(FORWARD);
    motor2.run(RELEASE);
     */
    Serial.println("turn right");
  }
  //line detected by none
  else if(!analogRead(lefts)<=calibragem && !analogRead(rights)<=calibragem){
    Serial.println("Stop");
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  }
  
}


