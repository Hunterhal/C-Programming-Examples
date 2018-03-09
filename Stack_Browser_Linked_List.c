/* This is code based from the website below to demonstrate
stack using linked lists in the lecture, please refer to site:
https://www.geeksforgeeks.org/stack-data-structure-introduction-program/
Halil DURMUÞ 09.03.2018
BLG221 Data Structures ITU
*/
// Browser next - previous program for linked list implementation of stack 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

// Our struct consists of website url and stack pointer
struct StackNode
{
	char url[100];
	struct StackNode* next;
};

//This function creates new node and retruns the address
struct StackNode* newNode(char *data)
{
	struct StackNode* stackNode =
		(struct StackNode*) malloc(sizeof(struct StackNode));
	strcpy_s(stackNode->url, 100, data);
	stackNode->next = NULL;
	return stackNode;
}

//If root is empty it returns 1
int isEmpty(struct StackNode *root)
{
	return !root;
}

//Push new node to the start of the linked list
void push(struct StackNode** root, char* newUrl)
{
	struct StackNode* stackNode = newNode(newUrl);
	stackNode->next = *root;
	*root = stackNode;
}

//Pop node from the head of the linked list
char* pop(struct StackNode** root)
{
	static char popped[100];
	if (isEmpty(*root))
		return NULL;
	struct StackNode* temp = *root;
	*root = (*root)->next;
	strcpy_s(popped, 100, temp->url);
	free(temp);

	return popped;
}

//This function lists the all previous websites
void list(struct StackNode* root)
{
	struct StackNode* temp = root;
	if (isEmpty(temp))
		return;
	do
	{
		puts(temp->url);
		temp = temp->next;
	} while (temp->next != NULL);
}

int main()
{
	int exit = 0;
	struct StackNode* root = NULL;
	char newData[100];
	char currentWebsite[100] = "Homepage";
	push(&root, currentWebsite);
	printf("Current website is: ");
	puts(currentWebsite);

	puts("This is a browser implemantation");
	do 
	{
		puts("Please enter with starting character w");
		puts("To go previus press p, to list stack press l, to clear stack press c,");
		puts("To exit press e, please enter new command");

		gets_s(newData, 100);
		switch (newData[0]) 
		{
			case ('w'): // If new website is entered
				push(&root, currentWebsite);
				
				printf("Current website is: ");
				puts(newData);
				strcpy_s(currentWebsite, 100, newData);
				break;
			case ('p'): //If previous website is selected
				printf("Previous website is: ");
				//Check if the stack is empty or not
				if (!isEmpty(root))
				{
					puts(pop(&root));
				}
				else
					puts("No more previous website !!!");
				break;
			case ('l'): //If all previous website will be listed
				puts("Previous websites:");
				list(root);
				break;
			case('c'): //To clear all previous websites
				puts("All previous websites are deleted !!!");
				while (!isEmpty(root))
				{
					//pop all the nodes until the root == NULL
					pop(&root);
				}
				break;
			case('e'):
				//Close the browser
				puts("Closing browser !!!");
				exit = 1;
			default:
				continue;
		}
	}while (exit != 1);

	getchar();
	return 0;
}