#include <Arduino.h>

const int sensorPin = 1; // Utilisation du GPIO 1 (ADC)
int reading = 0;
float voltage = 0;


void setup() {
  pinMode(sensorPin, INPUT); // Facultatif
  Serial.begin(115200);
}

void loop()
{
  reading = analogRead(sensorPin);
  voltage = reading * 3.3 / 4095.0;

  Serial.println(voltage);
  delay(800);
} 