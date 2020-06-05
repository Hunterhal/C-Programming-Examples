#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int val;
    struct node *next;
}node_t;

typedef struct student_node{
    node_t *head;
    int id;
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
    year = 15 + rand() % 6;
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
    new_node->id = head->val;
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
        for(temp_number = temp_id->head->next; temp_number != NULL; temp_number = temp_number->next)
            printf("%d", temp_number->val);
        printf("\n");
    }
}

void min_number( stack_t *s )
{
    student_node_t *temp_id = s->stack_head;

    node_t *min_head = s->stack_head->head;

    int min_id = temp_id->id;

    for(; temp_id != NULL; temp_id = temp_id->next)
    {
        if( min_id > temp_id->id)
        {
            min_id = temp_id->id;
            min_head = temp_id->head;
        }
    }

    printf("Smallest Student id is: ");
    for(min_head = min_head->next; min_head != NULL; min_head = min_head->next)
        printf("%d", min_head->val);
    puts("");
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
        push_number( &head, (id[8] - 48) + (id[7] - 48) * 10 +  (id[6] - 48) * 100);
    
        push_id( student_list, head );
    }

    puts("");
    print_list( student_list );
    puts("");
    min_number( student_list );
}