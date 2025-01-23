#define VIBRATION_SENSOR_PIN 4 

void loop() {
  int metalDetected = digitalRead(METAL_SENSOR_PIN);
  int vibrationDetected = digitalRead(VIBRATION_SENSOR_PIN);

  if (metalDetected == HIGH) {
    Serial.println("Metal Detected!");
    lcd.setCursor(0, 0);
    lcd.print("Metal Detected!");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("No Metal        ");
  }

  if (vibrationDetected == HIGH) {
    Serial.println("Vibration Detected!");
    lcd.setCursor(0, 1);
    lcd.print("Vibration Alert!");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("No Vibration    ");
  }
  delay(500);
}
