#include <NewPing.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 8
#define MAX_DISTANCE 300

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Motor A
int motor1Pin1 = 10; // Input 1
int motor1Pin2 = 11; // Input 2
int enablePin1 = 3; // Enable 1

// Motor B
int motor2Pin1 = 12; // Input 3
int motor2Pin2 = 13; // Input 4
int enablePin2 = 5; // Enable 2

void setup() {
  // Ultrasonic sensor setup
  Serial.begin(9600);

  // Motor control pins as output
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);
}

void loop() {
  delay(50);
  unsigned int distance = sonar.ping_cm();

  // Print the distance for debugging
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Obstacle avoidance logic
  if (distance > 10) { // If no obstacle in front
    // Move forward
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    analogWrite(enablePin1, 255);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enablePin2, 255);
  } else {
    // Stop and turn
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    analogWrite(enablePin1, 0);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enablePin2, 0);

    // Reverse and turn right
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    analogWrite(enablePin1, 255);
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enablePin2, 255);

    delay(500); // Turn for 1 second

    // Stop
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
    analogWrite(enablePin1, 0);
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enablePin2, 0);
  }
}

