#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "bitree.h"
#include "traverse.h"

typedef enum { root, left, right } Direction;

static
char *new_string(const char *list_of_numbers)
{

    char          *string;

    size_t        size = strlen(list_of_numbers);

    if (size == 0) {
        string = NULL;
    } else {
        string = (char*) malloc(size + 1);

        strcpy(string, list_of_numbers);
    }

    return string;

}


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
/*****************************************************************************
*                                                                            *
*  --------------------------------- main ---------------------------------  *
*                                                                            *
*****************************************************************************/

int main(int argc, char **argv)
{

    BiTree             tree;

    bitree_init(&tree, free);

    /* ax² + bx + c */
    /* insert_char(&tree, "+"); */
    /* insert_char(&tree, "1"); */
    /* insert_char(&tree, "*"); */
    /* insert_char(&tree, "6"); */
    /* insert_char(&tree, "2"); */

    insert_char(&tree, "b");
    insert_char(&tree, "*");
    insert_char(&tree, "b");
    insert_char(&tree, "-");
    insert_char(&tree, "4");
    insert_char(&tree, "*");
    insert_char(&tree, "a");
    insert_char(&tree, "*");
    insert_char(&tree, "c");

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

    return 0;

}
