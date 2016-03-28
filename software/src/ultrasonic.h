/**
 * ultrasonic.h
 *
 * Read and interpret ultrasonic sensor.
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

/**
 * note: the actual distance is 10.5 cm,
 * but our sensor reads ~13.5 cm -- so we will use that
 */
#define RESV_HEIGHT 13.5 // centimeters

void ultrasonic_init();
float read_water_level();

#endif /* ULTRASONIC_H */
