#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "array.h"

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- zero --------------------------------- *
 *                                                                           *
 *****************************************************************************/

void zero(Array array, Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 0;

    return;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- one ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

void one(Array array,
         Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 1;

    return;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- two ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

void two(Array array,
         Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 2;

    return;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------------- three --------------------------------- *
 *                                                                           *
 *****************************************************************************/

void three(Array array,
           Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        array[i] = 3;

    return;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------------- grand --------------------------------- *
 *                                                                           *
 *****************************************************************************/

void grand(Array array,
           Size size)
{

    unsigned int i;

    /* initialize generator */

    srand ((unsigned int)time(NULL));

    for (i = 0; i < size; i++)

    /* generate numbers
     * ----------------
     *
     * RAND_MAX = RAND_MAX
     *
     * A number between 0 and RAND_MAX : rand()
     * A number between 0 and 99: rand() % 100
     * A number between 0 and 9: rand() % 10
     *
     */

    array[i] = (Scalar)(rand() % 100);

    return;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- sum ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar sum(Array array,
           Size size)
{

    unsigned int i;

    Scalar       sum=0;

    for (i = 0; i < size; i++)

        sum += array[i];

    return sum;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------ seq_sum ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar seq_sum(Array array,
               unsigned int begin,
               unsigned int end,
               Scalar (*f)(Scalar))
{

    unsigned int i;

    Scalar       sum = 0;

    for (i = begin; i < end; i++)

        sum += f(array[i]);

    return sum;

}

/*****************************************************************************
 *                                                                           *
 * -------------------------- seq_product ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar seq_product(Array array,
                   unsigned int begin,
                   unsigned int end,
                   Scalar (*f)(Scalar))
{

    unsigned int i;

    Scalar       product=1;

    for (i = begin; i < end; i++)

        product *= f(array[i]);

    return product;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- dot ---------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar dot(Array A,
           Array B,
           Size size)
{

    Scalar        value;

    Array         C = new_array(size);

    array_dot(A, B, C, size);

    print_array(C,size);

    value = product(C, size);

    free(C);

    return value;

}

/*****************************************************************************
 *                                                                           *
 * ---------------------------------- product --------------------------------- *
 *                                                                           *
 *****************************************************************************/

Scalar product(Array array,
               Size size)
{

    unsigned int i;

    Scalar       product=1;

    for (i = 0; i < size; i++)

        product *= array[i];

    return product;

}


/*****************************************************************************
 *                                                                           *
 * ------------------------------ print_array ------------------------------ *
 *                                                                           *
 *****************************************************************************/

void print_array(Array array, Size size) {

    unsigned int i;

    for (i = 0; i < size; i++)
    {
        printf("array[%u] = " data_fmt "\n", i, array[i]);
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- array_add ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void array_add(Array A,
               Array B,
               Array C, Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        C[i] = A[i] + B[i];

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- array_dot ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void array_dot(Array A,
               Array B,
               Array C, Size size)
{

    unsigned int i;

    for (i = 0; i < size; i++)

        C[i] = A[i] * B[i];

    return;
}


/*****************************************************************************
 *                                                                           *
 * --------------------------- array_reverse ------------------------------- *
 *                                                                           *
 *****************************************************************************/

void array_reverse(Array array, Size size) {

    unsigned int i,
                 end = size - 1;

    Scalar       temp;

    for (i = 0; i < size/2; i++) {
        temp       = array[i];
        array[i]   = array[end];
        array[end] = temp;

        end--;
    }

    return;

}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- new_array ------------------------------- *
 *                                                                           *
 *****************************************************************************/

Array new_array(Size size)
{

    Array array;

    array = (Array) malloc((size_t)(size) * sizeof(Scalar));

    if is_null(array)
        return NULL;

    /* initialize with zero */
    zero(array, size);

    return array;

}

/*****************************************************************************
 *                                                                           *
 * --------------------------- new_array_of_split -------------------------- *
 *                                                                           *
 *****************************************************************************/

Array new_array_of_split(const char *list_of_numbers)
{

    char          *string = new_string(list_of_numbers);

    char          **res   = NULL;
    char          *p      = strtok(string, " ");

    int           number_of_spaces = 0,
                  i;

    /*
     * split string and append tokens to 'res'
     */

    while (p) {
        res = realloc(res, sizeof(char *) * ++number_of_spaces);

        if (res == NULL) {
            __error("memory allocation failed");
        }

        res[number_of_spaces - 1] = p;

        p = strtok(NULL, " ");
    }

    /*
     * realloc one extra element for the last NULL
     */

    res = realloc(res, sizeof(char *) * (number_of_spaces + 1));
    res[number_of_spaces] = 0;

    /*
     * print the result
     */

    /*
    for (i = 0; i < number_of_spaces; ++i)
        printf("res[%d] = %s\n", i, res[i]);
    */

    Array array = new_array(number_of_spaces);

    for (i = 0; i < number_of_spaces; ++i) {
        array[i] = atos(res[i]);
    }

    /*
     * free the memory allocated
     */
    free(res);
    free(string);

    return array;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------ set_array_w_split_string ----------------------- *
 *                                                                           *
 *****************************************************************************/

void set_array_w_split_string(Array dest, const char *list_of_numbers)
{
    char *string = new_string(list_of_numbers);

    copy_string_to_array(dest, string);

    /*
     * free the memory allocated
     */
    free(string);

    return;
}

/*****************************************************************************
 *                                                                           *
 * ------------------------------- new_string ------------------------------ *
 *                                                                           *
 *****************************************************************************/

char *new_string(const char *list_of_numbers)
{

    char          *string;

    size_t        size = strlen(list_of_numbers);

    string = (char*) malloc(size + 1);

    strcpy(string, list_of_numbers);

    return string;

}

/*****************************************************************************
 *                                                                           *
 * -------------------------- copy_string_to_array ------------------------- *
 *                                                                           *
 *****************************************************************************/

void copy_string_to_array(Array dest, char *string)
{
    char          **res = NULL;
    char          *p    = strtok(string, " ");

    int           number_of_spaces = 0,
                  i;

    /*
    * split string and append tokens to 'res'
    */

    while (p) {
        res = realloc(res, sizeof(char *) * ++number_of_spaces);

        if (res == NULL) {
            __error("memory allocation failed");
        }

        res[number_of_spaces - 1] = p;

        p = strtok(NULL, " ");
    }

    /*
     * realloc one extra element for the last NULL
     */
    res = realloc(res, sizeof(char *) * (number_of_spaces + 1));
    res[number_of_spaces] = 0;

    for (i = 0; i < number_of_spaces; ++i) {
        dest[i] = atos(res[i]);
    }

    /*
     * free the memory allocated
     */
    free(res);

}


