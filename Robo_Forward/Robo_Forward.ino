#define enA 7 // Enable1 L298 Pin enA 
#define in1 10 // Motor1  L298 Pin in1 
#define in2 11 // Motor1  L298 Pin in1 
#define in3 12 // Motor2  L298 Pin in1 
#define in4 13 // Motor2  L298 Pin in1 
#define enB 6 // Enable2 L298 Pin enB 

void setup() { 
  // put your setup code here, to run once 
  pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
  pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
  pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
  pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
  pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
  pinMode(enB, OUTPUT); // declare as output for L298 Pin enB 

  analogWrite(enA, 180); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
  analogWrite(enB, 180); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
}

void loop() {

      forward(); // Corrected function name
      delay(3000);

}

void forward() { // Corrected function name
  digitalWrite(in1, HIGH); // Right Motor forward Pin 
  digitalWrite(in2, LOW);  // Right Motor backward Pin 
  digitalWrite(in3, HIGH); // Left Motor backward Pin 
  digitalWrite(in4, LOW);   // Left Motor forward Pin 
}
