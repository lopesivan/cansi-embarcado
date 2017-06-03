#ifndef EQ2_H
#define EQ2_H

#include "array.h"

#define SQR(a) ((a) == 0.0 ? 0.0 : a*a)

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

Array eq2g(Scalar a, Scalar b, Scalar c);

#endif       /* EQ2_H */