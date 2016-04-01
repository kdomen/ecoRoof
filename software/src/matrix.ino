/**
 * matrix.ino
 *
 * Matrix routines and animations.
 */

#include "matrix.h"
#include "config.h"

static const int rows[] = {
    MATRIX_ROW0,
    MATRIX_ROW1,
    MATRIX_ROW2,
    MATRIX_ROW3,
    MATRIX_ROW4,
    MATRIX_ROW5,
    MATRIX_ROW6
};

/**
 * matrix_init()
 *
 * Set all matrix pins to output mode.
 */
void matrix_init() {
    for (int i = 0; i < sizeof(rows); i++) {
        pinMode(rows[i], OUTPUT);
    }
}

/**
 * matrix_set_row()
 *
 * row:   value between 0 and 6 (inclusive)
 * state: HIGH or LOW
 */
void matrix_set_row(int row, int state) {
    digitalWrite(rows[row], state);
}

/**
 * matrix_set_all()
 *
 * Set all matrix rows to a given state.
 *
 * state: HIGH or LOW
 */
void matrix_set_all(int state) {
    for (int i = 0; i < 7; i++) {
        matrix_set_row(i, state);
    }
}

/**
 * matrix_graph()
 *
 * Creates a bar graph filling the given percentage of LED rows.
 *
 * percentage: a float value between 0.00 and 1.00 (inclusive)
 */
void matrix_graph(float percentage) {
    int top = (int) ceil(percentage * 7.00);

    matrix_set_all(LOW);

    while (top--) {
        matrix_set_row(top, HIGH);
    }
}
