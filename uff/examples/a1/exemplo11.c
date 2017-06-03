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

typedef enum {
    NUMBER = 0,
    ALPHA,
    OPERATOR,
    BRACES,
    WHITESPACE,
    OTHER } cursor;

void print_string(const char *begin,
                  const char *end);

void parse_pass1(cursor current_cursor_position,
                 cursor last_cursor_position,
                 char   **begin,
                 char   **end);

void parse_pass2(char     *begin,
                 char     *end,
                 cursor   last_cursor_position);

void parse_string_equation(char  *string,
                           char  *delimiter);

int main(int argc, char *argv[])
{

    char      *string    = argv[1];
    char      *delimiter = "=^*/+-";

    parse_string_equation(string, delimiter);

    return EXIT_SUCCESS;

}

void parse_string_equation(char *string,
                           char *delimiter)
{
    char    *p;
    char    *q;

    char    *begin = NULL,
            *end   = NULL;

    cursor    current_cursor_position,
              last_cursor_position = -1;

    p = string;

    do {

        if (begin == NULL)
            begin = p;
        else
            end = p;

        if ((isdigit(*p)) || (*p == '.')) {
            if (last_cursor_position == ALPHA) {
                current_cursor_position = ALPHA;
            } else
                current_cursor_position = NUMBER;
        }

        if (isalpha(*p))
            current_cursor_position = ALPHA;

        if (*p == ' ')
            current_cursor_position = WHITESPACE;

        if ((*p == '(') || (*p == ')'))
            current_cursor_position = BRACES;

        q = delimiter;

        do {
            if (*q == *p) {
                current_cursor_position = OPERATOR;
                break;
            }
        } while (*(++q));

        parse_pass1(current_cursor_position, last_cursor_position, &begin, &end);

        last_cursor_position = current_cursor_position;

    } while (*(++p));

    parse_pass2(begin, end, last_cursor_position);

}

void parse_pass1(cursor  current_cursor_position,
                 cursor  last_cursor_position,
                 char    **begin,
                 char    **end)
{

    if ((last_cursor_position != -1)
        && (last_cursor_position != current_cursor_position)) {

        switch (last_cursor_position) {
        case NUMBER:
        case ALPHA:
        case OPERATOR:
        case BRACES:
            while((*begin)!=(*end))
            {
                print_string((*begin), (*begin));
                (*begin)++;
            }
            break;

        case WHITESPACE:
            (*begin) = (*end);
            break;

        case OTHER:
            printf("OTHER");
            break;

        default:
            printf("NOPS!");
        };

    }
}

void parse_pass2(char   *begin,
                 char   *end,
                 cursor last_cursor_position)
{
    switch (last_cursor_position) {
        case NUMBER:
        case ALPHA:
        case OPERATOR:
            print_string(begin, ++end);
            break;
        case BRACES:
            while(begin!=end)
            {
                print_string(begin, begin);
                begin++;
            }
            break;

        case WHITESPACE:
            break;

        case OTHER:
            printf("OTHER");
            break;

        default:
            printf("NOPS!");
    };
}

void print_string(const char *begin,
                  const char *end)
{
    size_t size = (size_t) (end - begin + 1 + 1);

    char *tmp   = (char *)malloc((size_t) (size) * sizeof(char));

    if (!tmp) {
        printf("Memory Allocation Failed!\n");
    }

    memcpy(tmp, begin, size);
    tmp[size - 1] = '\0';

    printf("->@%s@\n", tmp);

    free(tmp);
}

/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */
