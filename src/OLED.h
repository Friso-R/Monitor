#ifndef OLED_h
#define OLED_h

#include <string>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OLED
{

  public:
    void begin();
    
    void printVal(std::string str, 
                  float val, 
                  const char *decimals, 
                  int Ypos);
    void watering();

    void clear();
    void show();

  private:
};

#endif