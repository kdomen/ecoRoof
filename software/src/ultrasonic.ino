/**
 * ultrasonic.ino
 *
 * Read and interpret ultrasonic sensor.
 */

#include "ultrasonic.h"
#include "config.h"

float read_water_level() {
    static float previous[5] = {0};

    double distance =
        microseconds_to_cm(
            ultrasonic_read());

    double perc = (RESV_HEIGHT - distance) / RESV_HEIGHT;

    previous[0] = previous[1];
    previous[1] = previous[2];
    previous[2] = previous[3];
    previous[3] = previous[4];
    previous[4] = perc;

    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += previous[i];
    }

    return sum/5;
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
