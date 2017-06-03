If you want to write your own code, the best way is to define your expression in form of a grammar. To easily parse the grammar, it's best to make it simple.

For example, to parse expressions in the form like this (1+(3*4+x)*y)+1, you could write such a grammar:
```
    Expression -> Addition | null
    Addition -> Multiplication RestOfAddition
    RestOfAddition -> null | + Addition
    Multiplication -> Element RestOfMultiplication
    RestOfMultiplication -> null | * Element
    Element -> number | variable | ( Expression )
```

Then in your program, for every non-terminal in this grammar (the ones on the left of ->), you write one function, like this:

```
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
```

Similarly, `Multiplication` and `RestOfMultiplication` would be written as functions.

```
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
```

Where `extract_int` and `extract_variable` are two functions that take the expression and the position on it, go ahead while they are seeing a number (or a letter in the `extract_variable` function) they build the number (variable) from the expression string and return it, setting position to after where they finished.

Note: This is not code for copy paste. It is not complete and lacks sufficient error checking. Some details have been omitted and is offered as a solution to teach how simple parsing is done rather than easiest solution.
