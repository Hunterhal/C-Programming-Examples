/* This is code based from the website below to demonstrate
stack using linked lists in the lecture, please refer to site:
https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
Halil DURMUÞ 09.03.2018
BLG221 Data Structures ITU
*/
// C program for Hanoi Towers problem using linked list and stack
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

void list(struct StackNode* root)
{
	struct StackNode* temp = root;
	int i = 1;
	if (root != NULL)
	{
		do
		{
			printf("%d node of the stack is: %d\n", i, temp->data);
			temp = temp->next;
			i++;

		} while (temp != NULL);
	}
	else
	{
		puts("Stack is empty !!!");
	}
}

int main()
{
	struct StackNode* stack1 = NULL;
	struct StackNode* stack2 = NULL;
	struct StackNode* stack3 = NULL;

	push(&stack1, 10);
	push(&stack1, 20);
	push(&stack1, 30);

	puts("Contents of the first stack are");
	list(stack1);
	puts("");

	//While until empty, move contents of the 
	//first stack to second stack
	while (!isEmpty(stack1))
	{
		push(&stack2, pop(&stack1));
	}
	puts("Contents of the first stack are");
	list(stack2);
	puts("");

	//While until empty, move contents of the 
	//second stack to third stack
	while (!isEmpty(stack2))
	{
		push(&stack3, pop(&stack2));
	}
	puts("Contents of the first stack are");
	list(stack3);
	puts("");

	puts("Contents of the stack 1 are");
	list(stack1);
	puts("Contents of the stack 2 are");
	list(stack2);

	getchar();
	return 0;
}