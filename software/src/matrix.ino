/**
 * matrix.cpp
 *
 * Matrix routines and animations.
 */

#include "matrix.h"
#include "config.h"

void matrix_init() {
    for (int i = MATRIX_ROW1; i >= 39; i -= 2) {
        pinMode(i, OUTPUT);
    }
}

void matrix_all_on() {
    for (int i = MATRIX_ROW1; i >= 39; i -= 2) {
        digitalWrite(i, HIGH);
    }
}

void matrix_all_off() {
    for (int i = MATRIX_ROW1; i >= 39; i -= 2) {
        digitalWrite(i, LOW);
    }
}
