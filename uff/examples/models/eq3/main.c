#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "eq3.h"

static int test(int argc, char *argv[])
{

    Array       answer;

    complex     x1,
                x2,
                x3;

    if (argc == 5) {
        answer = eq3g( atos(argv[1]),
                       atos(argv[2]),
                       atos(argv[3]),
                       atos(argv[4])
                     );

        x1.real = answer[0];
        x1.imag = answer[1];

        x2.real = answer[2];
        x2.imag = answer[3];

        x3.real = answer[4];
        x3.imag = answer[5];

        printf("X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n",
                1, realpart(x1),(imagpart(x1)<0.0f)? '-':'+',fabs(imagpart(x1)),
                2, realpart(x2),(imagpart(x2)<0.0f)? '-':'+',fabs(imagpart(x2)),
                3, realpart(x3),(imagpart(x3)<0.0f)? '-':'+',fabs(imagpart(x3))
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
