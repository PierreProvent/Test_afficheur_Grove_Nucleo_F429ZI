#include "mbed.h"
#include "LCD.h"

LCD::LCD(PinName sda, PinName scl):i2c(sda, scl)
{
    init();
}

void LCD::clear()
{
    sendCommand(?????????????);
    wait_us(1600);
}

void LCD::print(char *str)
{
    data[0] = 0x40;
    while(*str) {
        data[1] = *str;
        i2c.write(LCD_ADDRESS, data, 2);
        str++;
    }
}

void LCD::cursor(char col, char row)
{
    if(row == 0) {
        col = col | 0x80;
    } else {
        col = col | 0xc0;
    }
    sendCommand(col);
}

void LCD::sendCommand(char value)
{
    data[0] = 0x80 ; // Co = 1, RS = 0 (Command transmitted)
    data[1] = value;
    i2c.write(LCD_ADDRESS, data, 2);
}

void LCD::init()
{
    // Attendre au moins 30 ms après la mise en tension de la carte
    wait_ms(50);
    // Choisir le type d'affichage : 2 lignes de 5x8 points /caractère
    sendCommand(???????????????);
    // Attendre au moins 39 us
    wait_us(45);
    // Allumer l'afficheur, pas de curseur, il ne clignote pas
    sendCommand(????????????);
    // Attendre au moins 39 us
    wait_us(45);
    // Effacer l'afficheur
    ???????????????
    // Curseur se déplace à droite à chaque caractère, pas de "shift" de l'affichage
    sendCommand(0x06);
}
