#include <Arduino.h>

const int buttonPin = 14;
const int ledPin1 = 27;
const int ledPin2 = 26;
const int ledPin3 = 25;

void setup() {
  pinMode(14, INPUT_PULLDOWN);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH)
  {
    digitalWrite(27, HIGH);
    digitalWrite(26, HIGH);
    digitalWrite(25, HIGH);
  }
  else{
    digitalWrite(27, LOW);
    digitalWrite(26, LOW);
    digitalWrite(25, LOW);
  }
}