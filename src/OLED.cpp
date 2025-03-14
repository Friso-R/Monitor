#include "OLED.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void OLED::begin() 
{
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void OLED::printVal(std::string str, float val, const char *decimals, int Ypos) {
  display.setCursor(0, Ypos*10);

  // Format string with two decimal places
  char formattedString[20];
  sprintf(formattedString, decimals, str.c_str(), val);

  // Print the formatted string on the OLED display
  display.println(formattedString);
}

void OLED::clear(){  display.clearDisplay();  }
void OLED::show() {  display.display();       }


