/**
 * lcd.cpp
 *
 * LCD status routines.
 */

#include "lcd.h"
#include "config.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void lcd_init() {
    /* setup contrast and backlight */
    pinMode(LCD_CONTRAST,  OUTPUT);
    pinMode(LCD_BACKLIGHT, OUTPUT);
    analogWrite(LCD_CONTRAST,  (1.57) /5*255);
    analogWrite(LCD_BACKLIGHT, (3.20) /5*255);

    lcd.begin(16, 4);
    lcd.print("Status: ");
    lcd.setCursor(0, 1); lcd.print("Moisture: ");
    lcd.setCursor(0, 2); lcd.print("Temperature: ");
    lcd.setCursor(0, 3); lcd.print("Water Level: ");
}
