#include <stdio.h>
#include <stdlib.h>

#include "pythagoras.h"

static int test(int argc, char *argv[])
{

    if (argc == 3)
        printf("->"data_fmt"\n",
               pythagoras(atos(argv[1]), atos(argv[2]))

              );
    else
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}


int main(int argc, char *argv[])
{
    if (test(argc, argv) == EXIT_FAILURE)
        exit(1);

    return EXIT_SUCCESS;

}
