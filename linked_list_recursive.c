#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int key;
    struct node *next;
}node_t;

void add_end(node_t **node_ref, int key)
{
    if(*node_ref == NULL)
    {
        *node_ref = (node_t *) malloc(sizeof(node_t));
        (*node_ref)->key = key;
        (*node_ref)->next = NULL;
        return;
    }

    add_end(&((*node_ref)->next), key);
}

void print_list(node_t **node_ref)
{
    if(*node_ref == NULL)
    {
        return;
    }
    printf("Node Key: %d\n", (*node_ref)->key);
    print_list(&((*node_ref)->next));
}

void func(node_t **ptr_ref, node_t *ptr)
{
    printf("Pointer is: %X, pointer adress is %X\n", ptr, &ptr);
    printf("Pointer ref: %X, pointer ref holds: %X\n", ptr_ref, *ptr_ref);
}

void main()
{
    node_t *head = NULL;
    printf("Head: %X\n", &head);

    func(&head, head);

    for(int i=0; i<5; i++)
    {
        add_end(&head, i);
    }

    print_list(&head);

}