#ifndef NARRAY_H
#define NARRAY_H

#include "except.h"
#include "datatype.h"

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

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

void populate_array2d_w_sequential_numbers(size_t dim1, size_t dim2, Array2d a2d);
void populate_array3d_w_sequential_numbers(size_t dim1, size_t dim2, size_t dim3, Array3d a3d);
void populate_array4d_w_sequential_numbers(size_t dim1, size_t dim2, size_t dim3, size_t dim4, Array4d a4d);
void populate_array5d_w_sequential_numbers(size_t dim1, size_t dim2, size_t dim3, size_t dim4, size_t dim5, Array5d a5d);

Array2d new_array_2d(size_t dim1, size_t dim2);
Array3d new_array_3d(size_t dim1, size_t dim2, size_t dim3);
Array4d new_array_4d(size_t dim1, size_t dim2, size_t dim3, size_t dim4);
Array5d new_array_5d(size_t dim1, size_t dim2, size_t dim3, size_t dim4, size_t dim5);

#endif       /* NARRAY_H */
