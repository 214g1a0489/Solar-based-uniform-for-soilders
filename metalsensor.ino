#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define METAL_SENSOR_PIN 3 // Digital pin for Metal Sensor

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address, 16x2 LCD

void setup() {
  pinMode(METAL_SENSOR_PIN, INPUT);
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  int metalDetected = digitalRead(METAL_SENSOR_PIN);

  if (metalDetected == HIGH) {
    Serial.println("Metal Detected!");
    lcd.setCursor(0, 0);
    lcd.print("Metal Detected!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("No Metal        ");
  }
  delay(500); // Update every 500ms
}
