#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "eq3.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- eq3g --------------------------------- *
 *                                                                           *
 *****************************************************************************/

Array eq3g(Scalar a, Scalar b, Scalar c, Scalar d)
{

    /*************************************************************************
     *                3      2                                               *
     *      f(x) = a x  + b x + c x + d                                      *
     *                                                                       *
     *************************************************************************/

    Scalar    B = b/a,
              C = c/a,
              D = d/a;

    Scalar    P     = (3*C - SQR(B))/9;

    Scalar    Q     = B*C/6 - CUBE(B)/27 - D/2;

    Scalar    delta = CUBE(P) + SQR(Q);

    Complex   x3;

    if (delta >=0)
    {

        x3.real =  cbrt(Q + sqrt(delta)) +
                   cbrt(Q - sqrt(delta)) +
                                   - B/3
        ;

    } else {

        Scalar teta = acos(Q /
                    sqrt(CUBE(ABS(P)))
        );

        x3.real     = 2*sqrt(ABS(P))*cos(teta /3) -B/3;
    }

    x3.imag = 0;

    Array  array = new_array(6),
           temp  = eq2g(1, B+x3.real, -D/x3.real);

    if is_null(array)
    {
        __error("Returned null!");
    }

    array[0] = temp[0]; /* X1 */
    array[1] = temp[1];
    array[2] = temp[2]; /* X2 */
    array[3] = temp[3];
    array[4] = x3.real; /* X3 */
    array[5] = x3.imag;

    free(temp);

    return array;

}
