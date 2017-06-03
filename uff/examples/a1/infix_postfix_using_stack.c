#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50

char infix[SIZE], postfix[SIZE], Stack[SIZE];
int top = -1;

int braces(char *);
int precedence(char ch);
void push(char ch);
char pop();
char topelement();

int braces(char *s)
{
    int leftbr = 0, rightbr = 0, i;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(')
            leftbr++;
        else if (s[i] == ')')
            rightbr++;
    }
    if (leftbr == rightbr)
        return 0;
    else if (leftbr < rightbr)
        return 1;
    else if (leftbr > rightbr)
        return -1;

    return EXIT_FAILURE;
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
        Stack[top] = ch;
    }
    return;
}

char pop()
{
    char ret;
    if (top != -1) {
        ret = Stack[top];
        top--;
        return ret;
    } else
        return '#';
}

char topelement()
{
    char ch;
    if (top != -1)
        ch = Stack[top];
    else
        ch = '#';
    return ch;
}



int main()
{
    int i, j = 0, chk;
    int popped, pre, prep;
    char ele, elem;
    strcpy(postfix, " ");

    printf("\nEnter the infix expression :");
    scanf("%s", infix);
    chk = braces(infix);

    if (chk != 0) {
        printf("\nUnbalanced no. of braces");
        printf("\n Extra %s", (chk == 1 ? "right bracrs" : "left braces"));
        exit(1);
    }

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] != '(' && infix[i] != ')' && infix[i] != '/'
            && infix[i] != '*' && infix[i] != '+' && infix[i] != '-'
            && infix[i] != '^')
            postfix[j++] = infix[i];
        else if (infix[i] == '(') {
            elem = infix[i];
            push(elem);
        } else if (infix[i] == ')') {
            while ((popped = pop()) != '(')
                postfix[j++] = popped;
        } else {
            elem = infix[i];
            pre = precedence(elem);
            ele = topelement();
            prep = precedence(ele);
            if (pre > prep)
                push(elem);
            else {
                while (prep >= pre) {
                    if (ele == '#')
                        break;
                    popped = pop();
                    postfix[j++] = popped;
                    ele = topelement();
                    prep = precedence(ele);
                }
                push(elem);
            }
        }
    }
    while ((popped = pop()) != '#')
        postfix[j++] = popped;
    postfix[j] = '\0';
    printf("\nThe postfix expression is : ");
    puts(postfix);

    return 0;
}

