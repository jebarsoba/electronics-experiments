#define sensorPin A0

// Calibration constants
#define OPEN_AIR_THRESHOLD 590
#define DRY_SOIL_THRESHOLD 380
#define IDEAL_MIN_THRESHOLD 277

void setup() {
  Serial.begin(9600);
  Serial.println("=== Soil Moisture Sensor ===");
  Serial.println("Starting readings...");
  Serial.println("Calibration reference:");
  Serial.print("  Open air: ");
  Serial.print(OPEN_AIR_THRESHOLD);
  Serial.println("+");
  Serial.print("  Dry soil (needs watering): ");
  Serial.print(DRY_SOIL_THRESHOLD);
  Serial.println("+");
  Serial.print("  Ideal soil moisture: ");
  Serial.print(IDEAL_MIN_THRESHOLD);
  Serial.print("-");
  Serial.println(DRY_SOIL_THRESHOLD - 1);
  Serial.println("----------------------------------------");
  delay(1000);
}

void loop() {
  int value = analogRead(sensorPin);
  
  Serial.print("Raw reading: ");
  Serial.print(value);
  Serial.print(" | ");
  
  if (value >= OPEN_AIR_THRESHOLD) {
    Serial.println("OPEN AIR/NO CONTACT");
  }
  else if (value >= DRY_SOIL_THRESHOLD) {
    Serial.println("VERY DRY - Needs urgent watering");
  }
  else if (value >= IDEAL_MIN_THRESHOLD) {
    Serial.println("PERFECT - Ideal soil moisture");
  }
  else {
    Serial.println("VERY WET - Overwatered");
  }
  
  delay(1000);
}