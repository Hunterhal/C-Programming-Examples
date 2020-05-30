#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void add_begin( node_t **head_ref, int val) 
{
	node_t * new_node;

    if( (*head_ref) == NULL)
    {
        (*head_ref) = malloc(sizeof(node_t));
        (*head_ref)->val = val;
        (*head_ref)->next = NULL;

        return;
    }

    new_node = malloc(sizeof(node_t));
	new_node->val = val;
	new_node->next = (*head_ref);

	(*head_ref) = new_node;
}

void print_list( node_t *head)
{
    node_t *current = head;
    while(current != NULL)
    {
        printf("%d, ", current->val);
        current = current->next;
    }
}

void brute_force_sort( node_t** head_ref)
{
    node_t *temp = (*head_ref);
    node_t *max_node = (*head_ref);
    node_t *max_node_previous = NULL;
    int max_val = 0;

    if( temp == NULL || temp->next == NULL)
        return;

    max_val = temp->val;
    
    while( temp->next != NULL )
    {
        if( temp->next->val >= max_val )
        {
            max_node = temp->next;
            max_node_previous = temp;
            max_val = temp->next->val;
        }
        temp = temp->next;
    }

    if(max_node_previous != NULL)
    {       
        max_node_previous->next = max_node->next;
        max_node->next = (*head_ref);
        (*head_ref) = max_node;
    }

    brute_force_sort( & ((*head_ref)->next) );
}

int main()
{
    node_t *head = NULL;
    node_t *temp = NULL;
    srand( time(NULL) );

    for(int i = 0; i < 15; i++)
    {
        add_begin( &head, rand() % 50 );
    }

    print_list( head );
    puts("");
    
    brute_force_sort(&head);

    printf("Sorted List: ");
    print_list( head );

    return 0;
}

