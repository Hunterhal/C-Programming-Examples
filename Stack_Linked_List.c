/* This is code based from the website below to demonstrate
stack using linked lists in the lecture, please refer to site:
https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
Halil DURMUÞ 02.03.2018
BLG221 Data Structures ITU
*/
// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// A structure to represent a stack
struct StackNode
{
	int data;
	struct StackNode* next;
};

//This function creates new node and retruns the address
struct StackNode* newNode(int data)
{
	struct StackNode* stackNode =
		(struct StackNode*) malloc(sizeof(struct StackNode));
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}

//If root is empty it returns 1
int isEmpty(struct StackNode *root)
{
	return !root;
}

//Push new node to the start of the linked list
void push(struct StackNode** root, int data)
{
	struct StackNode* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
	printf("%d pushed to stack\n", data);
}

//Pop node from the head of the linked list
int pop(struct StackNode** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(struct StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main()
{
	struct StackNode* root = NULL;

	push(&root, 10);
	push(&root, 20);
	push(&root, 30);

	printf("%d popped from stack\n", pop(&root));

	printf("Top element is %d\n", peek(root));

	getchar();
	return 0;
}