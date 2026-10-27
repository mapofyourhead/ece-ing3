//Hello world !
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // Largeur de l'écran OLED, en pixels
#define SCREEN_HEIGHT 64 // Hauteur de l'écran OLED, en pixels

// Déclaration de l'écran connecté en I2C (pins SDA et SCL)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
void setup() {
Serial.begin(115200);

if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
  Serial.println(F("SSD1306 allocation failed"));
  for(;;);
}
delay(2000);
display.clearDisplay();
display.setTextSize(1);
display.setTextColor(WHITE);
display.setCursor(0, 10);
display.println("I love you, honey!");
display.display();
}
void loop() {
}
//*/

/*
//Display Tension of Potentiometer
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int sensorPin = 1;
int reading = 0;
float voltage = 0;

void setup()
{
    Serial.begin(115200);

    Wire.begin(8, 9);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("SSD1306 allocation failed");
        for (;;);
    }

    display.setTextColor(WHITE);
}

void loop()
{
    // Lecture du potentiometre
    reading = analogRead(sensorPin);
    voltage = reading * 3.3 / 4095.0;

    // Affichage de la tension sur l'OLED
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 15);
    display.print(voltage, 2);
    display.println(" V");
    display.display();

    delay(800);
}
    */