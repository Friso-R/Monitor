#ifndef BMP_h
#define BMP_h

#include <Adafruit_BMP280.h>

class BMP
{

  public:
    void begin();
    void update();
    void test();
    
    float temperature;
    float pressure;

  private:
};

#endif