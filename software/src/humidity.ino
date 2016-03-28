/**
 * humidity.ino
 *
 * Analog reading and digital control of humidity sensor.
 */

#include "humidity.h"
#include "config.h"

void humidity_init() {
    pinMode(HUMIDITY_POWER, OUTPUT);
    digitalWrite(HUMIDITY_POWER, LOW);
}

float humidity_read() {
    digitalWrite(HUMIDITY_POWER, HIGH);
    int val = analogRead(HUMIDITY_SIGNAL);
    digitalWrite(HUMIDITY_POWER, LOW);

    return val / 616;
}
