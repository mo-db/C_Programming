#include <stdlib.h>
#include <stdio.h>

struct lnode {
    int value;
    struct lnode *next;
};

void print_list(struct lnode *);
struct lnode *create_new_node(int);
struct lnode *insert_at_head(struct lnode *, struct lnode *);


int main()
{
    struct lnode *head = NULL;
    struct lnode *tmp;

    for (int i = 0; i < 25; i++) {
        tmp = create_new_node(i);
        head = insert_at_head(tmp, head);
    }
    
    print_list(head);

    return 0;
}

void print_list(struct lnode *head_ptr)
{
    struct lnode *temp_ptr = head_ptr;

    while (temp_ptr != NULL) {
        printf("%d - ", temp_ptr->value);
        temp_ptr = temp_ptr->next;
    }
    printf("\n");
}

struct lnode *create_new_node(int value)
{
    struct lnode *result = malloc(sizeof(struct lnode));
    result->value = value;
    result->next = NULL;
    return result;
}

struct lnode *insert_at_head(struct lnode *node_to_insert, struct lnode *head)
{
    node_to_insert->next = head;
    return node_to_insert;
}
