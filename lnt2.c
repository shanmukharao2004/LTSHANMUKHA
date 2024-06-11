// Include the necessary libraries
#include <Arduino.h>

// Define pins for ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;

// Define variables
long duration;
int distance;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(trigPin, OUTPUT); // Set the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Set the echoPin as an INPUT
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distance= duration*0.034/2;
  
  // Print the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  delay(1000); // Wait for 1 second before next reading
}
\