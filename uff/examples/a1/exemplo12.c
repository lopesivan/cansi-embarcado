#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <execinfo.h>

void split(char *tmp, const char *d);
void print_trace (void);
void dummy_function (void);


typedef enum {
    LAMBDA=0,
    ADDITION,
    INTEGER,
    VARIABLE

} TypeOfElemment;

typedef struct ExpTree_{
    TypeOfElemment type;
    char           *value;
} ExpTree;


ExpTree *Expression(char *exp, int *position);
ExpTree *Addition(char *exp, int *position);
ExpTree *RestOfAddition(char *exp, int *position);
ExpTree *Element(char *exp, int *position);


ExpTree *Expression(char *exp, int *position)
{
    if (exp[*position])
    {
        ExpTree *node = malloc(sizeof(*node));
        node->type = LAMBDA;
        node->value = 0;
        return node;
    }
    else
        return Addition(exp, position);
}

ExpTree *Addition(char *exp, int *position)
{
    ExpTree *node = malloc(sizeof(*node));
    node->type = ADDITION;
    node->left = Multiplication(exp, position);
    node->right = RestOfAddition(exp, position);
    return node;
}

ExpTree *RestOfAddition(char *exp, int *position)
{
    ExpTree *node;
    if (exp[*position] == '+')
    {
        ++*position;
        return Addition(exp, position);
    }
    else
    {
        ExpTree *node = malloc(sizeof(*node));
        node->type = LAMBDA;
        node->value = 0;
        return node;
    }
}

ExpTree *Element(char *exp, int *position)
{
    if (exp[*position] == '(')
    {
        ExpTree *node;
        ++*position;
        node = Expression(exp, position);
        if (!exp[*position] != ')')
            printf("Expected ) at position %d\n", *position);
        else
            ++*position;
        return node;
    }
    else if (exp[*position] == ')')
    {
        printf("Unexpected ) at position %d\n", *position);
        return NULL;
    }
    else if (exp[*position] >= '0' && exp[*position] <= '9')
    {
        ExpTree *node = malloc(sizeof(*node));
        node->type = INTEGER;
        node->value = extract_int(exp, position);
        return node;
    }
    else if ((exp[*position] >= 'a' && exp[*position] <= 'z') ||
             (exp[*position] >= 'A' && exp[*position] <= 'Z') ||
             exp[*position] == '_')
    {
        ExpTree *node = malloc(sizeof(*node));
        node->type = VARIABLE;
        node->value = extract_variable(exp, position);
        return node;
    }
    else
    {
        printf("Warning: unexpected character %c in location %d\n", exp[*position], *position);
        return NULL;
    }
}




/*****************************************************************************
 *                                                                           *
 *  --------------------------------- main --------------------------------- *
 *                                                                           *
 *****************************************************************************/

int main(int argc, char *argv[])
{

    char tmp[] = "a*x^2 +b*x +ccccc -5";
    const char *d    = "*+-^";

    split(tmp, d);


    return EXIT_SUCCESS;

}

void split(char *tmp, const char *d)
{

    /* dummy_function(); */

    char *t = strtok(tmp, d);

    while (t)
    {
        printf("->@%s@\n", t);
        t = strtok(NULL, d);
        printf("->(%c)\n", *d);
    }
}

/* Obtain a backtrace and print it to stdout. */
void print_trace (void)
{
    void *array[10];
    size_t size;
    char **strings;
    size_t i;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    printf ("Obtained %zd stack frames.\n", size);

    for (i = 0; i < size; i++)
        printf ("%s\n", strings[i]);

    free (strings);
}

/* A dummy function to make the backtrace more interesting. */
void dummy_function (void)
{
    print_trace ();
}


/* -*- vim: set ts=4 sw=4 tw=78 ft=c: -*- */