#include "matrix.h"

int
main (int argc, char *argv[])
{

    MatrixPtr M = createMatrix(5, 5);

    destroyMatrix(M);

    return EXIT_SUCCESS;

}
