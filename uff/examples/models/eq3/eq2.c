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

    if(a == 0.0)
    {
        __error("Quadratic equation is a second order polynomial with 3 coefficients - a, b, c.");
    }

    Array      array;

    Scalar     delta  = SQR(b) - 4*a*c;

    Scalar     PR     = -b/(2*a);

    Scalar     PI     = sqrt(fabs(delta))/(2*a);

    Scalar     PR1, PR2, PI1, PI2;

    if (delta >=0)
    {
        PR1 = PR + PI;
        PR2 = PR - PI;

        PI1 = 0;
        PI2 = PI1;

    } else {
        PR1 = PR;
        PR2 = PR1;

        PI1 = PI;
        PI2 = - PI1;
    }

    array = new_array(4);

    array[0] = PR1;
    array[1] = PI1;
    array[2] = PR2;
    array[3] = PI2;

    return array;
}
