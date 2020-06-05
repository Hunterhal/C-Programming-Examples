#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int val;
    struct node *next;
}node_t;

typedef struct student_node{
    node_t *head;
    int height;
    int key;
    struct student_node *left, *right;
}student_node_t;

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
/*
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
*/
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

int get_height( student_node_t *node)
{
    if( node == NULL)
        return 0;
    
    return node->height;
}

int calc_height( student_node_t *node)
{
    int new_height = 0;
    if( node == NULL )
        return 0;

    if( get_height(node->left) > get_height(node->right))
        new_height = get_height(node->left) + 1;
    else
        new_height = get_height(node->right) + 1;

    node->height = new_height;
}

int get_balance( student_node_t *node )
{
    return get_height( node->left ) - get_height( node->right );
}

void right_rotate( student_node_t **y_ref )
{
    student_node_t *x = (*y_ref)->left;
    student_node_t *T2 = x->right;

    (*y_ref)->left = T2;
    x->right = (*y_ref);

    calc_height( (*y_ref) );
    calc_height( x );

    (*y_ref) = x;
}

void left_rotate( student_node_t **x_ref )
{
    student_node_t *y = (*x_ref)->right;
    student_node_t *T2 = y->left;

    (*x_ref)->right = T2;
    y->left = (*x_ref);

    calc_height( (*x_ref) );
    calc_height( y );

    (*x_ref) = y;
}

void insert(student_node_t **node_ref, node_t *head)
{
    int balance = 0;
    int key = get_number(head);

    if( *node_ref == NULL)
    {
        (*node_ref) = malloc(sizeof(student_node_t));

        (*node_ref)->head = head;
        (*node_ref)->key = key;
        (*node_ref)->height = 1;

        (*node_ref)->left = NULL;
        (*node_ref)->right = NULL;

        return;
    }

    if( key <= (*node_ref)->key )
    {
        insert( &((*node_ref)->left), head);
    }
    else if( key > (*node_ref)->key )
    {
        insert( &((*node_ref)->right), head);
    }

    calc_height( (*node_ref) );

    balance = get_balance( (*node_ref) );

    //AVL Cases
    if(balance > 1)
    {
        //Left Cases
        if( get_balance( (*node_ref)->left) >= 0)
        {
            //Left left
            right_rotate( node_ref );
        }
        else
        {
            //Left right
            left_rotate( &((*node_ref)->left) );
            right_rotate( node_ref );
        }
    }
    else if (balance < -1)
    {
        //Right Cases
        if( get_balance( (*node_ref)->right ) >= 0 )
        {
            //Right left
            right_rotate( &((*node_ref)->right) );
            left_rotate( node_ref );
        }
        else
        {
            //Right right
            left_rotate( node_ref );
        }
    }
}

void print_preorder(student_node_t *node)
{
    if(node == NULL)
        return;

    node_t *temp_number = NULL;

    printf("%d Key student id: ", node->key);
    for(temp_number = node->head; temp_number != NULL; temp_number = temp_number->next)
            printf("%d", temp_number->val);

    printf("\n");

    print_preorder(node->left);

    print_preorder(node->right);
}

/* Given a non-empty binary search tree, return the
node with minimum key value found in that tree.
Note that the entire tree does not need to be
searched. */
student_node_t *minValueNode(student_node_t *node)
{
	student_node_t *current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

/* Given a non-empty binary search tree, return the
node with maximum key value found in that tree.
Note that the entire tree does not need to be
searched. */
student_node_t *maxValueNode(student_node_t *node)
{
	student_node_t *current = node;

	/* loop down to find the leftmost leaf */
	while (current->right != NULL)
		current = current->right;

	return current;
}

student_node_t *deleteNode(student_node_t **node_ref, int key)
{
	if (*node_ref == NULL)
		return (*node_ref);

	if (key < (*node_ref)->key)
		(*node_ref)->left = deleteNode( &((*node_ref)->left), key);

	else if (key > (*node_ref)->key)
		(*node_ref)->right = deleteNode( &((*node_ref)->right), key);

	else
	{
		// node with only one child or no child
		if (((*node_ref)->left == NULL) || ((*node_ref)->right == NULL))
		{
			student_node_t *temp = (*node_ref)->left ? (*node_ref)->left :
				(*node_ref)->right;

			// No child case
			if (temp == NULL)
			{
				temp = (*node_ref);
				(*node_ref) = NULL;
			}
			else // One child case
				(**node_ref) = *temp; // Copy the contents of
							   // the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			student_node_t* temp = minValueNode((*node_ref)->right);

			// Copy the inorder successor's data to this node
			(*node_ref)->key = temp->key;

			// Delete the inorder successor
			(*node_ref)->right = deleteNode(&((*node_ref)->right), temp->key);
		}
	}

	// If the tree had only one node then return
	if ((*node_ref) == NULL)
		return (*node_ref);

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    calc_height( (*node_ref) );

	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = get_balance((*node_ref));

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && get_balance((*node_ref)->left) >= 0)
		right_rotate(node_ref);

	// Left Right Case
	if (balance > 1 && get_balance((*node_ref)->left) < 0)
	{
		left_rotate(&((*node_ref)->left));
		right_rotate(node_ref);
	}

	// Right Right Case
	if (balance < -1 && get_balance((*node_ref)->right) <= 0)
		left_rotate(node_ref);

	// Right Left Case
	if (balance < -1 && get_balance((*node_ref)->right) > 0)
	{
		right_rotate(&((*node_ref)->right));
		left_rotate(node_ref);
	}

	return (*node_ref);
}

void main()
{
    srand(time(NULL));
    node_t *head = NULL;
    char *id;
    student_node_t *tree = NULL;
    student_node_t *deleted = NULL;

    for(int i=0; i<10; i++)
    {
        head = NULL;
        id = student_id_generator();
        for(int j = 8; j>=0; j--)
        {
            push_number( &head, id[j] - 48);
        }

        insert( &tree, head );
    }

    print_preorder( tree );

    printf("\n%d will be deleted\n", tree->right->left->key);
    deleteNode( &tree, tree->right->left->key);
    printf("\n%d is deleted\n", deleted->key);
    print_preorder( tree );
}