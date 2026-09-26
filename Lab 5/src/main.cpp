#include <Arduino.h>

/* gbg29: Uses the potentiometer, touch sensor, and TT motor together.
The potentiometer data activates system, where then the TT Motor's movement 
is dictated by the touch sensor value
*/ 
 
// gbg29: Define our inputs/sensors
const int potentiometerPin = A2;//gbg29: Set potentiometer pin to A2 
const int touchSensorPin = A4;//gbg29: Set touch sensor pin to A4.(Gets buggy with A3) 
 
// gbg29: Define our output/actuators
const int motorPin1 = A0;//gbg29: Define motor pin 1 to A0
const int motorPin2 = A1; //gbg29: Define motor pin 2 to A1
 
// gbg29: Define the angle where the system is considered active
const int activeAngle = 20; 
 
// gbg29: Define different target angles depending on the touch sensor
const int contactTargetAngle = 70; 
const int noContactTargetAngle = 55; 
 
// gbg29: Define how long the system waits before taking action. 3 seconds is best for testing
const unsigned long waitTime = 3000; 
 
// gbg29: Define the initial conditions. Should all be off
bool systemActive = false; 
bool motorActive = false; 
 
int previousAngle = 0;//gbg29: Stores the previous potentiometer "angle"
unsigned long lastMovementTime = 0;//gbg29: Stores the time when movement was last detected as unsigned long to compare to millis() later
 
// gbg29: Gets potentiometer values and converts it to an angle from 0-90
int getSensorAngle(){ 
    int potentiometerValue = analogRead(potentiometerPin);//gbg29: Reads the current potentiometer value
    int sensorAngle = map(potentiometerValue, 0, 4095, 0, 90);//gbg29: Converts the value to an angle from 0-90
 
    return sensorAngle;//gbg29: Returns the converted angle
}  
 
//gbg29: Helper methods for the TT motor
// gbg29: Turns the motor on
void motorOn(){ 
    digitalWrite(motorPin1, HIGH);//gbg29: Sends a HIGH signal to motor pin 1
    digitalWrite(motorPin2, LOW);//gbg29: Sends a LOW signal to motor pin 2
} 
 
// gbg29: Turns the motor off
void motorOff(){ 
    digitalWrite(motorPin1, LOW);//gbg29: Turns motor pin 1 off
    digitalWrite(motorPin2, LOW);//gbg29: Turns motor pin 2 off
} 
 
void setup() { 
    Serial.begin(115200);//gbg29: Starts the Serial Monitor at 115200 baud
 
    pinMode(touchSensorPin, INPUT);//gbg29: Sets the touch sensor pin as an input
    pinMode(motorPin1, OUTPUT);//gbg29: Sets motor pin 1 as an output
    pinMode(motorPin2, OUTPUT);//gbg29: Sets motor pin 2 as an output
 
    motorOff();//gbg29: Makes sure the motor starts off
 
    previousAngle = getSensorAngle();//gbg29: Gets the starting potentiometer angle
    lastMovementTime = millis();//gbg29: Starts the movement timer
} 
 
void loop() { 
 
    int sensorAngle = getSensorAngle();//gbg29: Gets the current potentiometer angle
    int touchValue = digitalRead(touchSensorPin);//gbg29: Reads the current touch sensor value
 
    // gbg29: Prints the current angle and touch sensor values for testing and verification
    Serial.print("Angle: "); 
    Serial.print(sensorAngle); 
    Serial.print(" | Touch: "); 
    Serial.println(touchValue); 
 
    // gbg29: Detects when the system becomes active
    if(sensorAngle > activeAngle && !systemActive && !motorActive){ 
        systemActive = true;//gbg29: Activates the system
        lastMovementTime = millis();//gbg29: Starts the timer when the system becomes active
    } 
 
    // gbg29: Resets the timer when movement is detected
    if(sensorAngle != previousAngle){ 
        lastMovementTime = millis();//gbg29: Records the time movement was detected
        previousAngle = sensorAngle;//gbg29: Updates the previous angle
    } 
 
    // gbg29: Waits until the system has gone through the wait time
    if (systemActive && !motorActive){ 
 
        if(millis() - lastMovementTime >= waitTime){ 
 
            int targetAngle;//gbg29: Stores the target angle for the motor
             
            // gbg29: Chooses the target angle based on the touch sensor
            if(touchValue == LOW){ 
                targetAngle = noContactTargetAngle;//gbg29: Uses the no-contact target angle
            }
            else{ 
                targetAngle = contactTargetAngle;//gbg29: Uses the contact target angle
            } 
             
            // gbg29: Turns the motor on until the target angle is reached
            motorOn(); 
 
            while(getSensorAngle() > targetAngle){ 
                motorOn();//gbg29: Keeps the motor running while above the target angle
 
                int currentAngle = getSensorAngle();//gbg29: Gets the current potentiometer angle
                int currentTouch = digitalRead(touchSensorPin);//gbg29: Gets the current touch sensor value
 
                // gbg29: Prints the current sensor values while the motor is moving. The touch angle values can be buggy but behavior still holds as intended
                Serial.print("Angle: "); 
                Serial.print(currentAngle); 
                Serial.print(" | Touch: "); 
                Serial.println(currentTouch); 
 
                delay(10);//gbg29: Give a 10 ms delay
            } 
 
            motorOff();//gbg29: Turns the motor off after reaching the target angle
 
            motorActive = true;//gbg29: Records that the motor has completed its movement
            systemActive = false;//gbg29: Deactivates the system
        } 
    } 
 
    // gbg29: Resets the motor status after the angle goes below the active angle
    if(sensorAngle <= activeAngle){ 
        motorActive = false;//gbg29: Allows the system to activate again
    } 
 
    delay(50);//gbg29: Waits 50ms before running the loop again
}
