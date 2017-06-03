#ifndef ARRAY_H
#define ARRAY_H

#include "narray.h"

typedef Scalar*              Array;
typedef Scalar**             Matrix;

typedef const unsigned long  Row;
typedef const unsigned long  Column;
typedef const unsigned long  Size;

/*****************************************************************************
 *                                                                           *
 * ---------------------------- Public Interface --------------------------- *
 *                                                                           *
 *****************************************************************************/

void zero(Array array, Size size);
void one(Array array, Size size);
void two(Array array, Size size);
void three(Array array, Size size);
void grand(Array array, Size size);
void reverse(Array array, Size size);

Scalar sum(Array array, Size size);
Scalar seq_sum(Array array, unsigned int begin, unsigned int end, Scalar (*f)(Scalar));
Scalar seq_product(Array array, unsigned int begin, unsigned int end, Scalar (*f)(Scalar));
Scalar dot(Array A, Array B, Size size);
Scalar product(Array array, Size size);

char *new_string(const char *list_of_numbers);
Array new_array_of_split(const char *list_of_numbers);
void set_array_w_split_string(Array dest, const char *list_of_numbers);
void copy_string_to_array(Array dest, char *string);

void print_array(Array array, Size size);

void array_add(Array A, Array B, Array C, Size size);
void array_dot(Array A, Array B, Array C, Size size);

Array new_array(Size size);

#endif       /* ARRAY_H */
