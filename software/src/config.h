/**
 * config.h
 *
 * Configuration header, includes pin definitions.
 */

#ifndef CONFIG_H
#define CONFIG_H

/* ultrasonic sensor */
#define US_SIGNAL 1

/* reservoir and rainbox pump control */
#define RESV_PUMP_CONTROL 2
#define RBOX_PUMP_CONTROL 3

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

#endif /* CONFIG_H */
