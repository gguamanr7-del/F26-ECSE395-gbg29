#include <ESP32Servo.h>

// Define the servo and the pin it is connected to
Servo myServo;
const int servoPin = A0;//gbg29

// Define the minimum and maximum pulse widths for the servo
const int minPulseWidth = 500; // 0.5 ms
const int maxPulseWidth = 2500; // 2.5 ms

//gbg29: Helper method that helps gradually increase and decrease speed
void helper(int startAngle, int endAngle){
  int direction;//gbg29: Stores direction, used to determine increase or decrease angle

  if(startAngle < endAngle){//gbg29: If ending angle is greater than the starting angle
    direction = 1;//gbg29: Assigns an angle change of +1 ,(180,0)
  } else{
    direction = -1;//gbg29: Assigns an angle change of -1, (180,0)
  }

  //gbg29: Moves the servo motor one degree at a time until it reach the end angle
  for (int angle = startAngle; angle != endAngle; angle+= direction){
    int pulseWidth; //gbg29:Used to store current angle's pulse width

    pulseWidth = map(angle, 0, 180, minPulseWidth, maxPulseWidth); //gbg29: Converts the
    // angle from 0-180 to pulse width range

    myServo.writeMicroseconds(pulseWidth);//gbg29:Sends the pulse width to the servo to move it
    //to the current angle

    int distance_from_center = abs(90-angle); //gbg29: Calculates distance from mid way point
    int delayTime = 5 + (15*distance_from_center*distance_from_center/8100); //gbg29: Used to make
    //the servo faster as it approaches 90 degreees and slows down as it goes away
  
    delay(delayTime);//gbg29: Waits a certain time before going to the next angle(changes)
  }

  int pulseWidth = map(endAngle, 0, 180, minPulseWidth, maxPulseWidth);//gbg29: Finds the pulse width for final angle
  myServo.writeMicroseconds(pulseWidth); //gbg29: Makes sure the servo gets to the final angle
}
void setup() {
  // Attach the servo to the specified pin and set its pulse width range
  myServo.attach(servoPin, minPulseWidth, maxPulseWidth);

  // Set the PWM frequency for the servo
  myServo.setPeriodHertz(50); // Standard 50Hz servo
}

void loop() {
  helper(0,180);//gbg29: Moves the servo from 0-180 degrees. Increases speed
  //then decreases speed halfway

  helper(180,0);//gbg29: Moves the back from 180-0 degrees. Increases speed
  //then decreases speed halfway 
}