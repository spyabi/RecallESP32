#include <FastLED.h>

const int buttonPin = 2;
const int NUM_LED = 6;
const int ledPin = 13; // LED pin number
int x = 0;
int myArray[] = {1, 0, 0, 0, 0, 0}; // Define array

CRGB strip_1[NUM_LED];

void setup() {
  pinMode(buttonPin, INPUT_PULLDOWN);
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
  FastLED.addLeds<WS2812B, ledPin, GRB>(strip_1, NUM_LED);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    // Button is pressed
    // Perform desired actions here
    Serial.println("Button pressed!");
    x += 1;
    myArray[x] = 1;
  FastLED.clear();
  // Iterate through the array
  for (int i = 0; i < NUM_LED; i++) {
    // Check if the current element of the array is equal to 1
    if (myArray[i] == 1) {
      Serial.println("CHANGE");
      // Light up the LED in red (simulate by printing a message)
      // Set the color of each LED individually
      strip_1[i] = CRGB(255, 0, 0);  // Set to red (RGB color: 255, 0, 0)
    } else {
      // Print a message indicating that the number is not equal to 1
      strip_1[i] = CRGB(0, 0, 0);  // Set to nothing
    }
  }

  FastLED.show();
  Serial.println("DONE"); // Delay for 1 second between each iteration
  // End of loop
  delay(500);
  }
}