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

    if(a == 0)
    {
        __error("Cubic equation is a third order polynomial with 4 coefficients - a, b, c, d.");
    }

    Array     array,
              temp;

    Scalar    B = b/a,
              C = c/a,
              D = d/a;

    Scalar    P = (3*C - SQR(B))/9;

    Scalar    Q = B*C/6 - CUBE(B)/27 - D/2;

    Scalar    delta = CUBE(P) + SQR(Q);

    Scalar    PR3,
              PI3;

    if (delta >=0)
    {

        PR3 =  pow(Q + sqrt(delta), (1.0/3.0)) +
               pow(Q - sqrt(delta), (1.0/3.0)) +
                                        - B/3;

    } else {

        Scalar TETA = acos(Q /
                    sqrt(CUBE(fabs(P)))
        );

        PR3  = 2*sqrt(fabs(P))*cos(TETA/3) -B/3;
    }

    PI3 = 0;

    temp = eq2g(1, B+PR3, -D/PR3);

    array = new_array(6);

    array[0] = temp[0];
    array[1] = temp[1];
    array[2] = temp[2];
    array[3] = temp[3];
    array[4] = PR3;
    array[5] = PI3;

    free(temp);

    return array;

}
