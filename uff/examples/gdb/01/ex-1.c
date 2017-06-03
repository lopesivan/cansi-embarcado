#include <stdio.h>
#include <stdlib.h>

typedef unsigned char        uint8_t;
typedef unsigned int         uint32_t;

typedef double               Scalar;
typedef Scalar*              Array1d;
typedef Scalar**             Array2d;
typedef Scalar***            Array3d;
typedef Scalar****           Array4d;

typedef const unsigned long  Size;

Array2d new_2d(Size dim1, Size dim2)
{

    unsigned int i;

    Array2d      array2d = (Array2d)
                           malloc(
                                 dim1 * sizeof(Array1d)
                               + dim1 * dim2 * sizeof(Array2d)
                           );

    if (array2d == NULL)
        return NULL;

    for(i = 0; i < dim1; ++i)
    {
        array2d[i] = (Array1d)(array2d + dim1)
                     + i * dim2;
    }

    return array2d;

}

Array3d new_3d(Size dim1, Size dim2, Size dim3)
{

    unsigned int i,
                 j;

    Array3d      array3d = (Array3d)
                           malloc(
                                 dim1 * sizeof(Array1d)
                               + dim1 * dim2 * sizeof(Array2d)
                               + dim1 * dim2 * dim3 * sizeof(Scalar)
                           );

    if (array3d == NULL)
        return NULL;

    for(i = 0; i < dim1; ++i)
    {
        array3d[i] = (Array2d)(array3d + dim1) + i * dim2;

        for(j = 0; j < dim2; ++j)
        {
            array3d[i][j] =
                    (Array1d)(array3d + dim1 + dim1 * dim2)
                    + i * dim2 * dim3
                    + j * dim3;
        }
    }

    return array3d;

}

Array4d new_4d(Size dim1, Size dim2, Size dim3, Size dim4)
{
    Size layer1_size = sizeof(Array3d) * dim1;
    Size layer2_size = sizeof(Array2d) * dim1 * dim2;

    size_t layers_size =
            sizeof(Array3d) * dim1 +
            sizeof(Array2d) * dim1 * dim2 +
            sizeof(Array1d) * dim1 * dim2 * dim3;

    size_t data_size = sizeof(Scalar) * dim1 * dim2 * dim3 * dim4;

    uint8_t *raw_bytes = (uint8_t *)malloc(layers_size + data_size);

    if (raw_bytes == NULL)
        return NULL;

    Array4d array4d = (Array4d)(raw_bytes);

    unsigned int i,
                 j,
                 k;

    for (i = 0; i < dim1; i++) {
        array4d[i] =
                (Array3d)(raw_bytes + layer1_size)
                + i * dim2;

        for (j = 0; j < dim2; j++) {
            array4d[i][j] =
                    (Array2d)(raw_bytes + layer1_size + layer2_size)
                    + i * dim2 * dim3
                    + j * dim3;

            for (k = 0; k < dim3; k++) {
                array4d[i][j][k] =
                        (Array1d)(raw_bytes + layers_size)
                        + i * dim2 * dim3 * dim4
                        + j * dim3 * dim4
                        + k * dim4;
            }
        }
    }

    return array4d;
}

/*****************************************************************************
*                                                                            *
*  --------------------------------- main ---------------------------------  *
*                                                                            *
*****************************************************************************/

int main(int argc, char **argv)
{
    unsigned int i,
                 j,
                 k,
                 l;

    Size         dim1 = 4,
                 dim2 = 3,
                 dim3 = 3,
                 dim4 = 2;

    Array2d a2d = new_2d(dim1, dim2);

    for (i = 0; i < dim1; ++i)
    {
        for (j = 0; j < dim2; ++j)
        {
            a2d[i][j] = (Scalar)(dim2*i + j);
        }
    }

    free(a2d);


    Array3d a3d = new_3d(dim1, dim2, dim3);
    for (i = 0; i < dim1; ++i)
    {
        for (j = 0; j < dim2; ++j)
        {
            for (k = 0; k < dim3; ++k)
            {
                a3d[i][j][k] = (Scalar) (i*dim2*dim3 + j*dim3 + k);
            }
        }
    }

    /*
     *  width_index=index/(height*depth);  //Note the integer division . This is x
     *  height_index=(index-width_index*height*depth)/depth; //This is y
     *  depth_index=index-width_index*height*depth- height_index*depth;//This is z
     */
    free(a3d);


    Array4d a4d = new_4d(dim1, dim2, dim3, dim4);
    for (i = 0; i < dim1; ++i)
    {
        for (j = 0; j < dim2; ++j)
        {
            for (k = 0; k < dim3; ++k)
            {
                for (l = 0; l < dim4; ++l)
                {
                    a4d[i][j][k][l] = (Scalar) 1000 * i + 100*j + 10*k + l;
                }
            }
        }
    }

    free(a4d);
/*
*/
    return EXIT_SUCCESS;
}
