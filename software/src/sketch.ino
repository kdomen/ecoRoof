#include "config.h"

#include "lcd.h"
#include "temp.h"
#include "pump.h"
#include "matrix.h"
#include "humidity.h"
#include "ultrasonic.h"

#include <Arduino.h>
#include <pins_arduino.h>

volatile unsigned int tick = 0x00;
volatile int running_pump = NULL_PUMP;
volatile unsigned char pump_duration = 0;

void setup() {
    lcd_init();
    pump_init();
    humidity_init();
    matrix_init();

    /* setup upper and lower control buttons
     * in interrupt mode AND pullup mode */
    pinMode(UPPER_BUTTON, INPUT);
    pinMode(LOWER_BUTTON, INPUT);
    digitalWrite(UPPER_BUTTON, HIGH);
    digitalWrite(LOWER_BUTTON, HIGH);
    attachInterrupt(UPPER_BUTTON_INT, ub_isr, FALLING);
    attachInterrupt(LOWER_BUTTON_INT, lb_isr, FALLING);
}

void loop() {
    unsigned int tick = 0;
    float temp, humidity, water_level;

    while (1) {
        tick++;
        delay(1);

        // switch pumps
        set_pump(RESV_PUMP, LOW);
        set_pump(RBOX_PUMP, LOW);
        if (running_pump != NULL_PUMP)
            set_pump(running_pump, HIGH);
        else
          //lcd_update_message("Waiting...");

        lcd_update_message(String(tick));

        if (--pump_duration == 0) {
            set_pump(RESV_PUMP, LOW);
            set_pump(RBOX_PUMP, LOW);
        }

        // every 100 ms
        if (tick % 1 == 100) {
            temp        = read_temp();
        }
            water_level = read_water_level();

        // once a second
        if (tick % 1000 == 0) {
            humidity  = humidity_read();
        }

        // every 500 ms
            lcd_update_status(humidity, temp, water_level);
            matrix_graph(water_level);
    }
}

void ub_isr() {
    running_pump = RBOX_PUMP;
    pump_duration = 1;
    lcd_update_message("Raining...");
}

void lb_isr() {
    running_pump = RESV_PUMP;
    pump_duration = 1;
    lcd_update_message("Irrigating...");
}
