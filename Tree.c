/* Binary Tree Example 23.03.2018
*  Halil DURMUÞ ITU BLG221
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

/* newNode() allocates a new node with the given data and NULL left and
right pointers. */
struct node* newNode(int data)
{
	// Allocate memory for new node 
	struct node* node = (struct node*)malloc(sizeof(struct node));

	// Assign data to this node
	node->data = data;

	// Initialize left and right children as NULL
	node->left = NULL;
	node->right = NULL;
	return(node);
}

insert(int key, struct node **leaf)
{
	if (*leaf == 0)
	{
		*leaf = (struct node*) malloc(sizeof(struct node));
		(*leaf)->data = key;
		/* initialize the children to null */
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	}
	else if (key <= (*leaf)->data)
	{
		insert(key, &(*leaf)->left);
	}
	else if (key >(*leaf)->data)
	{
		insert(key, &(*leaf)->right);
	}
}

int main()
{
	srand(time(NULL));
	/*create root*/
	struct node *root = NULL;
	
	int tree_size = 100;
	int new_leaf_value;

	root = newNode(50);
	for (int i = 1; i <= tree_size; i++)
	{
		new_leaf_value = rand() % 100;
		insert(new_leaf_value, &root);
	}
	getchar();
	return 0;
}
