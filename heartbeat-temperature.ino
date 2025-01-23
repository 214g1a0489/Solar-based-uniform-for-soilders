
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD Initialization
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust address if needed

// Pin Definitions
const int pulsePin = A0;  // Pulse sensor connected to A0
const int tempPin = A1;   // Temperature sensor (e.g., LM35) connected to A1

// Variables for Heartbeat
int pulseValue = 0;
int bpm = 0;
unsigned long lastBeatTime = 0;

// Variables for Temperature
float temperature = 0.0;

void setup() {
  lcd.begin(16, 2);       // Initialize LCD
  lcd.backlight();        // Turn on LCD backlight
  pinMode(pulsePin, INPUT);
  pinMode(tempPin, INPUT);
  Serial.begin(9600);     // For debugging
  
  lcd.setCursor(0, 0);
  lcd.print("Heartbeat & Temp");
  delay(2000);
}

void loop() {
  // Heartbeat Measurement
  pulseValue = analogRead(pulsePin); // Read pulse sensor value
  if (pulseValue > 512) {           // Threshold to detect beat
    unsigned long currentTime = millis();
    if (currentTime - lastBeatTime > 600) { // Minimum interval to avoid false beats
      bpm = 60000 / (currentTime - lastBeatTime);
      lastBeatTime = currentTime;
    }
  }

  // Temperature Measurement
  int tempValue = analogRead(tempPin);             // Read temperature sensor value
  temperature = (tempValue * 5.0 * 100) / 1024.0;  // Convert to Celsius (for LM35)

  // Display on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BPM: ");
  lcd.print(bpm);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  // Debugging in Serial Monitor
  Serial.print("BPM: ");
  Serial.print(bpm);
  Serial.print(", Temp: ");
  Serial.print(temperature);
  Serial.println(" C");

  delay(1000); // Update every second
}
