#ifndef EQ2_H
#define EQ2_H

#include "array.h"
#include "util.h"
#include "complex.h"

#define DELTA(a, b, c)              (SQR((b)) - 4*(a)*(c))
#define REAL_PART(a, b)             (-(b)/(2*(a)))
#define IMAGINARY_PART(a, delta)    (sqrt(ABS((delta)))/(2*(a)))

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

Array eq2g(Scalar a, Scalar b, Scalar c);

#endif       /* EQ2_H */
