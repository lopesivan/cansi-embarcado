#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "eq2.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- eq2g --------------------------------- *
 *                                                                           *
 *****************************************************************************/

Array eq2g(Scalar a, Scalar b, Scalar c)
{
    /*************************************************************************
     *                2                                                      *
     *      f(x) = a x  + b x + c                                            *
     *                                                                       *
     *************************************************************************/

    Scalar     delta          = DELTA(a,b,c);

    Scalar     real_part      = REAL_PART(a, b);

    Scalar     imaginary_part = IMAGINARY_PART(a, delta);

    Complex    x1,
               x2;

    if (delta >=0)
    {
        x1.real = real_part + imaginary_part;
        x2.real = real_part - imaginary_part;

        x1.imag = 0;
        x2.imag = x1.imag;

    } else {
        x1.real = real_part;
        x2.real = x1.real;

        x1.imag = imaginary_part;
        x2.imag = -x1.imag;
    }

    Array array = new_array(4);

    if is_null(array)
    {
        __error("Returned null!");
    }

    array[0] = x1.real;
    array[1] = x1.imag;
    array[2] = x2.real;;
    array[3] = x2.imag;

    return array;
}