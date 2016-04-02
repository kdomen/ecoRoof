#include "config.h"

#include "lcd.h"
#include "temp.h"
#include "pump.h"
#include "matrix.h"
#include "humidity.h"
#include "ultrasonic.h"

#include <EEPROM.h>
#include <Arduino.h>
#include <pins_arduino.h>

volatile unsigned int tick = 0x00;
volatile int running_pump = 0;
volatile int pump_duration = 0;

void setup() {
    unsigned char contrast = 81;
    contrast = EEPROM.read(LCD_CONTRAST_ADDR);

    lcd_init(contrast);
    pump_init();
    humidity_init();
    matrix_init();

    lcd_update_status("Waiting...");

    /* setup upper and lower control buttons in pullup mode */
    pinMode(UPPER_BUTTON, INPUT);
    pinMode(LOWER_BUTTON, INPUT);
    digitalWrite(UPPER_BUTTON, HIGH);
    digitalWrite(LOWER_BUTTON, HIGH);

    /* check if we are in config mode */
    if (!digitalRead(UPPER_BUTTON) && !digitalRead(LOWER_BUTTON)) {
        lcd_update_status("CONFIG");

        while (1) {
            int ub = !digitalRead(UPPER_BUTTON);
            int lb = !digitalRead(LOWER_BUTTON);

            if (ub && !lb)
                analogWrite(LCD_CONTRAST, --contrast);
            else if (!ub && lb)
                analogWrite(LCD_CONTRAST, ++contrast);

            if (contrast > 160)
                contrast = 160;

            // only read/write if a button was pressed
            if (ub || lb) {
            lcd_update_status(String(contrast));
                if (EEPROM.read(LCD_CONTRAST_ADDR) != contrast)
                    EEPROM.write(LCD_CONTRAST_ADDR, contrast);
            }

            delay(10);
        }
    }

    /* enable button interrupts */
    attachInterrupt(UPPER_BUTTON_INT, ub_isr, FALLING);
    attachInterrupt(LOWER_BUTTON_INT, lb_isr, FALLING);
}

void loop() {
    int tick = 0;

    lcd_update_temp(42.00);
    lcd_update_humidity(0.42);
    lcd_update_water_level(0.42);

    while (1) {
        if (++tick > 999)
            tick = 0;

        // set pumps
        set_pump(RESV_PUMP, LOW);
        set_pump(RBOX_PUMP, LOW);

        if (--pump_duration > 0) {
            set_pump(running_pump, HIGH);
        } else {
            pump_duration = 0;
            running_pump = NULL_PUMP;
        }

        // update status
        if (tick % 5 == 0) {
            String cd = String((int) pump_duration / 10 + 1);

            if      (running_pump == NULL_PUMP) lcd_update_status("Waiting... ");
            else if (running_pump == RBOX_PUMP) lcd_update_status("Raining... " + cd);
            else if (running_pump == RESV_PUMP) lcd_update_status("Irrigating... " + cd);
        }

        // temp
        lcd_update_temp(read_temp());

        // water level
        float wl = read_water_level();
        if (tick % 6 == 0)
            lcd_update_water_level(wl);
        matrix_graph(wl);

        // humidity
        if (tick % 200 == 0) {
            lcd_update_humidity(humidity_read());
        }
    }
}

void ub_isr() {
    running_pump = RBOX_PUMP;
    pump_duration = 100;
}

void lb_isr() {
    running_pump = RESV_PUMP;
    pump_duration = 50;
}
