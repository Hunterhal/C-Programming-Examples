#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int key;
    int height;
    struct node *left, *right;
}node_t;

int get_height( node_t *node)
{
    if( node == NULL)
        return 0;
    
    return node->height;
}

int calc_height( node_t *node)
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

int get_balance( node_t *node )
{
    return get_height( node->left ) - get_height( node->right );
}

void right_rotate( node_t **y_ref )
{
    node_t *x = (*y_ref)->left;
    node_t *T2 = x->right;

    (*y_ref)->left = T2;
    x->right = (*y_ref);

    calc_height( (*y_ref) );
    calc_height( x );

    (*y_ref) = x;
}

void left_rotate( node_t **x_ref )
{
    node_t *y = (*x_ref)->right;
    node_t *T2 = y->left;

    (*x_ref)->right = T2;
    y->left = (*x_ref);

    calc_height( (*x_ref) );
    calc_height( y );

    (*x_ref) = y;
}

void insert(node_t **node_ref, int key)
{
    int balance = 0;

    if( *node_ref == NULL)
    {
        (*node_ref) = malloc(sizeof(node_t));

        (*node_ref)->key = key;
        (*node_ref)->height = 1;

        (*node_ref)->left = NULL;
        (*node_ref)->right = NULL;

        return;
    }

    if( key <= (*node_ref)->key )
    {
        insert( &((*node_ref)->left), key);
    }
    else if( key > (*node_ref)->key )
    {
        insert( &((*node_ref)->right), key);
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

void print_preorder(node_t *node)
{
    if(node == NULL)
        return;

    printf("%d ", node->key);

    print_preorder(node->left);

    print_preorder(node->right);
}

void main()
{
    node_t *root = NULL;

    for(int i = 0; i < 10; i++)
    {
        insert(&root, i);
    }

    print_preorder(root);

    root = NULL;

    insert(&root, 30);
    insert(&root, 15);
    insert(&root, 35);
    insert(&root, 5);
    insert(&root, 20);

    right_rotate(&root);
    left_rotate(&root);

}