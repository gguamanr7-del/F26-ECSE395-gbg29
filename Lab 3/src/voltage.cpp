#include <Arduino.h>

// function prototype
float voltage(float analogvalue);


const int sensorPin = A1;//gbg29: Sets the potentiometer pin to A1

void setup() {
    Serial.begin(115200);
}

void loop() {
    // This is the line for printing in the serial
    int sensorValue = analogRead(sensorPin); //gbg29: Reads the analog value from the potentiometer and stores it in sensorValue
    float sensorVoltage = voltage(sensorValue); //gbg29: Converts the sensor value into voltage usomg the voltage function
    Serial.println(sensorVoltage); //gbg29: Prints the potentiometer voltage to the Serial Monitor
    delay(150); //gbg29: Waits 150 ms before reading and printing the voltage again
}

// function to calculate output voltage
float voltage(float analogvalue){
    float volt; //gbg29: Creates a float variable to store the calculated voltage 
    volt = (analogvalue*3.0)/4095.0; //gbg29: Converts the analog voltage using a 3.0V reference voltage and a miximum analog value of 4095
    return volt; //gbg29: Returns the calculated voltage back 
}