#include "narray.h"

/*****************************************************************************
 *                                                                           *
 * ----------------- populate_array2d_w_sequential_numbers ----------------- *
 *                                                                           *
 *****************************************************************************/

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

/*****************************************************************************
 *                                                                           *
 * ----------------- populate_array3d_w_sequential_numbers ----------------- *
 *                                                                           *
 *****************************************************************************/

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

/*****************************************************************************
 *                                                                           *
 * ----------------- populate_array4d_w_sequential_numbers ----------------- *
 *                                                                           *
 *****************************************************************************/

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

/*****************************************************************************
 *                                                                           *
 * ----------------- populate_array5d_w_sequential_numbers ----------------- *
 *                                                                           *
 *****************************************************************************/

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

/*****************************************************************************
 *                                                                           *
 * ------------------------------ new_array_3d ----------------------------- *
 *                                                                           *
 *****************************************************************************/

Array2d new_array_2d(size_t dim1, size_t dim2)
{

    /* layers */
    size_t     layer_1_size =  dim1 * sizeof(Array1d);

    size_t     layers_size  = layer_1_size;

    /* data */
    size_t     data_size   = dim1 * dim2 * sizeof(Scalar);

    /* raw of bytes */
    unsigned char  *raw_bytes = (unsigned char *) malloc(layers_size + data_size);

    if is_null(raw_bytes)
        return NULL;

    Array2d  array2d = (Array2d)raw_bytes;

    size_t   i;

    for(i = 0; i < dim1; ++i)
    {
        array2d[i] = (Array1d)(array2d + dim1)
                     + LINEARIZE2D(dim2, i);
    }

    return array2d;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ new_array_3d ----------------------------- *
 *                                                                           *
 *****************************************************************************/

Array3d new_array_3d(size_t dim1,
                     size_t dim2,
                     size_t dim3)
{

    /* layers */
    size_t     layer_1_size =  dim1 * sizeof(Array1d);
    size_t     layer_2_size =  dim1 * dim2 * sizeof(Array2d);

    size_t     layers_size = layer_1_size + layer_2_size;

    /* data */
    size_t     data_size   = dim1 * dim2 * dim3 * sizeof(Scalar);

    /* raw of bytes */
    unsigned char  *raw_bytes = (unsigned char *) malloc(layers_size + data_size);

    if is_null(raw_bytes)
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

/*****************************************************************************
 *                                                                           *
 * ------------------------------ new_array_4d ----------------------------- *
 *                                                                           *
 *****************************************************************************/

Array4d new_array_4d(size_t dim1,
                     size_t dim2,
                     size_t dim3,
                     size_t dim4)
{
    /* layers */
    size_t     layer_1_size =  dim1 * sizeof(Array1d);
    size_t     layer_2_size =  dim1 * dim2 * sizeof(Array2d);
    size_t     layer_3_size =  dim1 * dim2 * dim3 * sizeof(Array3d);

    size_t     layers_size  = layer_1_size + layer_2_size + layer_3_size;

    /* data */
    size_t     data_size    = dim1 * dim2 * dim3 * dim4 * sizeof(Scalar);

    /* raw of bytes */
    unsigned char  *raw_bytes = (unsigned char *) malloc(layers_size + data_size);

    if is_null(raw_bytes)
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

/*****************************************************************************
 *                                                                           *
 * ------------------------------ new_array_5d ----------------------------- *
 *                                                                           *
 *****************************************************************************/

Array5d new_array_5d(size_t dim1,
                     size_t dim2,
                     size_t dim3,
                     size_t dim4,
                     size_t dim5)
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
    unsigned char  *raw_bytes = (unsigned char *) malloc(layers_size + data_size);

    if is_null(raw_bytes)
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

