/**
 * lcd.cpp
 *
 * LCD status routines.
 */

#include "lcd.h"
#include "config.h"

#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(LCD_RS, LCD_ENABLE, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void lcd_init() {
    /* setup contrast and backlight */
    pinMode(LCD_CONTRAST,      OUTPUT);
    pinMode(LCD_BACKLIGHT,     OUTPUT);
    analogWrite(LCD_CONTRAST,  (1.57) /5*255); /* 1.57V */
    analogWrite(LCD_BACKLIGHT, (3.20) /5*255); /* 3.20V */

    /* safety ground -- just in case! */
    pinMode(LCD_SAFETY_GROUND, OUTPUT);
    digitalWrite(LCD_SAFETY_GROUND, LOW);

    lcd.begin(16, 4);
    lcd.setCursor(0, 0); lcd.print("Status: null");
    lcd.setCursor(0, 1); lcd.print("Moisture: null");
    lcd.setCursor(0, 2); lcd.print("Temperature: null");
    lcd.setCursor(0, 3); lcd.print("Water Level: null");
}

void lcd_pump_status(String status) {
    lcd.setCursor(0, 0);
    lcd.print("Status: " + status);
}
