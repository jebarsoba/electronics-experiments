#include "DHT.h"

#define DHT1PIN 2
#define DHT2PIN 3

#define DHTTYPE DHT11

DHT dht1(DHT1PIN, DHTTYPE);
DHT dht2(DHT2PIN, DHTTYPE);

int pinOut = 8;

void setup() {
  pinMode(8, OUTPUT);

  Serial.begin(9600);

  dht1.begin();
  dht2.begin();
}

void loop() {
  delay(2000);

  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();

  if (isnan(h1) || isnan(t1)) {
    Serial.println(F("Failed to read from DHT #1"));
  } else {
    Serial.print(F(" Humidity 1: "));
    Serial.print(h1);
    Serial.print(F("%  Temperature 1: "));
    Serial.print(t1);
    Serial.print(F("C "));
  }

  if (isnan(h2) || isnan(t2)) {
    Serial.println(F("Failed to read from DHT #2"));
  } else {
    Serial.print(F(" Humidity 2: "));
    Serial.print(h2);
    Serial.print(F("%  Temperature 2: "));
    Serial.print(t2);
    Serial.print(F("C "));
  }

  if (!isnan(t1) && !isnan(t2) && (t2 - t1 > 1)) {
    Serial.print("Sensor #2 is 1 degrees hotter than Sensor #1. Turning on the "
                 "lights...");
    digitalWrite(pinOut, HIGH);
  } else {
    digitalWrite(pinOut, LOW);
  }

  Serial.println();
}
