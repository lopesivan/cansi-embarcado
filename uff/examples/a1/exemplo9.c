#include <stdio.h>
#include <stdlib.h>

typedef enum {false=0, true=1} bool;
#define INVALID_ADDRESS ((char*)1)

#define T char
#define foreach(pointer, array)  for ((pointer) = &(array)[0]; (pointer) < 1[&(array)]; (pointer)++)

int main(int argc, char *argv[])
{
    char arr[4] = {'A', 'B', 'C', 'D'};
    char *p;

    /* cdecl explain "int (*p)[];" */
    /* declare p as pointer to array of int */

    foreach(p, arr)
        printf("%c\n", *p);

    return EXIT_SUCCESS;
}
