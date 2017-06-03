#ifndef PYTHAGORAS
#define PYTHAGORAS

#include "datatype.h"

#define SQR(a) ((a) == 0.0 ? 0.0 : a*a)

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar pythagoras(Scalar a, Scalar b);

#endif       /* PYTHAGORAS */
