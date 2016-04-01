/**
 * pump.ino
 *
 * Pump control routines.
 */

#include "pump.h"
#include "config.h"

volatile bool lock = false;

void pump_init() {
    pinMode(RESV_PUMP, OUTPUT);
    pinMode(RBOX_PUMP, OUTPUT);
}

void set_pump(int pump, int state) {
    if (lock)
        return;

    lock = true;
    digitalWrite(pump, state);
    lock = false;
}
