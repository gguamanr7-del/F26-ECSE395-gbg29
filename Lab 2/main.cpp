#include <Arduino.h>
// This is required in PlatformIO but hidden in the standard Arduino IDE.

#define LED_PIN 13

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200); // gbg29 - Start the Serial connection and defined the baud rate a recommended rate 
}

void loop() {
  Serial.println("Bum    Bum\n"); // gbg29 - Print the words "Bum Bum" to the Serial Monitor.
  // gbg29 - Setup a frequency similar to a heartbeat
  digitalWrite(LED_PIN, HIGH); // LED On
  delay(100); // gbg29
  digitalWrite(LED_PIN, LOW); // LED Off
  delay(80); // gbg29
  digitalWrite(LED_PIN, HIGH); // gbg29 - LED On
  delay(100); //gbg29
  digitalWrite(LED_PIN, LOW); // LED gbg29 - Off
  delay(400); //gbg29
}