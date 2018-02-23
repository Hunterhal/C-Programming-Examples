/* Linked list sample code 23.02.2018
*  Code is based from the http://www.learn-c.org/en/Linked_lists  
*  Halil DURMUÞ ITU BLG221
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Definition of the node of the linked list
It has one value, and next pointer to point next value
*/
typedef struct node {
	int val;
	//float a;
	//char b;
	struct node * next;
} node_t;

/*
This function prints out the list by iterating in the
list until the last node by checking if the next pointer
of the last node is NULL or not
*/
void print_list(node_t * head) 
{
	node_t * current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

/*
This function adds new node to the end of the list
In the while loop function iterates to the end of the 
list by checking NULL. Then new node created and 
added to the end of the list
*/
void add_end(node_t * head, int val) 
{
	node_t * current = head;
	while (current->next != NULL) 
	{
		current = current->next;
	}

	/* now we can add a new variable */
	current->next = malloc(sizeof(node_t));
	current->next->val = val;
	current->next->next = NULL;
}

/*
This function adds new node to the beginning of the 
list. First new node is created, then address of the head
written to this new node. Lastly, new head is changed to the
new node address.
*/
void add_begin(node_t ** head, int val) 
{
	node_t * new_node;
	new_node = malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

/*
This function pops out the first node of the list and 
return its value. Firstly containers of the first node
taken to the another pointer then the memory freed. Lastly,
head pointer updated.
*/
int pop(node_t ** head) 
{
	int retval = -1;
	node_t * next_node = NULL;

	if (*head == NULL) {
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

/*
This function removes the node with given index no
First it checks, if the index is first node. If yes 
runs the pop() function adn returns its value.
If no then code iterates to index. In the meantime code
checks if the list end or not.
When the code iterated to the given index, code uses temp
node to remove indexed node.
*/
int remove_by_index(node_t ** head, int n) {
	int i = 0;
	int retval = -1;
	node_t * current = *head;
	node_t * temp_node = NULL;

	if (n == 0) {
		return pop(head);
	}

	for (i = 0; i < n - 1; i++) {
		if (current->next == NULL) {
			return -1;
		}
		current = current->next;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;
}

/*
This function counts the every node of the list 
by iterating over them. If the head pointer is NULL
then returns 0
*/
int list_size(node_t * head)
{
	int size = 1;
	node_t * current = head;

	if (head == NULL)
		return 0;

	while (current->next != NULL) 
	{
		size += 1;
		current = current->next;
	}

	return size;	 
}

/*
This function searches the list by iterating over
every node. First it checks the head pointer,
wheter it is NULL or not. Then iterates through
the list. Also it checks if the current node is
last one or not. Incase of it can not find returns -1
*/
int list_search(node_t * head, int search)
{
	int index = 0;
	node_t * current = head;

	if (head == NULL)
		return -1;

	do
	{
		if (search == current->val)
		{
			return index;
		}
		current = current->next;
		index++;
	} while (current->next != NULL);

	return -1;
}

int main(void)
{
	//Create the first node of the list
	node_t * head = NULL;
	head = malloc(sizeof(node_t));
	head->val = 1;
	head->next = NULL;

	//Create the second node
	head->next = malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = NULL;

	//Other nodes can be added by using same way
	//head->next = malloc(sizeof(node_t));
	//head->next->next->val = 3;
	//head->next->next->next = NULL;


	//Print the nodes in the list
	puts("List created with two nodes!!!");
	print_list(head);

	//Add node with value 
	add_end(head, 3);
	add_end(head, 4);

	puts("Node three and four added!!!");
	print_list(head);

	add_begin(&head, 0);
	
	puts("Node zero added to list!!!");
	print_list(head);

	int listSize = 0;
	listSize = list_size(head);
	printf("List size is: %d\n", listSize);

	printf("Head of the list has the value of: %d and it's removed\n", pop(&head));
	puts("New list is ");
	print_list(head);

	add_begin(&head, 4);
	add_begin(&head, 12);
	
	add_end(head, 298);
	add_end(head, 47);
	puts("New nodes are added to list, new list is:");
	print_list(head);

	int index = 0;
	int search = 1;
	index = list_search(head, search);

	printf("Index of the %d in the list is: %d\n",search, index);

	puts("To remove the node with given value: First search the index of the value");
	search = 298;
	index = list_search(head, search);
	printf("Index of the %d is: %d\n", search, index);
	puts("Then use remove by index function and print out the list !!!");
	remove_by_index(&head, index);
	print_list(head);

	getchar();
	return 0;
}
