#define PELTIER_PIN 6 // Digital pin for Peltier control

void setup() {
  pinMode(PELTIER_PIN, OUTPUT);
}

void loop() {
  if (temperature < 18) {
    digitalWrite(PELTIER_PIN, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Heating On");
  } else if (temperature > 30) { 
    digitalWrite(PELTIER_PIN, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Cooling On");
  } else {
    digitalWrite(PELTIER_PIN, LOW);
  }
}
