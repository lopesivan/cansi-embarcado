#include <stdio.h>
#include <stdlib.h>

#include "array.h"

/*****************************************************************************
 *                                                                           *
 * --------------------------------- zero ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

void zero(Array array, Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 0;

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- new_array ------------------------------- *
 *                                                                           *
 *****************************************************************************/

Array new_array(Size size)
{

    Array array;

    array = (Array) malloc((size_t)(size) * sizeof(Scalar));

    if (!array)
    {
        __error("Couldn't allocate memory");
    }

    /* initialize with zero */
    zero(array, size);

    return array;

}
