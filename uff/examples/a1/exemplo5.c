#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <assert.h>*/

int print_string_char_by_char(const char *string);

char *new_string_without_white_spaces(char *source);

char *strsep(char **string, const char *delim);

int main()
{

    char *token, *string, *tofree;

    /* tofree = string = strdup("    a*x + b"); */
    tofree = string = new_string_without_white_spaces("    a*x + b");

    while ((token = strsep(&string, "*+-")) != NULL){
        printf("->%s\n", token);
    }

    free(tofree);

    char *s = "w  jj bb";
    tofree = string = new_string_without_white_spaces(s);
    print_string_char_by_char(string);
    free(tofree);

    return EXIT_SUCCESS;
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
    while(*string)
    {
        printf("-> %c\n", *string);
        string++;
    }

    return EXIT_SUCCESS;

}

char *strsep(char **string, const char *delim)
{
    char       *s;

    const char *spanp;

    int        c,
               sc;

    char       *token;

    if ((s = *string) == NULL)
        return (NULL);

    for (token = s;;)
    {
        c     = *s++;
        spanp = delim;

        do {
            if ((sc = *spanp++) == c)
            {
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

