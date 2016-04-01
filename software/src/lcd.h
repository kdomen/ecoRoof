/**
 * lcd.h
 *
 * LCD status routines.
 */

#ifndef LCD_H
#define LCD_H

void lcd_init();
void lcd_clear_row(unsigned char row);

void lcd_update_status(String message);
void lcd_update_temp(float temp);
void lcd_update_humidity(float humidity);
void lcd_update_water_level(float wl);

#endif /* LCD_H */
