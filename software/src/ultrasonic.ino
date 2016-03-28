/**
 * ultrasonic.ino
 *
 * Read and interpret ultrasonic sensor.
 */

#include "ultrasonic.h"
#include "config.h"

float read_water_level() {
    double distance =
        microseconds_to_cm(
            ultrasonic_read());

    return distance - 4;
  //return (RESV_HEIGHT - distance + 4) / RESV_HEIGHT;
}

unsigned long ultrasonic_read() {
    // give sensor a low signal for 2 us
    pinMode(US_SIGNAL, OUTPUT);
    digitalWrite(US_SIGNAL, LOW);
    delayMicroseconds(2);
    
    // give it a high signal for 5 us
    digitalWrite(US_SIGNAL, HIGH);
    delayMicroseconds(5);
    digitalWrite(US_SIGNAL, LOW);
    
    // measure the return pulse length
    pinMode(US_SIGNAL, INPUT);
    return pulseIn(US_SIGNAL, HIGH);
}

double microseconds_to_cm(long us) {
    return ((double) us)/29/2;
}
