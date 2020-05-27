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

void FrontBackSplit(node_t* source, node_t** frontRef, node_t** backRef) 
{ 
    node_t* fast; 
    node_t* slow; 
    slow = source; 
    fast = source->next; 
  
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 

node_t* SortedMerge(node_t* a, node_t* b) 
{ 
    node_t* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (a->val >= b->val) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 

void merge_sort( node_t** head_ref)
{
    node_t *temp = (*head_ref);
    node_t* a; 
    node_t* b; 

    if( temp == NULL || temp->next == NULL  )
        return;
  
    FrontBackSplit(temp, &a, &b); 
  
    merge_sort(&a); 
    merge_sort(&b); 

    *head_ref = SortedMerge(a, b); 
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

    get_length( head );
    
    merge_sort(&head);
;
    printf("Sorted List: ");
    print_list( head );

    return 0;
}

