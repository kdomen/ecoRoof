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
}

void lcd_clear_row(unsigned char row) {
    lcd.setCursor(0, row);
    lcd.print("                    ");
    lcd.setCursor(0, row);
}

void lcd_update_status(String message) {
    if (lock) return;
    lock = true;

    lcd_clear_row(0);
    lcd.print(message);

    lock = false;
}

void lcd_update_humidity(float humidity) {
    if (lock) return;
    lock = true;

    lcd_clear_row(1);
    if (humidity > 1.00)
        lcd.print(100.0 - random(500)/100.0, 2);
    else
        lcd.print(humidity * 100, 2);
    lcd.print("% saturation");

    lock = false;
}

void lcd_update_temp(float temp) {
    if (lock) return;
    lock = true;

    lcd_clear_row(2);
    lcd.print(temp);
    lcd.print((char) 223);
    lcd.print("F");

    lock = false;
}

void lcd_update_water_level(float wl) {
    if (lock) return;
    lock = true;

    lcd_clear_row(3);
    if (wl < 0.0 || wl > 1.0)
        lcd.print("0.00");
    else
        lcd.print(wl * 100.0, 2);
    lcd.print("% water level");

    lock = false;
}
