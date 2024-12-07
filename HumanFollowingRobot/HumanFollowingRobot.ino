#define MLa 10 // left motor 1st pin 
#define MLb 11 // left motor 2nd pin 
#define MRa 12 // right motor 1st pin 
#define MRb 13 // right motor 2nd pin 
#define e1 3   // Right Motor Enable Pin EA
#define e2 5   // Left Motor Enable Pin EB

int IR_Left = 4;
int IR_Right = 7;

void setup() {
  pinMode(IR_Left, INPUT);  // IR1 DO pin 
  pinMode(IR_Right, INPUT); // IR2 DO pin 
  pinMode(MLa, OUTPUT); // Motors pins 
  pinMode(MLb, OUTPUT); 
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);

  analogWrite(e1, 255); // Set the motor speed to 0-255
  analogWrite(e2, 255);
}

void loop() {
  if (digitalRead(IR_Left) == HIGH && digitalRead(IR_Right) == HIGH) {
    // Stop
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW); 
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
  }

  if (digitalRead(IR_Left) == LOW && digitalRead(IR_Right) == HIGH) {
    // Move in the left direction
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);
  }

  if (digitalRead(IR_Left) == HIGH && digitalRead(IR_Right) == LOW) {
    // Move in the right direction
    digitalWrite(MLa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, LOW);
    digitalWrite(MRb, LOW);
  }

  if (digitalRead(IR_Left) == LOW && digitalRead(IR_Right) == LOW) {
    // Move in the forward direction 
    digitalWrite(MLa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);
  }
}
