#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "complex.h"
#include "pythagoras.h"
#include "eq4.h"
#include "bitree.h"

typedef enum { root, left, right } Direction;

/*
static
bool isOperator(int c)
{
    int i;
    char legalOps[] = {'+', '-', '*', '/'};

    for (i = 0; i < 4; i++)
        if (c == legalOps[i])
            return true;
    return false;
}
*/

static
void print_preorder(const BiTreeNode *node)
{

    if (!bitree_is_eob(node)) {

        fprintf(stdout, "Node=%s\n", (char *)bitree_data(node));

        if (!bitree_is_eob(bitree_left(node)))
            print_preorder(bitree_left(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_preorder(bitree_right(node));

    }

    return;

}

static
void print_inorder(const BiTreeNode *node)
{

    if (!bitree_is_eob(node)) {

        if (!bitree_is_eob(bitree_left(node)))
            print_inorder(bitree_left(node));

        fprintf(stdout, "Node=%s\n", (char *)bitree_data(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_inorder(bitree_right(node));

    }

    return;

}

static
void print_postorder(const BiTreeNode *node)
{

    if (!bitree_is_eob(node)) {

        if (!bitree_is_eob(bitree_left(node)))
            print_postorder(bitree_left(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_postorder(bitree_right(node));

        fprintf(stdout, "Node=%s\n", (char *)bitree_data(node));

    }

    return;

}

static
int insert_char(BiTree *tree, const char* i)
{

    BiTreeNode         *node,
                       *prev;

    Direction          direction;
    char               *data;

    node      = tree->root;
    direction = root;

    while (!bitree_is_eob(node)) {

        prev = node;

        if (bitree_is_eob(bitree_left(node))) {

            node = bitree_left(node);
            direction = left;
        } else {

            node = bitree_right(node);
            direction = right;

        }

    }

    data = new_string(i);

    if (direction == root)
        return bitree_ins_left(tree, NULL, data);

    if (direction == left)
        return bitree_ins_left(tree, prev, data);

    if (direction == right)
        return bitree_ins_right(tree, prev, data);

    return -1;

}

static
int testTree(void)
{

    BiTree             tree;

    bitree_init(&tree, free);

    /* ax² + bx + c */
    /* insert_char(&tree, "+"); */
    /* insert_char(&tree, "1"); */
    /* insert_char(&tree, "*"); */
    /* insert_char(&tree, "6"); */
    /* insert_char(&tree, "2"); */

    insert_char(&tree, "1");
    insert_char(&tree, "+");
    insert_char(&tree, "6");
    insert_char(&tree, "*");
    insert_char(&tree, "2");

    fprintf(stdout, "Inserting some nodes\n");
    fprintf(stdout, "Tree size is %d\n", bitree_size(&tree));
    fprintf(stdout, "(Preorder traversal)\n");
    print_preorder(bitree_root(&tree));

    fprintf(stdout, "(Inorder traversal)\n");
    print_inorder(bitree_root(&tree));

    fprintf(stdout, "(Postorder traversal)\n");
    print_postorder(bitree_root(&tree));

    fprintf(stdout, "Destroying the tree\n");
    bitree_destroy(&tree);

    return EXIT_SUCCESS;

}

static
int testPythagoras(int argc, char *argv[])
{

    if (argc == 3)
        printf("->"data_fmt"\n",
               pythagoras(atos(argv[1]), atos(argv[2]))

              );
    else
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

static
int testEq2(int argc, char *argv[])
{

    Array       answer;

    Complex     x1,
                x2;

    if (argc == 4) {
        answer = eq2g( atos(argv[1]),
                       atos(argv[2]),
                       atos(argv[3])
                     );

        x1.real = answer[0];
        x1.imag = answer[1];

        x2.real = answer[2];
        x2.imag = answer[3];

        printf("X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n",
                1, realpart(x1),(imagpart(x1)<0.0f)? '-':'+',fabs(imagpart(x1)),
                2, realpart(x2),(imagpart(x2)<0.0f)? '-':'+',fabs(imagpart(x2))
              );

        free(answer);

    } else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}

static
int testEq3(int argc, char *argv[])
{

    Array       answer;

    Complex     x1,
                x2,
                x3;

    if (argc == 5) {
        answer = eq3g( atos(argv[1]),
                       atos(argv[2]),
                       atos(argv[3]),
                       atos(argv[4])
                     );

        x1.real = answer[0];
        x1.imag = answer[1];

        x2.real = answer[2];
        x2.imag = answer[3];

        x3.real = answer[4];
        x3.imag = answer[5];

        printf("X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n",
                1, realpart(x1),(imagpart(x1)<0.0f)? '-':'+',fabs(imagpart(x1)),
                2, realpart(x2),(imagpart(x2)<0.0f)? '-':'+',fabs(imagpart(x2)),
                3, realpart(x3),(imagpart(x3)<0.0f)? '-':'+',fabs(imagpart(x3))
              );

        free(answer);

    } else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}

static
int testEq4(int argc, char *argv[])
{

    Array       answer;

    Complex     x1,
                x2,
                x3,
                x4;

    if (argc == 6) {
        answer = eq4g( atos(argv[1]),
                       atos(argv[2]),
                       atos(argv[3]),
                       atos(argv[4]),
                       atos(argv[5])
                     );

        x1.real = answer[0];
        x1.imag = answer[1];

        x2.real = answer[2];
        x2.imag = answer[3];

        x3.real = answer[4];
        x3.imag = answer[5];

        x4.real = answer[6];
        x4.imag = answer[7];

        printf("X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n"
               "X%u ="data_fmt" %c"data_fmt"*I\n",
                1, realpart(x1),(imagpart(x1)<0.0f)? '-':'+',fabs(imagpart(x1)),
                2, realpart(x2),(imagpart(x2)<0.0f)? '-':'+',fabs(imagpart(x2)),
                3, realpart(x3),(imagpart(x3)<0.0f)? '-':'+',fabs(imagpart(x3)),
                4, realpart(x4),(imagpart(x4)<0.0f)? '-':'+',fabs(imagpart(x4))
              );

        free(answer);

    } else {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;

}

int main(int argc, char *argv[])
{
    printf("argc = <%d>\n", argc);

    switch(argc) {

    case 3:
        if (testPythagoras(argc, argv) == EXIT_FAILURE)
            exit(1);
        break;

    case 4:
        if (testEq2(argc, argv) == EXIT_FAILURE)
            exit(2);
        break;

    case 5:
        if (testEq3(argc, argv) == EXIT_FAILURE)
            exit(3);
        break;

    case 6:
        if (testEq4(argc, argv) == EXIT_FAILURE)
            exit(4);
        break;

    default : /* Optional */
        testTree();
    }

    return EXIT_SUCCESS;

}
