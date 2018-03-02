/* Linked list sample code 02.03.2018
*  GPS string parser
*  Halil DURMUÞ ITU BLG221
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGSIZE (int)100

/*
Definition of the node of the linked list
Value is string with size 10
*/
typedef struct node {
	char data[10];
	struct node * next;
} node_t;

/*
This function adds new node to the end of the list
if the list is empty creates the first node
*/
node_t * addNodeToEnd(node_t ** head)
{
	node_t * current = *head;

	if (current == NULL)
	{
		current = malloc(sizeof(node_t));
		current->next = NULL;
		memset(current->data, 0, 10);
		*head = current;
		return *head;
	}
	while (current->next != NULL)
	{
		current = current->next;
	}

	/* now we can add a new variable */
	current->next = malloc(sizeof(node_t));
	current->next->next = NULL;
	memset(current->next->data, 0, 10);
	return current->next;
}

/*
This function prints out the list by iterating in the
list until the last node by checking if the next pointer
of the last node is NULL or not
*/
void print_list_gps(node_t * head)
{
	node_t * current = head;

	while (current != NULL) {
		puts(current->data);
		current = current->next;
	}
}


int main(void)
{
	//Create the first node of the list
	node_t * head = NULL;
	node_t * last;
	//Example GPS string
	char gpsString[STRINGSIZE] = "dsadasdwqe$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
	int stringCounter = 0;
	int nodeCounter = 0;
	char compareString[6];

	//Print the string
	printf("GPS String is: ");
	puts(gpsString);

	//First find the start of the string
	while (stringCounter < (STRINGSIZE - 6))
	{
		if (gpsString[stringCounter] != '$')
		{
			//If it is not $ go to next elemt of the string
			stringCounter++;
			continue;
		}
		stringCounter++;

		//Get the packet type from the GPS string
		memcpy(compareString, gpsString + stringCounter, 5);
		//end of compare string is NULL
		compareString[5] = NULL;

		//Check if it is the same packet type
		if (strcmp("GPGGA", compareString) == 0)
		{
			head = NULL;
			break;
		}

		//If not continue to search in the string
		stringCounter++;
	}

	//While it is not '*' character and not the end of GPS string
	while ((gpsString[stringCounter] != '*') && (stringCounter < (STRINGSIZE - 6)))
	{
		//Reset node counter of the node of the list
		nodeCounter = 0;

		//Add node to the end of the list and get it's address
		last = addNodeToEnd(&head);

		//While it is not ',' character get the data from GPS string to last node of the list
		while (gpsString[stringCounter] != ',')
		{
			//Get data from list
			last->data[nodeCounter] = gpsString[stringCounter];
			nodeCounter++;
			stringCounter++;
		}
		stringCounter++;
	}

	//print the parsed GPS list
	print_list_gps(head);

	getchar();
	return 0;
}
