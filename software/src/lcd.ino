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
    lcd.print("Booting...");
  //lcd.setCursor(0, 0); lcd.print("Status: null");
  //lcd.setCursor(0, 1); lcd.print("Moisture: null");
  //lcd.setCursor(0, 2); lcd.print("Temperature: null");
  //lcd.setCursor(0, 3); lcd.print("Water Level: null");
}

void lcd_clear_row(unsigned char row) {
    lcd.setCursor(0, row);
    lcd.print("                ");
    lcd.setCursor(0, row);
}

void lcd_update_status(struct lcd_status_t status) {
    /* message line */
    lcd_clear_row(0);
    lcd.print(status.message);

    /* humidity */
    lcd_clear_row(1);
    lcd.print(status.humidity, HEX);

    /* temperature */
    lcd_clear_row(2);
    lcd.print(status.temp);
    lcd.print((char) 223);
    lcd.print("F");
}
