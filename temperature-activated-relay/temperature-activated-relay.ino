#include "DHT.h"

#define DHT_TCH 2
#define DHT_TEXT 3

#define DHTTYPE DHT11

DHT dhtTch(DHT_TCH, DHTTYPE);
DHT dhtExt(DHT_TEXT, DHTTYPE);

int pinOut = 8;

void setup() {
  pinMode(pinOut, OUTPUT);

  Serial.begin(9600);

  dhtTch.begin();
  dhtExt.begin();
}

void loop() {
  delay(2000);

  float tCh = dhtTch.readTemperature();
  float tExt = dhtExt.readTemperature();

  if (isnan(tCh)) {
    Serial.println(F("Ocurrió un error al intentar leer la temperatura del techo."));
  } else {
    Serial.print(F("%  Temperatura techo: "));
    Serial.print(tCh);
    Serial.print(F("C "));
  }

  if (isnan(tExt)) {
    Serial.println(F("Ocurrió un error al intentar leer la temperatura exterior."));
  } else {
    Serial.print(F("%  Temperatura exterior: "));
    Serial.print(tExt);
    Serial.print(F("C "));
  }

  if (!isnan(tCh) && !isnan(tExt) && tCh > 26 && (tCh - tExt > 3)) {
    Serial.print("Temperatura techo y diferencia techo / exterior superiores a los parámetros establecidos. Encendiendo relé!");
    digitalWrite(pinOut, HIGH);
  } else {
    digitalWrite(pinOut, LOW);
  }

  Serial.println();
}