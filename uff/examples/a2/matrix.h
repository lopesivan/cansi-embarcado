#ifndef MATRIX_H
#define MATRIX_H

#include "narray.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

/*
A pointer to an incomplete type (hides the implementation details).
*/
typedef struct Matrix* MatrixPtr;

MatrixPtr createMatrix(size_t rows, size_t columns);

void destroyMatrix(MatrixPtr matrix);

#endif       /* MATRIX_H */
