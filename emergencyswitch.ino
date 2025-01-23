#define EMERGENCY_SWITCH_PIN 5 

void setup() {
  pinMode(EMERGENCY_SWITCH_PIN, INPUT_PULLUP); 
}

void loop() {
  int buttonState = digitalRead(EMERGENCY_SWITCH_PIN);

  if (buttonState == LOW) { 
    Serial.println("Emergency Triggered!");
    lcd.clear();
    lcd.print("Emergency Mode!");
  }
}
