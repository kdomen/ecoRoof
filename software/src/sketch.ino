#include "config.h"

#include "lcd.h"
#include "temp.h"
#include "pump.h"
#include "matrix.h"
#include "humidity.h"
#include "ultrasonic.h"

#include <Arduino.h>
#include <pins_arduino.h>

volatile int running_pump = NULL_PUMP;

void setup() {
    Serial.begin(9600);
    Serial.println("hello world!");

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
    unsigned long tick = millis();

    // switch pumps
    set_pump(RESV_PUMP, LOW);
    set_pump(RBOX_PUMP, LOW);
    if (running_pump != NULL_PUMP)
        set_pump(running_pump, HIGH);

    struct lcd_status_t status;
    status.temp = read_temp();
    status.message = running_pump == RESV_PUMP ? "irrigating..." : "raining...";
    status.humidity = humidity_read();
    status.water_level = read_water_level();
    lcd_update_status(status);
}

ISR(TIMER1_COMPA_vect) {
}

void ub_isr() {
    running_pump = RBOX_PUMP;
}

void lb_isr() {
    running_pump = RESV_PUMP;
}
