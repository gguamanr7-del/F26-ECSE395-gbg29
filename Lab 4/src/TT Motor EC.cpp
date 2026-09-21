#include <Arduino.h>

const int MOTOR_B_1A = A0; // gbg29: Sets motor pin 1A to A0
const int MOTOR_B_1B = A1; // gbg29 Sets motor pin 1B to  A1


void setup() {

  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT);  

}

void loop() {
  //gbg29: increase motor speed
  for (int speed = 0; speed <= 255; speed++){
    analogWrite(MOTOR_B_1A, speed);//gbg29: Sets the motor speed, gradualy increasing the value of speed
    analogWrite(MOTOR_B_1B, 0); //gbg29: Keeps the motor going in only one direction

    delay(25);//gbg29: Waits 25ms before increasing speed 
  }

  for (int speed = 255; speed>= 0; speed--){
    analogWrite(MOTOR_B_1A, speed); //gbg29: Sets the motor speed, gradually decreasing the value of speed
    analogWrite(MOTOR_B_1B, 0); //gbg29: Keeps the motor going in only one direction

    delay(25); //gbg29: Waits 25ms before decreasing speed
  
  }
  
}
