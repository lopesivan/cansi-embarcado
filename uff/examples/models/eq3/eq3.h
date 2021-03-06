#ifndef EQ3_H
#define EQ3_H

#include "eq2.h"

#define CUBE(a) ((a) == 0.0 ? 0.0 : (a*a*a))

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

Array eq3g(Scalar a, Scalar b, Scalar c, Scalar d);

#endif       /* EQ3_H */
