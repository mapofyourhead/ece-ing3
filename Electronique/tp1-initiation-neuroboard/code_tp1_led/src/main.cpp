
///////////////////////////////
// INCLUSION DES BIBLIOTHEQUES //
// Sous VSCode PlatformIO //
///////////////////////////////
#include<NeuroBoardS3.h> //
//////////////////
// DECLARATIONS //
//////////////////
const int Led = 3;

////////////////////
// FONCTION SETUP //
////////////////////
void setup() {
  pinMode(Led, OUTPUT); // La broche 3 est une sortie
}
///////////////////
// FONCTION LOOP //
///////////////////
void loop() {
  digitalWrite(Led, HIGH); // Met la broche au niveau haut (3,3 V) : on allume la LED
  delay(500); // Pause de 500 ms
  digitalWrite(Led, LOW); // Met la broche au niveau bas (0 V) : on éteint la LED
  delay(500); // Pause de 500 ms
}