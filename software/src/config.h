/**
 * config.h
 *
 * Configuration header, includes pin definitions.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* ultrasonic sensor */
#define US_SIGNAL 1

/* DS18B20 signal pin,
 * (make sure this has the 4.7K pullup resistor) */
#define TEMP_SIGNAL 22

/* reservoir and rainbox pump control */
#define RESV_PUMP 2
#define RBOX_PUMP 3

/* main LCD */
#define LCD_CONTRAST 4
#define LCD_RS 5
#define LCD_SAFETY_GROUND 6
#define LCD_ENABLE 7
#define LCD_BACKLIGHT 13

#define LCD_D4 9
#define LCD_D5 10
#define LCD_D6 11
#define LCD_D7 12

/* matrix row control pins */
#define MATRIX_ROW1 51
#define MATRIX_ROW2 49
#define MATRIX_ROW3 47
#define MATRIX_ROW4 45
#define MATRIX_ROW5 43
#define MATRIX_ROW6 41
#define MATRIX_ROW7 39

#endif /* CONFIG_H */
