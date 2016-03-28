/**
 * lcd.h
 *
 * LCD status routines.
 */

#ifndef LCD_H
#define LCD_H

struct lcd_status_t {
    String message;
    float humidity;
    float temp;
    float water_level;
};

void lcd_init();
void lcd_clear_row(unsigned char row);
void lcd_update_status(struct lcd_status_t status);

#endif /* LCD_H */
