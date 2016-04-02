/**
 * ultrasonic.ino
 *
 * Read and interpret ultrasonic sensor.
 */

#include "ultrasonic.h"
#include "config.h"

#define N 15

float read_water_level() {
    static float previous[N] = {0};

    double distance =
        microseconds_to_cm(
            ultrasonic_read());

    double perc = (RESV_HEIGHT - distance) / RESV_HEIGHT;

    perc /= 0.68;
    if (perc > 1.00)
        perc = 1.00;

    for (int i = 0; i < N; i++) {
        previous[i] = previous[i+1];
    }
    previous[N-1] = perc;

    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += previous[i];
    }

    return sum/N;
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
