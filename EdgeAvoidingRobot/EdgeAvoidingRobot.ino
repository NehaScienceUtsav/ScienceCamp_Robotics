#define MLa 10//left motor 1st pin
#define MLb 11//left motor 2nd pin 
#define MRa 12//right motor 1st pin
#define MRb 13//right motor 2nd pin
#define Sensor 2
#define enB 5 // Enable2 L298 Pin enB
#define enA 3 // Enable1 L298 Pin enA

void setup(){ 
  pinMode(Sensor, INPUT);// declaring sensor pin as input pin f for Arduino 
  pinMode(MLa, OUTPUT);// declaring Motors pin as output pin
  pinMode(MLb, OUTPUT); 
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT); 
  Serial.begin(9600);
  analogWrite(enA, 160); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
  analogWrite(enB, 160); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
}

void loop(){
  int Sensorin=digitalRead(Sensor); 
  Serial.println(Sensorin);
  delay(100);
  if (Sensorin == LOW) // applying condition
  {
    //forward
    digitalWrite(MLa, HIGH);
    digitalWrite(MLb, LOW);
    digitalWrite(MRa, HIGH);
    digitalWrite(MRb, LOW);
  }
  else{
    //Stop
    digitalWrite(MLa, LOW);
    digitalWrite(MLb, LOW); 
    digitalWrite(MRa, LOW); 
    digitalWrite(MRb, LOW);
    delay(300);
    //backward 
    digitalWrite(MLa, LOW); 
    digitalWrite(MLb, HIGH); 
    digitalWrite(MRa, LOW); 
    digitalWrite(MRb, HIGH);
    delay(800);
    //Stop
    digitalWrite(MLa, LOW); 
    digitalWrite(MLb, LOW); 
    digitalWrite(MRa, LOW); 
    digitalWrite(MRb, LOW);
    delay(300);
    //Rightturn
    digitalWrite(MLa, HIGH); 
    digitalWrite(MLb, LOW); 
    digitalWrite(MRa, LOW); 
    digitalWrite(MRb, LOW);
    delay(500);
  }
}
