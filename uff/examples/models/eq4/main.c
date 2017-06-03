#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "pythagoras.h"
#include "eq4.h"

static
int testPythagoras(int argc, char *argv[])
{

    if (argc == 3)
        printf("->"data_fmt"\n",
               pythagoras(atos(argv[1]), atos(argv[2]))

              );
    else
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

static
int testEq2(int argc, char *argv[])
{

    Array       answer;

    Complex     x1,
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

static
int testEq3(int argc, char *argv[])
{

    Array       answer;

    Complex     x1,
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

static
int testEq4(int argc, char *argv[])
{

    Array       answer;

    Complex     x1,
                x2,
                x3,
                x4;

    if (argc == 6) {
        answer = eq4g( atos(argv[1]),
                       atos(argv[2]),
                       atos(argv[3]),
                       atos(argv[4]),
                       atos(argv[5])
                     );

        x1.real = answer[0];
        x1.imag = answer[1];

        x2.real = answer[2];
        x2.imag = answer[3];

        x3.real = answer[4];
        x3.imag = answer[5];

        x4.real = answer[6];
        x4.imag = answer[7];

        printf("X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n",
                1, realpart(x1),(imagpart(x1)<0.0f)? '-':'+',fabs(imagpart(x1)),
                2, realpart(x2),(imagpart(x2)<0.0f)? '-':'+',fabs(imagpart(x2)),
                3, realpart(x3),(imagpart(x3)<0.0f)? '-':'+',fabs(imagpart(x3)),
                4, realpart(x4),(imagpart(x4)<0.0f)? '-':'+',fabs(imagpart(x4))
              );

        free(answer);

    } else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}


int main(int argc, char *argv[])
{
    printf("argc = <%d>\n", argc);

    switch(argc) {

    case 3:
        if (testPythagoras(argc, argv) == EXIT_FAILURE)
            exit(1);
        break;

    case 4:
        if (testEq2(argc, argv) == EXIT_FAILURE)
            exit(2);
        break;

    case 5:
        if (testEq3(argc, argv) == EXIT_FAILURE)
            exit(3);
        break;

    case 6:
        if (testEq4(argc, argv) == EXIT_FAILURE)
            exit(4);
        break;

    default : /* Optional */
        printf("No input ...\n");
    }

    return EXIT_SUCCESS;

}
