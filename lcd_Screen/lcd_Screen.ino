#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);
  lcd.init();                      // Initialize the LCD
  lcd.backlight();
  lcd.setCursor(0, 0);                 // Turn on backlight           // Set cursor to beginning of first line
  lcd.print("Hello");      // Print a message to the LCD
  lcd.setCursor(0,3);                 // Turn on backlight           // Set cursor to beginning of first line
  lcd.print("TESTING");
}

void loop() {
    Serial.println("HELLO1");
  // Your loop code here
}

