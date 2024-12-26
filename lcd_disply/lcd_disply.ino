#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.print("BIO MEDICAL ENGINEERING");
}

void loop() {
  // Move the cursor to the beginning of the second line
  lcd.setCursor(0, 1);

  // Scroll the text by shifting it leftwards by one position
  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(300); // Adjust the delay as per your preference for scrolling speed
  }
}

