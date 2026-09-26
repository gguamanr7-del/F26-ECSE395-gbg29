/* 

this was for testing some intial stuff, ignore



#include <Arduino.h>

// gbg29
// Potentiometer controlling TT motor

const int potentiometerPin = A2;

const int motorPin1 = A0;
const int motorPin2 = A1;

// Motor will activate when the potentiometer
// reaches this angle
const int targetAngle = 70;

void motorOn() {
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void motorOff() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
}

void setup() {
  Serial.begin(115200);

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  motorOff();
}

void loop() {

  // Read the potentiometer and convert it to an angle
  int potentiometerValue = analogRead(potentiometerPin);
  int angle = map(potentiometerValue, 0, 4095, 0, 90);

  //Serial.print("Angle: ");
  //Serial.println(angle);

  // When the potentiometer reaches the target angle,
  // turn the motor on
  if (angle >= targetAngle) {
    motorOn();
  }
  else {
    motorOff();
  }

  delay(50);
} */