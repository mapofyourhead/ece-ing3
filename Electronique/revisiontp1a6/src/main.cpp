//SIMPLE BITCH LED
/*
#include<NeuroBoardS3.h>

//DDV
const int Led = 3;

void setup(){
  pinMode(Led,OUTPUT);
}

void loop(){
  digitalWrite(Led, HIGH);
  delay(500);
  digitalWrite(Led,LOW);
  delay(500);
}
  */

///*Bouton 



//DDC


#include <NeuroBoardS3.h>

const int Led = 5;

void setup() {
  Serial.begin(115200);
  pinMode(Led, OUTPUT);
}

void loop() {
  digitalWrite(Led, HIGH);
  Serial.println("GPIO 5 = HIGH");
  delay(3000);

  digitalWrite(Led, LOW);
  Serial.println("GPIO 5 = LOW");
  delay(3000);
}


/*
const int Led = 5;
const int Bouton = 6;

void setup()
{
  pinMode(Led, OUTPUT);
  pinMode(Bouton, INPUT);
}

void loop()
{
  if (digitalRead(Bouton) == HIGH)
{
    digitalWrite(Led, HIGH);
    delay(2000);
    digitalWrite(Led, LOW);
}
else{
  digitalWrite(Led,LOW);
}
}
//*/
