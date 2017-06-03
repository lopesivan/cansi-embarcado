#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "eq4.h"

Array eq4g(Scalar a, Scalar b, Scalar c, Scalar d, Scalar e)
{

    /*************************************************************************
     *                4      3     2                                         *
     *      f(x) = a x  + b x + c x + d x + e                                *
     *                                                                       *
     *************************************************************************/

    Array     array = new_array(8),
              temp;

    if is_null(array)
    {
        __error("Returned null!");
    }

    Scalar    B3 = b/a,
              B2 = c/a,
              B1 = d/a,
              B0 = e/a;

    Scalar    B  = -B2,
              C  = B1*B3 - 4*B0,
              D  = B0*(4*B2 - SQR(B3)) - SQR(B1);


    temp = eq3g(1, B, C, D);

    int i;
    for (i = 0; i < 6; ++i)
    {
        array[i] = temp[i];
    }

    free(temp);

    Scalar   Y3 = array[4]; /* maior raiz real da equação cúbica */

    Scalar    A = B3/2;

    B = Y3/2;
    D = sqrt(SQR(B) - B0);

    if (!is_zero(D))
        C = (A*B -B1/2)/D;
    else
        C = sqrt(SQR(A) -B2 + 2*B);

    temp = eq2g(1, A - C, B - D);

    array[4] = temp[0];
    array[5] = temp[1];
    array[6] = temp[2];
    array[7] = temp[3];

    free(temp);

    temp = eq2g(1, A+C, B+D);

    for (i = 0; i < 4; ++i)
    {
        array[i] = temp[i];
    }

    free(temp);

    return array;

}
