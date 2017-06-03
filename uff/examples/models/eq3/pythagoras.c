#include <math.h>

#include "pythagoras.h"

/*****************************************************************************
 *                                                                           *
 * ------------------------------- pythagoras ------------------------------ *
 *                                                                           *
 *****************************************************************************/

Scalar pythagoras(Scalar a, Scalar b)
{

    Scalar  absa = fabs(a),
            absb = fabs(b);

    if (absa > absb)
        return absa * sqrt(1.0 + SQR(absb/absa));
    else
        return (
                   absb == 0.0 ? 0.0 : absb * sqrt(1.0 + SQR(absa/absb))
               );

}
