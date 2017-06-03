#include <stdio.h>
#include <stdlib.h>

typedef unsigned char        uint8_t;

#define data_fmt             "%8f"
typedef double               Scalar;
typedef Scalar*              Array1d;
typedef Scalar**             Array2d;
typedef Scalar***            Array3d;
typedef Scalar****           Array4d;
typedef Scalar*****          Array5d;

#define LINEARIZE2D(dim2, i)                                     ((dim2)*(i))

#define INDEX_OF_ARRAY2D(dim2, i, j)                             (LINEARIZE2D((dim2), (i)) + (j))
#define INDEX_OF_ARRAY3D(dim2, dim3, i, j, k)                    (INDEX_OF_ARRAY2D((dim2), (i), (j))*(dim3) + (k))
#define INDEX_OF_ARRAY4D(dim2, dim3, dim4, i, j, k, l)           (INDEX_OF_ARRAY3D((dim2), (dim3), (i), (j), (k))*(dim4) + (l))
#define INDEX_OF_ARRAY5D(dim2, dim3, dim4, dim5, i, j, k, l, m)  ((INDEX_OF_ARRAY4D((dim2), (dim3), (dim4), (i), (j), (k), (l)))*(dim5) + (m))

#define LINEARIZE3D(dim2, dim3, i, j)                            (INDEX_OF_ARRAY2D((dim2), (i), (j))*(dim3))
#define LINEARIZE4D(dim2, dim3, dim4, i, j, k)                   (INDEX_OF_ARRAY3D((dim2), (dim3), (i), (j), (k))*(dim4))
#define LINEARIZE5D(dim2, dim3, dim4, dim5, i, j, k, l)          (INDEX_OF_ARRAY4D((dim2), (dim3), (dim4), (i), (j), (k), (l))*(dim5))

static
void print_array(Array1d array, size_t size) {

    size_t i;

    for (i = 0; i < size; i++)
    {

        printf("array[%zd] = "data_fmt"\n", i, array[i]);
    }

    return;

}

static
void populate_array2d_w_sequential_numbers(size_t    dim1,
                                           size_t    dim2,
                                           Array2d   a2d)
{

    size_t i,
                 j;

    for (i = 0; i < dim1; ++i)
    {
        for (j = 0; j < dim2; ++j)
        {
            a2d[i][j] = (Scalar) INDEX_OF_ARRAY2D(dim2,i,j);
        }
    }

    return;

}


static
void populate_array3d_w_sequential_numbers(size_t    dim1,
                                           size_t    dim2,
                                           size_t    dim3,
                                           Array3d   a3d)
{

    size_t i,
                 j,
                 k;

    for (i = 0; i < dim1; ++i)
    {
        for (j = 0; j < dim2; ++j)
        {
            for (k = 0; k < dim3; ++k)
            {
                a3d[i][j][k] = (Scalar) INDEX_OF_ARRAY3D(dim2, dim3, i, j, k);
            }
        }
    }

    return;

}


static
void populate_array4d_w_sequential_numbers(size_t    dim1,
                                           size_t    dim2,
                                           size_t    dim3,
                                           size_t    dim4,
                                           Array4d   a4d)
{

    size_t i,
                 j,
                 k,
                 l;

    for (i = 0; i < dim1; ++i)
    {
        for (j = 0; j < dim2; ++j)
        {
            for (k = 0; k < dim3; ++k)
            {
                for (l = 0; l < dim4; ++l)
                {
                    a4d[i][j][k][l] = (Scalar) INDEX_OF_ARRAY4D(dim2, dim3, dim4, i, j, k, l);
                }
            }
        }
    }

    return;

}

static
void populate_array5d_w_sequential_numbers(size_t    dim1,
                                           size_t    dim2,
                                           size_t    dim3,
                                           size_t    dim4,
                                           size_t    dim5,
                                           Array5d   a5d)
{

    size_t i,
                 j,
                 k,
                 l,
                 m;

    for (i = 0; i < dim1; ++i)
    {
        for (j = 0; j < dim2; ++j)
        {
            for (k = 0; k < dim3; ++k)
            {
                for (l = 0; l < dim4; ++l)
                {
                    for (m = 0; m < dim5; ++m)
                    {
                        a5d[i][j][k][l][m] = (Scalar) INDEX_OF_ARRAY5D(dim2, dim3, dim4, dim5, i, j, k, l, m);
                    }

                }
            }
        }
    }

    return;

}


Array2d new_2d(size_t dim1, size_t dim2)
{

    /* layers */
    size_t     layer_1_size =  dim1 * sizeof(Array1d);

    size_t     layers_size  = layer_1_size;

    /* data */
    size_t     data_size   = dim1 * dim2 * sizeof(Scalar);

    /* raw of bytes */
    uint8_t  *raw_bytes = (uint8_t *) malloc(layers_size + data_size);

    if (raw_bytes == NULL)
        return NULL;

    Array2d      array2d = (Array2d)raw_bytes;

    size_t i;

    for(i = 0; i < dim1; ++i)
    {
        array2d[i] = (Array1d)(array2d + dim1)
                     + LINEARIZE2D(dim2, i);
    }

    return array2d;

}

Array3d new_3d(size_t dim1, size_t dim2, size_t dim3)
{

    /* layers */
    size_t     layer_1_size =  dim1 * sizeof(Array1d);
    size_t     layer_2_size =  dim1 * dim2 * sizeof(Array2d);

    size_t     layers_size = layer_1_size + layer_2_size;

    /* data */
    size_t     data_size   = dim1 * dim2 * dim3 * sizeof(Scalar);

    /* raw of bytes */
    uint8_t  *raw_bytes = (uint8_t *) malloc(layers_size + data_size);

    if (raw_bytes == NULL)
        return NULL;

    size_t i,
                 j;

    Array3d      array3d = (Array3d)raw_bytes;

    for(i = 0; i < dim1; ++i)
    {
        array3d[i] = (Array2d)(array3d + dim1)
                     + LINEARIZE2D(dim2, i);

        for(j = 0; j < dim2; ++j)
        {
            array3d[i][j] =
                    (Array1d)(array3d + dim1 + dim1 * dim2)
                    + LINEARIZE3D(dim2, dim3, i, j);
        }
    }

    return array3d;

}

