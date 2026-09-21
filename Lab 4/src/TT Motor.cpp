#include <Arduino.h>

// TODO: Define your pins
// Hint: Look at your wiring. Which pins did you use?
const int MOTOR_B_1A = A0; // gbg29: Sets motor pin 1A to A0
const int MOTOR_B_1B = A1; // gbg29 Sets motor pin 1B to  A1


void setup() {

  pinMode(MOTOR_B_1A, OUTPUT);
  pinMode(MOTOR_B_1B, OUTPUT);  

    
  analogWrite(MOTOR_B_1A, 0); //gbg29: COntrols direction  
  analogWrite(MOTOR_B_1B, 100); //gbg29: Controls speed 

  delay(2000); //gbg29: Controls delay between spinning and stopping

  analogWrite(MOTOR_B_1A, 0);
  analogWrite(MOTOR_B_1B, 0);
}

void loop() {
}