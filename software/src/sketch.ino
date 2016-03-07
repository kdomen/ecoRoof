#include "lcd.h"
#include "temp.h"
#include "pump.h"
#include "matrix.h"
#include "config.h"

#include <Arduino.h>
#include <pins_arduino.h>

volatile int running_pump = NULL_PUMP;

void setup() {
    Serial.begin(9600);
    Serial.println("hello world!");

    lcd_init();
    pump_init();
    matrix_init();
    matrix_all_on();

    /* setup upper and lower control buttons */
    pinMode(UPPER_BUTTON_PIN, INPUT); digitalWrite(UPPER_BUTTON_PIN, HIGH);
    pinMode(LOWER_BUTTON_PIN, INPUT); digitalWrite(LOWER_BUTTON_PIN, HIGH);

    attachInterrupt(UPPER_BUTTON_INT, ub_isr, CHANGE);
    attachInterrupt(LOWER_BUTTON_INT, lb_isr, CHANGE);
}

void loop() {
    struct lcd_status_t status;
    status.temp = read_temp();

    // switch pumps
    set_pump(RESV_PUMP, LOW);
    set_pump(RBOX_PUMP, LOW);
    if (running_pump != NULL_PUMP)
        set_pump(running_pump, HIGH);

    status.message = running_pump == RESV_PUMP ? "irrigating..." : "raining...";

    lcd_update_status(status);
    delay(800);
}

void ub_isr() {
    Serial.println("upper");
    running_pump = RBOX_PUMP;
}

void lb_isr() {
    Serial.println("lower");
    running_pump = RESV_PUMP;
}
