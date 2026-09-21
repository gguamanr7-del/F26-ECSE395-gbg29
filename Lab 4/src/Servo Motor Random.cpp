#include <ESP32Servo.h>

// Define the servo and the pin it is connected to
Servo myServo;
const int servoPin = A0; //gbg29: Set servoPin to A0

// variable for random angle
int randomAngle;

// Variable for pulse width
int pulseWidth;

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

void setup() {
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(50); // Standard 50Hz servo
}

void loop() {
    randomAngle = random(0,181); //gbg29: Creates a random angle from 0 to 180 degrees
  
    pulseWidth = map(randomAngle, 0, 180, minPulseWidth, maxPulseWidth); //gbg29: Converts the random angle into a pulse width
    myServo.writeMicroseconds(pulseWidth); // writing pulse width to servo

    delay(random(500,2001)); //gbg29: Creates a radnom delay between 500-2000ms
}
