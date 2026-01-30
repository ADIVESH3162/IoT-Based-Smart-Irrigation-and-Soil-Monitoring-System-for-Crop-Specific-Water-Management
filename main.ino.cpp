#include "config.h"
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
#define SOIL_PIN 34
#define RELAY_PIN 26

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Pump OFF

  dht.begin();
}

void loop() {
  int soilValue = analogRead(SOIL_PIN);
  float moisturePercent = map(soilValue, 4095, 0, 0, 100);

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  Serial.println("---- Sensor Data ----");
  Serial.print("Soil Moisture: ");
  Serial.print(moisturePercent);
  Serial.println(" %");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  controlIrrigation(moisturePercent);

  delay(3000);
}
