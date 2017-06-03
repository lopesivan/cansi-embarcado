#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*#include <assert.h>*/

char **str_split(char *a_str, const char a_delim);

int print_string_char_by_char(const char *a_str);

char *rm_space(char *a_str);

void test(void);
char *strsep(char **stringp, const char *delim);

char **str_split(char *a_str, const char a_delim)

{

    size_t    count       = 0;

    char      **result    = 0,
              *tmp        = a_str,
              *last_comma = 0,
              delim[2];

    delim[0]  = a_delim;
    delim[1]  = 0;

    /* Count how many elements will be extracted. */
    char *s ="+";

    while(*s)
    {
        count = 0;
        tmp = a_str;
        while (*tmp)
        {

            if (*s == *tmp)
            {
                count++;
                last_comma = tmp;
            }
            tmp++;
        }
        s++;
        printf("count = %lu\n", count);
    }


    printf("count = %lu\n", count);

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char *) * count);

    if (result)
    {
        size_t idx  = 0;
        char *token = strtok(a_str, delim);

        while (token)
        {
            /*assert(idx < count);*/
            result[idx++] = strdup(token);
            token         = strtok(0, delim);
        }

        /*assert(idx == count - 1);*/
        result[idx] = 0;
    }

    return result;
}

int main()
{
    char months[] = "a*x+b";
    char **tokens;

    printf("months=[%s]\n\n", months);

    tokens = str_split(months, '+');

    if (tokens)
    {
        int i;
        for (i = 0; tokens[i]; i++)
        {
            printf("month=[%s]\n", tokens[i]);
            free(tokens[i]);
        }
        printf("\n");
        free(tokens);
    }

    char *s = "ivan L";

    if (print_string_char_by_char(s) != EXIT_SUCCESS)
        exit(EXIT_FAILURE);


    char *str = rm_space(s);

    printf("%s\n", str);

    test();
    return EXIT_SUCCESS;
}
/*
 *
 *
          char *token, *string, *tofree;

           tofree = string = strdup("abc,def,ghi");
           assert(string != NULL);

           while ((token = strsep(&string, ",")) != NULL)
                   printf("%s\n", token);

           free(tofree);
 * */

char *rm_space(char *a_str)
{

    char *write, *string, *read;

    write = read = string = strdup(a_str);

    do {
        if (*read != ' ')
            *write++ = *read;

    } while (*read++);

    return string;
}

int print_string_char_by_char(const char *a_str)
{
    while(*a_str)
    {
        printf("-> %c\n", *a_str);
        a_str++;
    }

    return EXIT_SUCCESS;
}

char *strsep(char **stringp, const char *delim)
{
    char *s;
    const char *spanp;
    int c, sc;
    char *tok;

    if ((s = *stringp) == NULL)
        return (NULL);
    for (tok = s;;) {
        c = *s++;
        spanp = delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                *stringp = s;
                return (tok);
            }
        } while (sc != 0);
    }
    /* NOTREACHED */
}


void test(void)
{
    char *token, *string, *tofree;

    tofree = string = strdup(rm_space("a*x + b"));

    while ((token = strsep(&string, "*+")) != NULL)
        printf("%s\n", token);

    free(tofree);

}