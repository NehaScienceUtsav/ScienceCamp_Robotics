// Pin definitions
const int halleffectsensorPin = 2; // Touch sensor connected to pin D2
const int ledPin = 7;         // LED connected to pin D7

void setup() {
  // Set pin modes
  pinMode(halleffectsensorPin, INPUT); 
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the touch sensor state
  int sensorState = digitalRead(halleffectsensorPin);

  // If the touch sensor is HIGH, turn on the LED
  if (sensorState == LOW) {
    digitalWrite(ledPin, HIGH); // Turn on LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED
  }
}
