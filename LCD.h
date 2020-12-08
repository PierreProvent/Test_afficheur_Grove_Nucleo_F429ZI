#include "mbed.h"

#define LCD_ADDRESS   (0x3E << 1)

class LCD
{
public:
    LCD(PinName sda, PinName scl);// constructor
    void clear();
    void print(char *str);
    void cursor(char col, char row);
private:
    char data[2];
    void init();
    void sendCommand(char value);
    I2C i2c;
};
