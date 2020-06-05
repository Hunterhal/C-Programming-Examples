#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int val;
    struct node *next;
}node_t;

typedef struct student_node{
    node_t *head;
    struct student_node *next;
}student_node_t;

typedef struct stack{
    student_node_t *stack_head;
    int size;
}stack_t;

char* student_id_generator()
{
    int faculty_number = 0;
    int year = 0;
    int id = 0;
    char *student_num;

    student_num = malloc( sizeof(char) * 10 );

    id = rand() % 10000;
    year = 10 + rand() % 11;
    faculty_number = 700 + rand() % 10;

    sprintf(student_num, "%d%d%04d\0", faculty_number, year, id);
    puts(student_num);

    return student_num;
}

// Insert student numbers to stack
void push_number( node_t **head_ref, int val )
{
    node_t *new_node = malloc( sizeof(node_t) );
    new_node->val = val;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Insert new student id
void push_id( stack_t* s, node_t *head)
{
    student_node_t *new_node = malloc( sizeof(student_node_t) );
    new_node->head = head;
    new_node->next = s->stack_head;
    s->stack_head = new_node;
    s->size++;
}

void print_list( stack_t *s )
{
    node_t *temp_number = NULL;
    student_node_t *temp_id = s->stack_head;
        
    printf("Student Numbers: \n");
    for(; temp_id != NULL; temp_id = temp_id->next)
    {
        for(temp_number = temp_id->head; temp_number != NULL; temp_number = temp_number->next)
            printf("%d", temp_number->val);
        printf("\n");
    }
}

int pow( int base, int power )
{
    if(power == 0)
        return 1;
    if(power == 1)
        return base;
    return base * pow(base, power - 1);
}

int get_number( node_t *head )
{
    int counter = 0;
    int number = 0;
    for(node_t *temp=head; temp!=NULL; temp = temp->next)
    {
        if(counter > 4)
        {
            number += temp->val * pow(10, (8 - counter));
        }
        counter++;
    }
    return number;
}

int get_year( node_t *head )
{
    int counter = 0;
    int year = 0;
    for(node_t *temp=head; temp!=NULL; temp = temp->next)
    {
        if(counter == 3 || counter == 4)
        {
            year += temp->val * pow(10, (8 - counter));
        }
        counter++;
    }
    return year;
}

void FrontBackSplit(student_node_t* source, student_node_t** frontRef, student_node_t** backRef) 
{ 
    student_node_t* fast; 
    student_node_t* slow; 
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

student_node_t* SortedMerge(student_node_t* a, student_node_t* b) 
{ 
    student_node_t* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (get_year(a->head) <= get_year(b->head)) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 

void merge_sort( student_node_t** head_ref)
{
    student_node_t *temp = (*head_ref);
    student_node_t* a; 
    student_node_t* b; 

    if( temp == NULL || temp->next == NULL  )
        return;
  
    FrontBackSplit(temp, &a, &b); 
  
    merge_sort(&a); 
    merge_sort(&b); 

    *head_ref = SortedMerge(a, b); 
}

void main()
{
    srand(time(NULL));
    node_t *head = NULL;
    char *id;

    stack_t *student_list = malloc( sizeof(stack_t) );
    student_list->stack_head = NULL;
    student_list->size = 0;
    

    for(int i=0; i<1000; i++)
    {
        head = NULL;
        id = student_id_generator();
        for(int j = 8; j>=0; j--)
        {
            push_number( &head, id[j] - 48);

        }

        push_id( student_list, head );
    }

    puts("");
    print_list( student_list );

    printf("%d", get_number(student_list->stack_head->head));

    merge_sort( &student_list->stack_head );

    puts("");
    print_list( student_list );
}