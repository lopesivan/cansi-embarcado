#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "eq2.h"

static int test(int argc, char *argv[])
{

    Array       answer;

    complex     x1,
                x2;

    if (argc == 4) {
        answer = eq2g( atos(argv[1]),
                       atos(argv[2]),
                       atos(argv[3])
                     );

        x1.real = answer[0];
        x1.imag = answer[1];

        x2.real = answer[2];
        x2.imag = answer[3];

        printf("X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n",
                1, realpart(x1),(imagpart(x1)<0.0f)? '-':'+',fabs(imagpart(x1)),
                2, realpart(x2),(imagpart(x2)<0.0f)? '-':'+',fabs(imagpart(x2))
              );

        free(answer);

    } else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}

int main(int argc, char *argv[])
{
    if (test(argc, argv) == EXIT_FAILURE)
        exit(1);

    return EXIT_SUCCESS;

}
