#include <NeuroBoardS3.h>
const int analogPin = 2; // GPIO2 : Entrée analogique pour mesurer la tension du
condensateur
const int chargePin = 4; // GPIO4 : Broche numérique pour charger le condensateur
const int dischargePin = 5; // GPIO5 : Broche numérique pour décharger le condensateur
const float resistorValue = 9912.0; // Valeur réelle de la résistance mesurée au multimètre
(en Ohms)
const float adcCalibrationFactor = 4.07; // Facteur de compensation d'impédance du CAN de l'
ESP32-S3
unsigned long startTime;
unsigned long elapsedTime;
float microFarads;
void setup() {
Serial.begin(115200);
// Configuration spécifique de l'ADC pour l'ESP32-S3
analogReadResolution(12); // Résolution 12 bits (0 - 4095)
analogSetAttenuation(ADC_11db); // Atténuation 11 dB pour couvrir la plage de 0V à 3.3V
pinMode(chargePin, OUTPUT);
digitalWrite(chargePin, LOW);
pinMode(dischargePin, INPUT);
}
void loop() {
// 1. Décharge complète du condensateur pendant 500 ms
pinMode(dischargePin, OUTPUT);
digitalWrite(dischargePin, LOW);
digitalWrite(chargePin, LOW);
delay(500);
pinMode(dischargePin, INPUT); // Libération de la broche de décharge
// 2. Démarrage de la charge et démarrage du chronomètre
digitalWrite(chargePin, HIGH);
startTime = micros();
// 3. Attente jusqu'à atteindre le seuil de 63.2% (2588)
int adcVal = 0;
do {
adcVal = analogRead(analogPin);
} while (adcVal < 2588);
elapsedTime = micros() - startTime;
// 4. Arrêt de la charge
digitalWrite(chargePin, LOW);
// 5. Calcul de la capacité : C = (tau / R) * Facteur de calibration
microFarads = ((float)elapsedTime / resistorValue) * adcCalibrationFactor;
// Affichage du temps réel en ms et de la valeur en uF
Serial.print("Temps : ");
Serial.print(elapsedTime / 1000.0, 2);
Serial.print(" ms | Capacite : ");
Serial.print(microFarads, 2);
Serial.println(" microFarads");
delay(1000);
}
