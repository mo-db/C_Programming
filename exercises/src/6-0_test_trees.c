#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
    int value;
    struct tnode *left;
    struct tnode *right;
} tnode;

tnode *create_node(int value)
{
    tnode *result = malloc(sizeof(tnode));
    if (result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void print_tabs(int level)
{
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
}

void print_tree(tnode *tn)
{
    static int level = 0;
    if (tn == NULL) {
        printf("---<empty>---\n");
    }
    print_tabs(level++);
    printf("%d\n", tn->value);
    if (tn->left != NULL) {
        print_tree(tn->left);
    }
    if (tn->right != NULL) {
        print_tree(tn->right);
    }
    level--;
}

int insert_number(tnode **root_ptr, int value)
{
    tnode *root = *root_ptr;
    if (root == NULL) {
        // tree empty
        *root_ptr = create_node(value);
        return 1;
    }
    if (root->value == value) {
        // do nothing (add count to do)
        return 0;
    }
    if (value < root->value) {
        insert_number(&(root->left), value);
    } else {
        insert_number(&(root->right), value);
    }
    return 1;
}

int main()
{
    tnode *root = NULL;
    int ary[] = { 1, 5, 3, 5 };

    int chck = 1;
    for (int i = 0; i < 4; i++) {
        chck = insert_number(&root, ary[i]);
        if (!chck) { break; }
    }

    print_tree(root);

    return 0;
}
