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
#define NULL_PUMP -1 // do not pump at all

/* ultrasonic sensor */
#define US_SIGNAL 42

/* humidity sensor */
#define HUMIDITY_POWER  52
#define HUMIDITY_SIGNAL 15

/* main LCD */
#define LCD_CONTRAST 4
#define LCD_RS 5
#define LCD_SAFETY_GROUND 6
#define LCD_ENABLE 7
#define LCD_BACKLIGHT 13
#define LCD_CONTRAST_ADDR 0x00 // eeprom address

/* LCD data pins */
#define LCD_D4 9
#define LCD_D5 10
#define LCD_D6 11
#define LCD_D7 12

/* matrix row control pins */
#define MATRIX_ROW0 40
#define MATRIX_ROW1 38
#define MATRIX_ROW2 36
#define MATRIX_ROW3 34
#define MATRIX_ROW4 32
#define MATRIX_ROW5 30
#define MATRIX_ROW6 28

/* control buttons */
#define UPPER_BUTTON 2 // blue wire   - triggers rain
#define LOWER_BUTTON 3 // orange wire - triggers irrigation
#define UPPER_BUTTON_INT 0
#define LOWER_BUTTON_INT 1

#endif /* CONFIG_H */
