#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;


int main()
{
    node_t *head = NULL;

    node_t *node_1 = NULL;
    node_1 = (node_t*) malloc( sizeof(node_t) );
    node_1->val = 21;
    node_1->next = NULL;

    node_t *node_2 = NULL;
    node_2 = malloc( sizeof(node_t) );
    node_2->val = 29;
    node_2->next = NULL;

    head = node_1;
    node_1->next = node_2;

    node_2->next = malloc( sizeof(node_t) );
    node_2->next->val = 5;
    node_2->next->next = NULL;

    node_t **head_ptr;
    head_ptr = &head;

    node_t *node_0 = NULL;
    node_0 = malloc( sizeof(node_t) );
    node_0->val = 26;
    node_0->next = head;
    
    *head_ptr = node_0;

    node_t *current = head;
    while(current != NULL)
    {
        printf("%d ", current->val);
        current = current->next;
    }


    return 0;
}

