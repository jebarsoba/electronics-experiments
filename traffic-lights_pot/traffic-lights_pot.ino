int ledDelay = 250;

int redPin = 10;
int yellowPin = 9;
int greenPin = 8;

bool flashEnabled = true;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int analog = analogRead(A0);
  Serial.println(analog);

  if (analog > 0 && analog < 250) {
    flashEnabled = false;
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  } else if (analog >= 250 && analog < 500) {
    flashEnabled = false;
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
  } else if (analog >= 500 && analog < 750) {
    flashEnabled = false;
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
  } else if (analog >= 750) {
    flashEnabled = true;
  } else if (analog == 0) {
    flashEnabled = false;
    off();
  }

  if (flashEnabled) {
    flash();
  }

  delay(20);
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
