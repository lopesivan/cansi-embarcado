#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*****************************************************************************
 *                                                                           *
 *  --------------------------------- main --------------------------------- *
 *                                                                           *
 *****************************************************************************/

int
main (int argc, char *argv[]) {

    char *s = "A + 44.7*x - W*(A+B) + 1259*3.14 = y(x)";
    char *d ="()";

    char *p1;
    char *d1;
    int flag;
    char *begin, *end;
    p1 = s;
    d1 = d;
    flag = 1;
    while (*d1)
    {
        while(*p1)
        {
            if (*p1 == *d1)
            {
                printf("->%c\n", *p1);
                if (flag){
                    begin = p1;
                    flag = 0;
                } else {
                    end = p1;
                    flag = 1;
                }
                break;
            }

            p1++;
        }
        p1 = s;
        d1++;
    }

    printf("begin: %c\n", *begin);
    printf("end  : %c\n", *end);
    printf("size : %d\n", (int)(end-begin+1));

    size_t size = (size_t)(end - begin + 1 + 1);
    char *tmp;
    tmp = (char*) malloc ((size_t) (size) * sizeof (char));

    if (!tmp) {
        fprintf(stderr, "Memory Allocation Failed!");
    }

    memcpy(tmp, begin, size);
    tmp[size-1]= '\0';
    printf("->%s\n", tmp);
    free(tmp);
    return EXIT_SUCCESS;
}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */

