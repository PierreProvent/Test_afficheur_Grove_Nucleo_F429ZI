#include "mbed.h"
#include "LCD.h"

LCD lcd(PB_9,PB_8);
// PB_9 : I2C broche SDA platine Grove
// PB_8 : I2C broche SCL platine Grove
AnalogIn vsense(ADC_TEMP); // Capteur de température interne

int main()
{
    char chaine[17] ;
    float T ;
    lcd.cursor(3,0);
    lcd.print("T interne");
    while(1) {
        T = (vsense.read()*3.3f -0.76f)/2.5e-3f + 25 ;
        sprintf(chaine, "%.2f C", T);
        lcd.cursor(4,1);
        lcd.print(chaine);
        wait(1);
    }
}
