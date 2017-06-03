#ifndef ARRAY_H
#define ARRAY_H

#include "except.h"
#include "datatype.h"

typedef Scalar*              Array;

typedef const unsigned long  Row;
typedef const unsigned long  Column;
typedef const unsigned long  Size;

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

Array new_array(Size size);

void  zero(Array array, Size size);

#endif       /* ARRAY_H */
