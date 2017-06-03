#ifndef COMPLEX
#define COMPLEX

#include "datatype.h"

struct _complex {
    Scalar real;
    Scalar imag;
};

typedef struct _complex complex;

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/


#define imagpart(cval)  (cval).imag
#define realpart(cval)  (cval).real

#endif       /* COMPLEX */
