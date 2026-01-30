
#define MOISTURE_THRESHOLD 40  // crop-specific threshold

void controlIrrigation(float moisture) {
  if (moisture < MOISTURE_THRESHOLD) {
    Serial.println("Soil dry → Pump ON");
    digitalWrite(26, LOW);   // Relay ON
  } else {
    Serial.println("Soil moist → Pump OFF");
    digitalWrite(26, HIGH);  // Relay OFF
  }
}
