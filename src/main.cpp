#include <arduino.h>
#include <Wire.h>

#include "OLED.h"
#include "BMP.h"

#define SCL      17
#define SDA      18

BMP         bmp280;
OLED        oled;

void DisplayValues();

void setup() {
  Serial.begin(9600);

  bmp280.begin();
  oled.begin();
}

void loop() {
  static long lastUpdate = 0;
  long update = millis();
  if(update - lastUpdate > 5000){
    lastUpdate = update;
    bmp280.update();
    DisplayValues();
  }
}


/************************************************************
 *                           OLED                           *
 *                                                          *
 ************************************************************/

void DisplayValues(){
  
  float temperature = bmp280.temperature;
  float pressure    = bmp280.pressure;

  const char *integer = "%s%.0f";
  const char *twoDeci = "%s%.2f";

  oled.clear(); 

  oled.printVal("Temperature  ",  temperature, twoDeci, 2);
  oled.printVal("Pressure     ",  pressure,    integer, 3);

  oled.show();
  
}

