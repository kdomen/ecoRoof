#include "config.h"

#include "lcd.h"
#include "temp.h"
#include "pump.h"
#include "matrix.h"
#include "humidity.h"
#include "ultrasonic.h"

#include <Arduino.h>
#include <pins_arduino.h>

volatile unsigned char tick = 0x00;
volatile int running_pump = NULL_PUMP;

void setup() {
    lcd_init();
    pump_init();
    humidity_init();
    matrix_init();
    matrix_all_on();

    /* lcd timer */
    TCCR1B |= (1 << WGM12);   // CTC mode
    TCCR1B |= (1 << CS12);    // 256 prescaler 
    TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
    OCR1A = 31250;            // compare match register 16MHz/256/2Hz
    interrupts(); 

    /* setup upper and lower control buttons */
    pinMode(UPPER_BUTTON, INPUT);
    pinMode(LOWER_BUTTON, INPUT);
    digitalWrite(UPPER_BUTTON, HIGH);
    digitalWrite(LOWER_BUTTON, HIGH);
    attachInterrupt(UPPER_BUTTON_INT, ub_isr, FALLING);
    attachInterrupt(LOWER_BUTTON_INT, lb_isr, FALLING);
}

void loop() {
    tick++;

    // switch pumps
    set_pump(RESV_PUMP, LOW);
    set_pump(RBOX_PUMP, LOW);
    if (running_pump != NULL_PUMP)
        set_pump(running_pump, HIGH);
    else
        lcd_update_message("Waiting...");

    static float temp, humidity, water_level;

    temp        = read_temp();
    humidity    = humidity_read();
    water_level = read_water_level();

    // write out status stuff to LCD
    if (tick > 8) {
        tick = 0;
        lcd_update_status(humidity, temp, water_level);
    }
}

ISR(TIMER1_COMPA_vect) {
}

void ub_isr() {
    running_pump = RBOX_PUMP;
    lcd_update_message("raining...");
}

void lb_isr() {
    running_pump = RESV_PUMP;
    lcd_update_message("irrigating...");
}
