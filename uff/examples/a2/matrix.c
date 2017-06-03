#include "matrix.h"

struct Matrix{
    size_t    rows;
    size_t    columns;
    Scalar    **data;
};

MatrixPtr createMatrix(size_t rows, size_t columns)
{
    MatrixPtr matrix = malloc(sizeof *matrix);

    if is_null(matrix) {
        printf("%s:In function `%s':\n" "%s:%d: %s\n", \
           __FILE__, __FUNCTION__, __FILE__, __LINE__, \
           "could not allocate the Matrix pointer"
        );

        exit(EXIT_FAILURE);
    }

    matrix->rows    = rows;
    matrix->columns = columns;
    matrix->data    = new_array_2d(rows, columns);

    if is_null(matrix->data)
    {
        printf("%s:In function `%s':\n" "%s:%d: %s\n",\
           __FILE__, __FUNCTION__, __FILE__,  __LINE__,\
           "could not allocate Matrix data"
        );

        exit(EXIT_FAILURE);
    }

    return matrix;

}

void destroyMatrix(MatrixPtr matrix)
{
    free(matrix->data);
    free(matrix);

    return;

}
