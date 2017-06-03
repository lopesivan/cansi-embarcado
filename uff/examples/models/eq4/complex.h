#ifndef COMPLEX
#define COMPLEX

#include "datatype.h"

typedef struct _complex {
    Scalar real;
    Scalar imag;
} Complex;

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

#define imagpart(cval)  (cval).imag
#define realpart(cval)  (cval).real

#endif       /* COMPLEX */
