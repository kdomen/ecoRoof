/**
 * lcd.h
 *
 * LCD status routines.
 */

#ifndef LCD_H
#define LCD_H

void lcd_init();
void lcd_pump_status(String status);
void lcd_temp_status(float temp);

#endif /* LCD_H */
