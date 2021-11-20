int ledDelay = 250;

int redPin = 10;
int yellowPin = 9;
int greenPin = 8;

bool flashEnabled = false;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int analog = analogRead(A0);
  int digital = map(analog, 0, 1023, 0, 9);
  Serial.println(analog);
  Serial.println(digital);

  if (digital > 0 && digital < 3) {
    flashEnabled = false;
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  } else if (digital >= 3 && digital < 6) {
    flashEnabled = false;
    digitalWrite(yellowPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
  } else if (digital >= 6 && digital < 9) {
    flashEnabled = false;
    digitalWrite(greenPin, HIGH);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
  } else if (digital == 9) {
    flashEnabled = true;
  } else if (digital == 0) {
    flashEnabled = false;
    off();
  }

  if (flashEnabled) {
    flash();
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
