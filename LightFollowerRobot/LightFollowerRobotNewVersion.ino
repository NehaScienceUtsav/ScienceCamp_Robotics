#define MLa 10 // left motor 1st pin
#define MLb 11 // left motor 2nd pin
#define MRa 12 // right motor 1st pin
#define MRb 13 // right motor 2nd pin
#define e1 3   // Right Motor Enable Pin EA
#define e2 5   // Left Motor Enable Pin EB

int LDR_Pin = 4;  // LDR Digital Pin

void setup() {
  pinMode(LDR_Pin, INPUT); // LDR Digital Pin
  pinMode(MLa, OUTPUT);    // Motors pins
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  analogWrite(e1, 255); // Set the motor speed to 0-255
  analogWrite(e2, 255);
}

void loop() {
  // Read LDR sensor value
  int LDR_Value = digitalRead(LDR_Pin);

  if (LDR_Value == HIGH) {
    // Move forward
    digitalWrite(MLa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);
  } else {
    // Stop
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
  }
}
