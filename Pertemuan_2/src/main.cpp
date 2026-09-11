#include <Arduino.h>

const int potPin = 34;
const int buttonPin = 4;
const int ledRed = 18;
const int ledYellow = 19;
const int ledGreen = 21;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  int potValue = analogRead(potPin);

  if (buttonState == LOW) {
    digitalWrite(ledRed, LOW);
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);
  }
  else {
    if (potValue < 1365) {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, LOW);
    }
    else if (potValue >= 1365 && potValue < 2730) {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, HIGH);
      digitalWrite(ledGreen, LOW);
    }
    else {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledYellow, LOW);
      digitalWrite(ledGreen, HIGH);
    }
  }

  delay(100);
}