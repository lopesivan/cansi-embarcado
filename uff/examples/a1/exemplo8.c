#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define foreach(pointer, array)  for ((pointer) = &(array)[0]; (pointer) < 1[&(array)]; (pointer)++)
/*****************************************************************************
 *                                                                           *
 *  --------------------------------- main --------------------------------- *
 *                                                                           *
 *****************************************************************************/
typedef enum {NUMBER=0, ALPHA, OPERATOR, BRACES, WHITESPACE, OTHER} cursor;

void print_string(const char *begin, const char *end);

int
main (int argc, char *argv[])
{

    char         *string    = argv[1];
    char         *delimiter = "^*/+-";

    char         *p = string;
    char         *q;

    char         *begin = NULL,
                 *end   = NULL;

    cursor       current,
                 old = -1;

    do {
        /* printf("p=%c\n",*p); */

        if (begin == NULL)
            begin = p;
        else
            end = p;

        if ((isdigit(*p)) || (*p == '.'))
            current = NUMBER;

        if (isalpha(*p))
            current = ALPHA;

        if (*p == ' ')
            current = WHITESPACE;

        if ((*p == '(') || (*p == ')'))
            current = BRACES;

        q = delimiter;

        do {
            /* printf("p =%c q= %c\n", *p, *q); */

            if  (*q == *p) {
                current = OPERATOR;
                break;
            }
        } while(*(++q));

        if ((old != -1) && (old != current))
        {
/*
            switch (old) {
            case NUMBER:
                printf("NUMBER");
                break;

            case ALPHA:
                printf("ALPHA");
                break;

            case OPERATOR:
                printf("OPERATOR");
                break;

            case WHITESPACE:
                printf("WHITESPACE");
                break;

            case BRACES:
                printf("BRACES");
                break;

            case OTHER:
                printf("OTHER");
                break;

            default:
                printf("NOPS!");
            };

            printf(" to ");

            switch (current) {
            case NUMBER:
                printf("NUMBER\n");
                break;

            case ALPHA:
                printf("ALPHA\n");
                break;

            case OPERATOR:
                printf("OPERATOR\n");
                break;

            case WHITESPACE:
                printf("WHITESPACE\n");
                break;

            case BRACES:
                printf("BRACES\n");
                break;

            case OTHER:
                printf("OTHER\n");
                break;

            default:
                printf("NOPS!\n");
            };
*/
            /* ALPHA TO */
            if (old == ALPHA)
            {
                if (current == BRACES)
                {
                    printf("imprime ALPHA\n");
                }

                if (current == NUMBER)
                {
                    printf("imprime ALPHA\n");
                }

                if (current == OPERATOR)
                {
                    printf("imprime ALPHA\n");
                }

                if (current == WHITESPACE)
                {
                    printf("imprime ALPHA\n");
                }

                end--;
                print_string(begin, end);
                begin = end;
                begin++;
            }

            /* BRACES TO */
            if (old == BRACES)
            {
                if (current == ALPHA)
                {
                    printf("imprime BRACES\n");
                }

                if (current == NUMBER)
                {
                    printf("imprime BRACES\n");
                }

                if (current == OPERATOR)
                {
                    printf("imprime BRACES\n");
                }

                if (current == WHITESPACE)
                {
                    printf("imprime BRACES\n");
                }

                end--;
                print_string(begin, end);
                begin = end;
                begin++;
            }

            /* NUMBER TO */
            if (old == NUMBER)
            {
                if (current == ALPHA)
                {
                    printf("imprime NUMBER\n");
                }

                if (current == BRACES)
                {
                    printf("imprime NUMBER\n");
                }

                if (current == OPERATOR)
                {
                    printf("imprime NUMBER\n");
                }

                if (current == WHITESPACE)
                {
                    printf("imprime NUMBER\n");
                }

                end--;
                print_string(begin, end);
                begin = end;
                begin++;
            }

            /* OPERATOR TO */
            if (old == OPERATOR)
            {
                if (current == ALPHA)
                {
                    printf("imprime OPERATOR\n");
                }

                if (current == BRACES)
                {
                    printf("imprime OPERATOR\n");
                }

                if (current == NUMBER)
                {
                    printf("imprime OPERATOR\n");
                }

                if (current == WHITESPACE)
                {
                    printf("imprime OPERATOR\n");
                }

                end--;
                print_string(begin, end);
                end++;
                begin = end;

                /* printf("begin:%c\n",*begin); */
                /* printf("end  :%c\n",*end); */
            }

            /* WHITESPACE TO */
            if (old == WHITESPACE)
            {
                begin = end;
                /*
                if (current == ALPHA)
                {
                    printf("imprime WHITESPACE\n");
                }

                if (current == BRACES)
                {
                    printf("imprime WHITESPACE\n");
                }

                if (current == NUMBER)
                {
                    printf("imprime WHITESPACE\n");
                }

                if (current == OPERATOR)
                {
                    printf("imprime WHITESPACE\n");
                }
                */
            }

        }
        old = current;

    } while(*(++p));

    if (current == WHITESPACE)
    {
        while(*end == ' ')
            end--;

        print_string(begin, end);
    }

    printf("\n=%c=\n",*end);
    return EXIT_SUCCESS;

}

void print_string(const char *begin, const char *end)
{
    size_t size = (size_t)(end - begin + 1 + 1);
    char *tmp;
    tmp = (char*) malloc ((size_t) (size) * sizeof (char));

    if (!tmp) {
        fprintf(stderr, "Memory Allocation Failed!");
    }

    memcpy(tmp, begin, size);
    tmp[size-1]= '\0';
    printf("->@%s@\n", tmp);
    free(tmp);
}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */

