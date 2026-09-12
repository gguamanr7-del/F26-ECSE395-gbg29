#include <Arduino.h>

const int sensorPin = A1;//gbg92: Sets the potentiometer pin to A1


void setup() {
  Serial.begin(115200);
}

void loop() {
  int sensor_value = analogRead(sensorPin); /*gbg29: Reads the analog value
  from the potentiometer and stores it in sensor_value*/
  Serial.println(sensor_value); //gbg29: Prints the sesnor value to the Serial Monitor
  delay(50); 
} 
