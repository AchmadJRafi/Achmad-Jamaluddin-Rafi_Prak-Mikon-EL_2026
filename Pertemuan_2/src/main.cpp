#include <Arduino.h>

const int potPin = 34;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  int rawADC = analogRead(potPin);

  float voltage = (rawADC / 4095.0) * 3.3;
  float resistance = (rawADC / 4095.0) * 10000.0;

  Serial.print("Raw ADC: ");
  Serial.print(rawADC);
  Serial.print("\t | Tegangan: ");
  Serial.print(voltage, 2);
  Serial.print(" V\t | Hambatan: ");
  Serial.print(resistance, 0);
  Serial.println(" Ohm");
}