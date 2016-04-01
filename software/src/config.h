/**
 * config.h
 *
 * Configuration header, includes pin definitions.
 */

#ifndef CONFIG_H
#define CONFIG_H

/**
 * DS18B20 temperature sensor:
 *
 *   Red    - +5V
 *   Black  - GND
 *   Yellow - Signal
 *
 * (make sure this has the 4.7K pullup resistor between signal and 5V) */
#define TEMP_SIGNAL 22

/* reservoir and rainbox pump control */
#define RESV_PUMP 24 // to irrigate...
#define RBOX_PUMP 26 // to simulate rain...
#define NULL_PUMP -1 // don't pump at all

/* ultrasonic sensor */
#define US_SIGNAL 53

/* humidity sensor */
#define HUMIDITY_POWER  52
#define HUMIDITY_SIGNAL 15

/* main LCD */
#define LCD_CONTRAST 4
#define LCD_RS 5
#define LCD_SAFETY_GROUND 6
#define LCD_ENABLE 7
#define LCD_BACKLIGHT 13

/* LCD data pins */
#define LCD_D4 9
#define LCD_D5 10
#define LCD_D6 11
#define LCD_D7 12

/* matrix row control pins */
#define MATRIX_ROW0 49
#define MATRIX_ROW1 45
#define MATRIX_ROW2 41
#define MATRIX_ROW3 37
#define MATRIX_ROW4 33
#define MATRIX_ROW5 29
#define MATRIX_ROW6 25

/* control buttons */
#define UPPER_BUTTON 2 // blue wire   - triggers rain
#define LOWER_BUTTON 3 // orange wire - triggers irrigation
#define UPPER_BUTTON_INT 0
#define LOWER_BUTTON_INT 1

#endif /* CONFIG_H */
