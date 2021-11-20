// Remote control buttons codes:
// ON: -16321
// OFF: 16575
// Red: 8415
// Yellow: 10455
// Green: -24481
// Flash: -12241
// Strobe: -4081
// Fade: -14281
// Smooth: -6121

#include <IRremote.h>

int ledDelay = 250;

int redPin = 10;
int yellowPin = 9;
int greenPin = 8;

int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

bool flashEnabled = false;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (flashEnabled) {
    flash();
  }

  if (irrecv.decode(&results)) {
    int value = results.value;
    Serial.println(" ");
    Serial.print("Code: ");
    Serial.println(value);
    Serial.println(" ");

    switch (value) {
    case 8415:
      flashEnabled = false;
      digitalWrite(redPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(greenPin, LOW);
      break;
    case 10455:
      flashEnabled = false;
      digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      break;
    case -24481:
      flashEnabled = false;
      digitalWrite(greenPin, HIGH);
      digitalWrite(redPin, LOW);
      digitalWrite(yellowPin, LOW);
      break;
    case -12241:
      flashEnabled = true;
      break;
    case 16575:
      flashEnabled = false;
      off();
      break;
    }

    irrecv.resume();
  }
}

void flash() {
  off();

  digitalWrite(redPin, HIGH);
  delay(ledDelay);
  digitalWrite(redPin, LOW);

  digitalWrite(yellowPin, HIGH);
  delay(ledDelay);
  digitalWrite(yellowPin, LOW);

  digitalWrite(greenPin, HIGH);
  delay(ledDelay);
  digitalWrite(greenPin, LOW);
}

void off() {
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
}
