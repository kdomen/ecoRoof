/**
 * ultrasonic.ino
 *
 * Read and interpret ultrasonic sensor.
 */

#include "ultrasonic.h"
#include "config.h"

float read_water_level() {
    static float previous[50] = {0};

    double distance =
        microseconds_to_cm(
            ultrasonic_read());

    double perc = (RESV_HEIGHT - distance) / RESV_HEIGHT;

    for (int i = 0; i < 50; i++) {
        previous[i] = previous[i+1];
    }
    previous[49] = perc;

    double sum = 0;
    for (int i = 0; i < 50; i++) {
        sum += previous[i];
    }

    return sum/50;
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
