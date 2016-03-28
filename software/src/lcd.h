/**
 * lcd.h
 *
 * LCD status routines.
 */

#ifndef LCD_H
#define LCD_H

void lcd_init();
void lcd_clear_row(unsigned char row);
void lcd_update_status(String message, float humidity, float temp, float water_level);

#endif /* LCD_H */
