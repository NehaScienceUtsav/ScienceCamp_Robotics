void setup() {
  // Set pin modes
  pinMode(2, OUTPUT);
}

void loop() {
    digitalWrite(2, HIGH); // Turn on LED
    delay(1000); // 1000 milliseconds = 1 seconds
    digitalWrite(2, LOW); // Turn off LED
    delay(1000); // 1000 milliseconds = 1 seconds
}
