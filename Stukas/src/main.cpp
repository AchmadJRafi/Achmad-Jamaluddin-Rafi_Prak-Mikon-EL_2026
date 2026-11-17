#include <Arduino.h>

const int potPin = 34;
const int in1 = 17;
const int in2 = 18;
const int pwmPin = 16;
const int stby = 19;

const int freq = 5000;
const int pwmChannel = 0;
const int resolution = 8;

void setup() {
  Serial.begin(115200);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(stby, OUTPUT);
  digitalWrite(stby, HIGH);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(pwmPin, pwmChannel);
}

void loop() {
  int potValue = analogRead(potPin);
  int pwmValue = map(potValue, 0, 4095, 0, 255);

  ledcWrite(pwmChannel, pwmValue);
  Serial.print("ADC: ");
  Serial.print(potValue);
  Serial.print("PWM: ");
  Serial.print(pwmValue);
  Serial.print("Duty: ");
  Serial.print(map(pwmValue, 0, 255, 0, 100));
  Serial.println("%");
  delay(15);
}