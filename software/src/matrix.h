/**
 * matrix.h
 *
 * Matrix routines and animations.
 */

#ifndef MATRIX_H
#define MATRIX_H

void matrix_init();
void matrix_set_row(int row, int state);
void matrix_set_all(int state);
void matrix_graph(float percentage);

#endif /* MATRIX_H */
