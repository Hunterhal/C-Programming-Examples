/* Hash Function Example 23.03.2018
*  Halil DURMUÞ ITU BLG221
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Fake number holder struct
typedef struct fakeNumber {
	int n1;
	int n2;
	int n3;
}fakeNum;

//Hash Table element, linked list node
typedef struct node {
	fakeNum number;
	struct node * next;
} node_t;

node_t *hashTable[100]; //Global Hash Table
fakeNum book[100]; //Global fake number holder

/*
This function generates fake telephone number
*/
fakeNum generate_fake_number(void)
{
	fakeNum f;
	f.n1 = rand() % 60;
	f.n2 = rand() % 1000;
	f.n3 = rand() % 10000;

	return f;
}

/*
This function calculates the Hash Value according to Shift Folding algorithm
*/
int getHastValue(fakeNum bookPage)
{
	printf("Shift Folding Hash value generator: number is 05%02d - %03d - %04d\n", bookPage.n1, bookPage.n2, bookPage.n3);
	int right, mid, left, hash;

	right = bookPage.n3 % 1000;
	mid = (bookPage.n3 / 1000) + (bookPage.n2 % 100)*10;
	left = (bookPage.n2 / 100) + (bookPage.n1) * 10;
	
	hash = (left + mid + right)%100;

	printf("Hash value is %d\n", hash);

	return hash;
}

/*
This function adds new node to the end of the linked list
*/
void add_end(node_t * head, fakeNum newNumber)
{
	node_t * current = head;

	while (current->next != NULL)
	{
		current = current->next;
	}

	/* now we can add a new variable */
	current->next = malloc(sizeof(node_t));
	current->next->number = newNumber;
	current->next->next = NULL;
}

/*
This function prints out the list by iterating in the
list until the last node by checking if the next pointer
of the last node is NULL or not
*/
void print_list(node_t * head)
{
	node_t * current = head;
	int i = 1;

	while (current != NULL) {
		printf("%d element of current index of Hash Table is: ", i);
		printf("05%02d - %03d - %04d\n", current->number.n1, current->number.n2, current->number.n3);
		current = current->next;
		i++;
	}
}

int main(void)
{
	//Random number generator
	srand(time(NULL));
	int hashValue = 0;

	//Create random values
	for (int i = 0; i < 100; i++)
	{
		book[i] = generate_fake_number();
		printf("%02d th number is 05%02d - %03d - %04d\n", i, book[i].n1, book[i].n2, book[i].n3);
		printf("--------------------------------------------------\n");
		puts("");
	}

	//Initialize Hash Table
	for (int i = 0; i < 100; i++)
	{
		hashTable[i] = NULL;
	}

	//Write down values to the Hash Table
	for (int i = 0; i < 100; i++)
	{
		hashValue = getHastValue(book[i]);

		//Look if indexed element is NULL or not
		if (hashTable[hashValue] == NULL)
		{
			hashTable[hashValue] = malloc(sizeof(node_t));
			hashTable[hashValue]->number = book[i];
			hashTable[hashValue]->next = NULL;
		}
		else
			add_end(hashTable[hashValue], book[i]);
	}

	printf("Hash Table is created !!!\n");
	printf("--------------------------------------------------\n");
	//Print the Hash Table
	for (int i = 0; i < 100; i++)
	{
		//Check if the Hash index is used or not
		if (hashTable[i] == NULL)
		{
			//Only one number in this index
			printf("%d index not used !!!\n", i);
			
		}
		else
		{
			//Hash Table index has multiple numbers
			printf("%d indexed element of the Hash Table has:\n", i);
			print_list(hashTable[i]);
		}
		printf("--------------------------------------------------\n");
	}

	getchar();
	return 0;
}
