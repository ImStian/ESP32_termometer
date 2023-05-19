// Libraries
#include <Adafruit_BME280.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// Config
#define SCREEN_WIDTH 128 // OLED width,  in pixels
#define SCREEN_HEIGHT 64 // OLED height, in pixels

// OLED display objekt I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
// BME Objekt I2C
Adafruit_BME280 bme;

void configure_bme(){// Konfigurerer BME280
    Serial.println("Sjekker koblingen til BME280:");
    if(!bme.begin(0x76)){
        Serial.println("ERROR: BME280 er ikke koblet riktig!");
        while(1); // Fanger script i evig løkke
    } Serial.println("BME280 er koblet riktig!");
}


////////////

void setup(){
    Serial.begin(9600);
    configure_bme();

    // initialisering av OLED display med I2C addresse 0x3C
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("failed to start SSD1306 OLED"));
    while (1);
  }
  delay(2000);         // wait two seconds for initializing

}

void loop(){
  float temperature = bme.readTemperature();
  oled.clearDisplay(); // clear display

  oled.setTextSize(2);         // set text size
  oled.setTextColor(WHITE);    // set text color
  oled.setCursor(0, 10);       // set position to display
  oled.println("Temperatur"); // set text
  oled.print(temperature); oled.println(" C");
  oled.display();              // display on OLED
    
}