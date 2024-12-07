#define MLa 10 // left motor 1st pin
#define MLb 11 // left motor 2nd pin
#define MRa 12 // right motor 1st pin
#define MRb 13 // right motor 2nd pin
#define e1 3   // Right Motor Enable Pin EA
#define e2 5   // Left Motor Enable Pin EB

int LDR_Left = 4;   // LDR1 Digital Pin
int LDR_Right = 7;  // LDR2 Digital Pin

void setup() {
  pinMode(LDR_Left, INPUT);  // LDR1 Digital Pin
  pinMode(LDR_Right, INPUT); // LDR2 Digital Pin
  pinMode(MLa, OUTPUT);      // Motors pins
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  analogWrite(e1, 255); // Set the motor speed to 0-255
  analogWrite(e2, 255);
}

void loop() {
  // Read LDR sensor values (high or low)
  int LDR_Left_Value = digitalRead(LDR_Left);
  int LDR_Right_Value = digitalRead(LDR_Right);

  if (LDR_Left_Value == HIGH && LDR_Right_Value == HIGH) {
    // Stop
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
  }

  if (LDR_Left_Value == LOW && LDR_Right_Value == HIGH) {
    // Move in the left direction
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);
  }

  if (LDR_Left_Value == HIGH && LDR_Right_Value == LOW) {
    // Move in the right direction
    digitalWrite(MLa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
  }

  if (LDR_Left_Value == LOW && LDR_Right_Value == LOW) {
    // Move in the forward direction
    digitalWrite(MLa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);
  }
}
