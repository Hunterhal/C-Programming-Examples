#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node{
    int key;
    char date[11];
    int cases;
    int deaths;
    struct node *left, *right;
}node_t;

void insert(node_t **node_ref, int key, char *date, int cases, int deaths)
{
    if(*node_ref == NULL)
    {
        *node_ref = malloc(sizeof(node_t));
        (*node_ref)->key = key;
        
        strcpy((*node_ref)->date, date);
        (*node_ref)->cases = cases;
        (*node_ref)->deaths = deaths;

        (*node_ref)->left = NULL;
        (*node_ref)->right = NULL;
        return;
    }

    if( key <= (*node_ref)->key )
    {
        insert( &((*node_ref)->left), key, date, cases, deaths );
    }
    else if( key > (*node_ref)->key )
    {
        insert( &((*node_ref)->right), key, date, cases, deaths );
    }
}

void print_inorder(node_t *node_ref)
{
    if(node_ref == NULL)
        return;

    print_inorder(node_ref->left);

    printf("%d ", node_ref->key);

    print_inorder(node_ref->right);
}

void print_preorder(node_t *node_ref)
{
    if(node_ref == NULL)
        return;

    printf("Key: %d ", node_ref->key);
    printf("Date: %s, Cases: %d, Deaths: %d\n", node_ref->date, node_ref->cases, node_ref->deaths);

    print_preorder(node_ref->left);

    print_preorder(node_ref->right);
}

void print_postorder(node_t *node_ref)
{
    if(node_ref == NULL)
        return;

    print_postorder(node_ref->left);

    print_postorder(node_ref->right);

    printf("%d ", node_ref->key);
}

void func(node_t **ptr_ref, node_t *ptr)
{
    printf("Pointer is: %X, pointer adress is %X\n", ptr, &ptr);
    printf("Pointer ref: %X, pointer ref holds: %X\n", ptr_ref, *ptr_ref);
}

//Calculating Hash, using %100 modulo 100 is not efficient used for demonstrating
int calculate_key(char *buffer)
{
    unsigned long hash = 5381;
    int c;

    while (c = *buffer++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash%59;
}

void main()
{
    node_t *tree = NULL;

    FILE *f;
    char buffer[30];
    char date[10];
    int cases;
    int deaths;

    int key;

    printf("Tree: %X\n", &tree);

    func(&tree, tree);

    //open the file for reading
    f = fopen("covid.txt", "r");

    while(!feof(f))
    {
        fgets(buffer, 30, f);
        sscanf(buffer, "%s %d %d\n", date, &cases, &deaths);
        key = calculate_key(date);
        insert(&tree, key, date, cases, deaths);
    }

    print_preorder(tree);
    puts("");
    print_inorder(tree);
    puts("");
    print_postorder(tree);
}