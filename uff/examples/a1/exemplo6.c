#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

#define SIZE 50

char SSS[SIZE];
int top = -1;

int braces(const char *string);

int precedence(char ch);

void push(char ch);

char pop();

char topelement();

int print_string_char_by_char(const char *string);

char *new_string_without_white_spaces(char *source);

char *strsep(char **string, const char *delim);

char *new_string(const char *list_of_numbers);

static
void print_stack(const Stack *stack)
{

    ListElmt   *element;

    char       *data;

    int        size,
               i;

    fprintf(stdout, "Stack size is %d\n", size = stack_size(stack));

    i       = 0;
    element = list_head(stack);

    while (i < size) {
        data    = list_data(element);

        fprintf(stdout, "stack[%03d]=%s\n", i, data);

        element = list_next(element);

        i++;
    }

    return;

}

char *new_string_without_white_spaces(char *source)
{
    char *write, *string, *read;

    write = read = string = strdup(source);

    do {
        if (*read != ' ')
            *write++ = *read;

    } while (*read++);

    return string;
}

int print_string_char_by_char(const char *string)
{
    while (*string) {
        printf("-> %c\n", *string);
        string++;
    }

    return EXIT_SUCCESS;

}

char *strsep(char **string, const char *delim)
{
    char *s;

    const char *spanp;

    int c,
        sc;

    char *token;

    if ((s = *string) == NULL)
        return (NULL);

    for (token = s; ;) {
        c = *s++;
        spanp = delim;

        do {
            if ((sc = *spanp++) == c) {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;

                *string = s;

                return (token);
            }
        } while (sc != 0);
    }
}

int braces(const char *string)
{
    int    leftbr  = 0,
           rightbr = 0;

    while (*string) {
        if (*string == '(')
            leftbr++;

        if (*string == ')')
            rightbr++;

        string++;
    }

    if (leftbr == rightbr)
        return 0;

    return ((leftbr < rightbr) ? -1 : +1);

}

int precedence(char ch)
{
    switch (ch) {
    case '^':
        return 5;
    case '/':
        return 4;
    case '*':
        return 4;
    case '+':
        return 3;
    case '-':
        return 3;
    default:
        return 0;
    }

    return EXIT_FAILURE;
}

void push(char ch)
{
    if (top != SIZE - 1) {
        top++;
        SSS[top] = ch;
    }
    return;
}

char pop()
{
    char ret;
    if (top != -1) {
        ret = SSS[top];
        top--;
        return ret;
    } else
        return '#';
}

char topelement()
{
    char ch;
    if (top != -1)
        ch = SSS[top];
    else
        ch = '#';
    return ch;
}

char *new_string(const char *list_of_numbers)
{

    char          *string;

    size_t        size = strlen(list_of_numbers);

    string = (char*) malloc(size + 1);

    strcpy(string, list_of_numbers);

    return string;

}

int main()
{
    Stack    stack;

    char     *data;

    char     *infix, *tofree, *token;

    int      braces_unbalanced;

    tofree = infix = new_string_without_white_spaces("33.5*x^2 + (A+B/DELTA)*999*x + 5");

    braces_unbalanced = braces(infix);

    if (braces_unbalanced)
    {
        printf("Unbalanced no. of braces\n");
        printf("Extra `%s' braces\n", (braces_unbalanced == 1 ? "right" : "left"));

        exit(EXIT_FAILURE);
    }

    printf("input: %s\n",infix);

    stack_init(&stack, free);

    /* Pushing elements */

    while ((token = strsep(&infix, "^*+-/{}()[]")) != NULL)
    {
        if (strlen(token) != 0)
        {
            data = new_string(token);

            if (stack_push(&stack, data) != 0)
                return 1;
        }
    }

    print_stack(&stack);

    free(tofree);

    /* Clear stack */
    while (stack_size(&stack) > 0) {
        if (stack_pop(&stack, (void **) &data) == 0)
            free(data);
    }

    /* Destroying the stack */
    stack_destroy(&stack);

    return EXIT_SUCCESS;

}