Array4d new_4d(size_t dim1, size_t dim2, size_t dim3, size_t dim4)
{
    /* layers */
    size_t     layer_1_size =  dim1 * sizeof(Array1d);
    size_t     layer_2_size =  dim1 * dim2 * sizeof(Array2d);
    size_t     layer_3_size =  dim1 * dim2 * dim3 * sizeof(Array3d);

    size_t     layers_size  = layer_1_size + layer_2_size + layer_3_size;

    /* data */
    size_t     data_size    = dim1 * dim2 * dim3 * dim4 * sizeof(Scalar);

    /* raw of bytes */
    uint8_t  *raw_bytes = (uint8_t *) malloc(layers_size + data_size);

    if (raw_bytes == NULL)
        return NULL;

    Array4d      array4d = (Array4d)raw_bytes;

    size_t i,
                 j,
                 k;

    for(i = 0; i < dim1; ++i)
    {
        array4d[i] = (Array3d)(array4d + dim1)
                     + LINEARIZE2D(dim2, i);

        for(j = 0; j < dim2; ++j)
        {
            array4d[i][j] =
                    (Array2d)(array4d + dim1 + dim1 * dim2)
                    + LINEARIZE3D(dim2, dim3, i, j);

            for(k = 0; k < dim3; ++k)
            {
                array4d[i][j][k] =
                        (Array1d)(array4d + dim1 + dim1 * dim2 + dim1 * dim2 * dim3)
                        + LINEARIZE4D(dim2, dim3, dim4, i, j, k);
            }
        }


    }

    return array4d;

}


Array5d new_5d(size_t dim1, size_t dim2, size_t dim3, size_t dim4, size_t dim5)
{
    /* layers */
    size_t     layer_1_size =  dim1 * sizeof(Array1d);
    size_t     layer_2_size =  dim1 * dim2 * sizeof(Array2d);
    size_t     layer_3_size =  dim1 * dim2 * dim3 * sizeof(Array3d);
    size_t     layer_4_size =  dim1 * dim2 * dim3 * dim4 * sizeof(Array4d);

    size_t     layers_size  = layer_1_size + layer_2_size + layer_3_size + layer_4_size;

    /* data */
    size_t     data_size    = dim1 * dim2 * dim3 * dim4 * dim5 * sizeof(Scalar);

    /* raw of bytes */
    uint8_t  *raw_bytes = (uint8_t *) malloc(layers_size + data_size);

    if (raw_bytes == NULL)
        return NULL;

    Array5d      array5d = (Array5d)raw_bytes;

    size_t i,
                 j,
                 k,
                 l;

    for(i = 0; i < dim1; ++i)
    {
        array5d[i] = (Array4d)(array5d + dim1)
                     + LINEARIZE2D(dim2, i);

        for(j = 0; j < dim2; ++j)
        {
            array5d[i][j] =
                    (Array3d)(array5d + dim1 + dim1 * dim2)
                    + LINEARIZE3D(dim2, dim3, i, j);

            for(k = 0; k < dim3; ++k)
            {
                array5d[i][j][k] =
                        (Array2d)(array5d + dim1 + dim1 * dim2 + dim1 * dim2 * dim3)
                        + LINEARIZE4D(dim2, dim3, dim4, i, j, k);
                for(l = 0; l < dim4; ++l)
                {
                    array5d[i][j][k][l] =
                            (Array1d)(array5d + dim1 + dim1 * dim2 + dim1 * dim2 * dim3 + dim1 * dim2 * dim3 * dim4)
                            + LINEARIZE5D(dim2, dim3, dim4, dim5, i, j, k, l);
                }
            }
        }

    }

    return array5d;

}


static
void test() {

    size_t  dim1 = 5,
            dim2 = 4,
            dim3 = 3,
            dim4 = 2,
            dim5 = 2;

    Array2d a2d = new_2d(dim1, dim2);

    populate_array2d_w_sequential_numbers(dim1, dim2, a2d);

    printf("-- 2d -- \n");
    print_array(*a2d, dim1*dim2);

    free(a2d);


    Array3d a3d = new_3d(dim1, dim2, dim3);

    populate_array3d_w_sequential_numbers(dim1, dim2, dim3, a3d);

    printf("-- 3d -- \n");
    print_array(**a3d, dim1*dim2*dim3);

    free(a3d);

    Array4d a4d = new_4d(dim1, dim2, dim3, dim4);

    populate_array4d_w_sequential_numbers(dim1, dim2, dim3, dim4, a4d);

    printf("-- 4d -- \n");
    print_array(***a4d, dim1*dim2*dim3*dim4);

    free(a4d);

    Array5d a5d = new_5d(dim1, dim2, dim3, dim4, dim5);

    populate_array5d_w_sequential_numbers(dim1, dim2, dim3, dim4, dim5, a5d);

    printf("-- 5d -- \n");
    print_array(****a5d, dim1*dim2*dim3*dim4*dim5);

    free(a5d);

    printf("-- fim --\n");

    return;

}

/*****************************************************************************
*                                                                            *
*  --------------------------------- main ---------------------------------  *
*                                                                            *
*****************************************************************************/

int main(int argc, char **argv)
{

    test();

    return EXIT_SUCCESS;
}

