#include <Arduino.h>

// function prototype
float voltage(float analogvalue);

// Put your potentiometer pin assignment here
 //GBG29
const int sensorPin = A1;//gbg29

void setup() {
    Serial.begin(115200);
}

void loop() {
    // This is the line for printing in the serial
    int sensorValue = analogRead(sensorPin); //gbg
    float sensorVoltage = voltage(sensorValue);
    Serial.println(sensorVoltage);
    delay(150); //gbg29 
}

// function to calculate output voltage
float voltage(float analogvalue){
    float volt;
    volt = (analogvalue*3.3)/4095.0;
    //analogRead(sensorPin); gives us 0-4095 values
    //use the formula (Analog value*Reference voltage) / (Sensor Resolution) to calculate the output voltage
    return volt;
}