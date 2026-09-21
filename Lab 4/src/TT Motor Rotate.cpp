#include <Arduino.h>

const int MOTOR_B_1A = A0;//gbg29: sets motor pin 1A to A1
const int MOTOR_B_1B = A1; //gbg29: sets motor pin 1B to A2

void setup() {
  Serial.begin(115200); // gbg29:Starts Serial communication at 115200 baud

  pinMode(MOTOR_B_1A, OUTPUT); //gbg29: Sets pin 1A as an output
  pinMode(MOTOR_B_1B, OUTPUT); //gbg29: Sets 1B as an output 

  Serial.println("Motor controls startup"); //gbg29:Prints a startup message to Serial Monitor 
}

void loop() {
  // --- SECTION 1: Clokwise (5s) ---
  Serial.println("Rotating clockwise"); //gbg29:Prints that the motor is rotation clockwise
  
  // TODO: Write HIGH to one pin and LOW to the other
  digitalWrite(MOTOR_B_1A, HIGH); //gbg29: Sends HIGH to pin 1A
  digitalWrite(MOTOR_B_1B, LOW);//gbg29: Sends LOW to pin 1B
  
  delay(5000); //gbg29: Keeps it running for 5 seconds 

  // --- SECTION 2: Stop (2s) ---
  Serial.println("Stop"); //gbg29: Prints that the motor stopped

  // TODO: Turn off the motor
  digitalWrite(MOTOR_B_1A, LOW); //gbg29: Turns off pin 1A
  digitalWrite(MOTOR_B_1B, LOW);//gbg29: Turns off pin 1B(stopping the motor)

  delay(2000); //gbg29: Keeps the motor off for 2 seconds

  // --- SECTION 3: Counterclockwise (5s) ---
  Serial.println("Rotating counterclockwise"); //gbg29: Prints that the motor is rotating counterclockwise
  
 
  digitalWrite(MOTOR_B_1A, LOW); //gbg29: Sends LOW to pin 1A
  digitalWrite(MOTOR_B_1B, HIGH); //gbg29: Sends HIGH to pin 1B(causing the motor to reverse)

  delay(5000); //gbg29: Keeps the motor running for 5 seconds

  // --- SECTION 4: Stop (2s) ---
  Serial.println("Stop"); //gbg29: Prints that the motor stopped
  
  
  digitalWrite(MOTOR_B_1A, LOW); //gb29: Turns off pin 1A
  digitalWrite(MOTOR_B_1B, LOW); //gbg29: Turns off pin 1B

  delay(2000); //keeps the motor off for 2 seconds
}

