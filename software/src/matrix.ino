/**
 * matrix.ino
 *
 * Matrix routines and animations.
 */

#include "matrix.h"
#include "config.h"

void matrix_init() {
    for (int i = MATRIX_ROW1; i >= 27; i -= 4) {
        pinMode(i, OUTPUT);
    }
}

void matrix_all_on() {
    for (int i = MATRIX_ROW1; i >= 27; i -= 4) {
        digitalWrite(i, HIGH);
    }
}

void matrix_all_off() {
    for (int i = MATRIX_ROW1; i >= 27; i -= 4) {
        digitalWrite(i, LOW);
    }
}
