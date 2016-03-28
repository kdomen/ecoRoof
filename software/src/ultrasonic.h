/**
 * ultrasonic.h
 *
 * Read and interpret ultrasonic sensor.
 */

#ifndef ULTRASONIC_H
#define ULTRASONIC_H

//#define RESV_HEIGHT 4 * 2.54 // 4 inches -> cm
#define RESV_HEIGHT 3.75 * 2.54

void ultrasonic_init();
float read_water_level();

#endif /* ULTRASONIC_H */
