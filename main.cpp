#include "mbed.h"
 
Serial pc(USBTX, USBRX);

AnalogIn potentiometre(PC_3); // A2 connecteur Arduino
AnalogIn luminosite(PC_0); // A1 connecteur Arduino

DigitalOut led(PF_12); //D8 Connecteur Arduino

int main() {
    float val;
    
    pc.printf("\nExemple de conversion analogique-numerique\n");
    
    while(1) {
        val = potentiometre.read(); // Converts and read the analog input value (value from 0.0 to 1.0)
        val = val* 3300; // Change the value to be in the 0 to 3300 range
        pc.printf("Tension = %6.f mV\n", val);
        pc.printf("\033[1A");
        if (val > 1000) { // If the value is greater than 1V then switch the LED on
          led = 1;
        }
        else {
          led = 0;
        }
        wait(0.2); // 200 ms
    }
}
