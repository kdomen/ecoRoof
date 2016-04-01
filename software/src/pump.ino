/**
 * pump.ino
 *
 * Pump control routines.
 */

#include "pump.h"
#include "config.h"

void pump_init() {
    pinMode(RESV_PUMP, OUTPUT);
    pinMode(RBOX_PUMP, OUTPUT);
}

void set_pump(int pump, int state) {
    digitalWrite(pump, state);
}
