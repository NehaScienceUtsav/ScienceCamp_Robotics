// Pin definitions
const int irsensorPin = 2; // Touch sensor connected to pin D2
const int ledPin = 7;         // LED connected to pin D7

void setup() {
  // Set pin modes
  pinMode(ldrsensorPin, INPUT); 
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the touch sensor state
  int sensorState = digitalRead(ldrsensorPin);

  // If the touch sensor is HIGH, turn on the LED
  if (sensorState == LOW) {
    digitalWrite(ledPin, HIGH); // Turn on LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off LED
  }
}
