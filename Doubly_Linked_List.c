/* This is code based from the website below to demonstrate 
doubly linked lists in the lecture, please refer to site:
https://www.geeksforgeeks.org/doubly-linked-list/
Remove by index function added to code
Halil DURMUÞ 02.03.2018
BLG221 Data Structures ITU
*/


#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
};

/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. Make next of new node as head and previous as NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* 5. move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;  /* used in step 5*/

									/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so
	make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
	node as head */
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}

/*This function removes the indexed node of the list
It needs some improvments, such as index = 0
*/
int remove_by_index(struct Node** head_ref, int index)
{
	int i = 0;
	int retval = -1;
	struct Node* current_node = *head_ref;
	struct Node* temp_node = NULL;

	for (i = 0; i < index - 1; i++) {
		if (current_node->next == NULL) {
			return -1;
		}
		current_node = current_node->next;
	}

	current_node->prev->next = current_node->next;
	current_node->next->prev = current_node->prev;
	retval = current_node->data;

	free(current_node);

	return retval;
}

// This function prints contents of linked list starting from the given node
void printList(struct Node *node)
{
	struct Node *last = node;
	printf("\nTraversal in forward direction \n");
	while (node != NULL)
	{
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL)
	{
		printf(" %d ", last->data);
		last = last->prev;
	}
	puts("");
}

/* Drier program to test above functions*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	// Insert 6.  So linked list becomes 6->NULL
	append(&head, 6);

	// Insert 7 at the beginning. So linked list becomes 7->6->NULL
	push(&head, 7);

	// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
	push(&head, 1);

	// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
	append(&head, 4);

	printf("Created DLL is: ");
	printList(head);

	puts("Node with index two removed");
	remove_by_index(&head,2);
	printList(head);

	getchar();
	return 0;
}