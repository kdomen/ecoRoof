/**
 * lcd.ino
 *
 * LCD status routines.
 */

#include "lcd.h"
#include "config.h"

#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

volatile bool lock = false;

void lcd_init() {
    /* setup contrast and backlight */
    pinMode(LCD_CONTRAST,      OUTPUT);
    pinMode(LCD_BACKLIGHT,     OUTPUT);
    analogWrite(LCD_CONTRAST,  (1.57) /5*255); /* 1.57V */
    analogWrite(LCD_BACKLIGHT, (3.20) /5*255); /* 3.20V */

    /* safety ground -- just in case! */
    pinMode(LCD_SAFETY_GROUND, OUTPUT);
    digitalWrite(LCD_SAFETY_GROUND, LOW);

    lcd.begin(20, 4);
    lcd.print("ecoRoof v1.00");
}

void lcd_clear_row(unsigned char row) {
    lcd.setCursor(0, row);
    lcd.print("                    ");
    lcd.setCursor(0, row);
}

void lcd_update_message(String message) {
    if (lock)
        return;

    lock = true;

    lcd_clear_row(0);
    lcd.print(message);

    lock = false;
}

void lcd_update_status(float humidity, float temp, float water_level) {
    if (lock)
        return;

    lock = true;

    /* humidity */
    lcd_clear_row(1);
    if (humidity > 1.00)
        lcd.print(100.0 - random(500)/100.0, 2);
    else
        lcd.print(humidity * 100, 2);
    lcd.print("% humidity");

    /* temperature */
    lcd_clear_row(2);
    lcd.print(temp);
    lcd.print((char) 223);
    lcd.print("F");

    /* water level */
    lcd_clear_row(3);
    if (water_level < 0.0 || water_level > 1.0) {
        lcd.print("0.00");
    } else if (water_level == 1.0) {
        lcd.print("AAAHHH!!");
        return;
    } else {
        lcd.print(water_level * 100.0, 2);
    }
    lcd.print("% water level");

    lock = false;
}
