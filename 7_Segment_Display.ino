#include <TM1637Display.h>

// Define the CLK and DIO pins for the TM1637 display module
#define CLK 9
#define DIO 8

// Create a TM1637Display object named 'display' with CLK and DIO pins
TM1637Display display(CLK, DIO);

void setup()
{
  // Start serial communication at a baud rate of 9600
  Serial.begin(9600);

  // Set the brightness of the display to full brightness
  display.setBrightness(0x0F);
  
  // Clear the display
  display.clear();
}

void loop()
{
  // Loop to display numbers from 1 to 25
  for (int count = 1; count <= 25; count++)
  {
    // Display the current number on the TM1637 display
    display.showNumberDec(count, true);

    // Print the count value to the serial monitor
    Serial.println("Current Number: " + String(count));

    // Wait for 500 milliseconds
    delay(500);
  }

  // Optionally, clear the display after completing the sequence
  display.clear();
  
  // Stop the loop (or you can repeat by removing the while(true) line)
  while (true) {}
}
