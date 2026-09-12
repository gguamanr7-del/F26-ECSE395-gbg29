#include <Arduino.h>

const int sensorPin = A1; //gbg29: Set A1 as the pin used to read the touch sensor
const int ledPin = LED_BUILTIN; //gbg29: Defined the LED so it can be controlled


void setup() {
    Serial.begin(115200); //gbg29:Starts the serial commuication at the recommended rate 

    pinMode(sensorPin, INPUT); //gbg29:Sets the sensor pin as an input so it's readable
    pinMode(ledPin, OUTPUT); //gbg29: Sets the LED as an output  so the ESP32 can turn the LED on and off
}

void loop() {
    int touchValue = digitalRead(sensorPin); //gbg29: Reads the sensor and stores its value in touchValue
    
    if(touchValue == HIGH){ //gbg29:Checks if the sensor is detecting contact
        Serial.println("Touch detected!");//gbg29: Prints "Touch detected!" if contact is detected 
        digitalWrite(ledPin, HIGH); //gbg29: Turns on the LED if contact is detected
    }
    else{ //gbg29:For when sensor is not detecting contact
        Serial.println("No touch detected..."); //gbg29: Prints "No touch detected..." if contact is not detected
        digitalWrite(ledPin, LOW); //gbg29:Turns off the LED if contact is not detected
    }
    delay(100); //gbg29: delay before checking the sensor again
} 