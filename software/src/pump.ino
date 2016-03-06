/**
 * pump.cpp
 *
 * Pump control routines.
 */

#include "pump.h"
#include "config.h"
#include <assert.h>

void pump_init() {
    pinMode(RESV_PUMP, OUTPUT);
    pinMode(RBOX_PUMP, OUTPUT);
}

void set_pump(int pump_pin, int state) {
    assert(state == HIGH || state == LOW);
    assert(pump_pin == RESV_PUMP || pump_pin == RBOX_PUMP);

    digitalWrite(pump_pin, state);
}
