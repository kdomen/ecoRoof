/**
 * ultrasonic.h
 *
 * Read and interpret ultrasonic sensor.
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#define RESV_HEIGHT 10.5 // centimeters

void ultrasonic_init();
float read_water_level();

#endif /* ULTRASONIC_H */
