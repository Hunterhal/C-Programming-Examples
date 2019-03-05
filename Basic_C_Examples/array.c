#include <stdio.h>					//this is the library for input and output functions and macros

/*Arrays are static size, they are very basic data structures*/
/*Most important thing with arrays is they start from 0, only MATLAB starts from 1*/

/*Main is the most important function, that all C codes must have*/
/*It can take arguements and can return a value*/
/*Program starts inside the main function*/
int main()
{	
	int test[50];	//create integer array with 50 elements 
	char string[20] = "Hello World!!!"; //create char array called as string and fill it
	int counter = 0;

	printf(string);

	/*Array elements are reached by using index []*/
	/*for loop is a kind of while loop, in for loops first value, condition, and increment is given*/
	for (counter = 0; counter < 50; counter++) //create for loop
	{
		test[counter] = counter * 2;
	}
	for (counter = 49; counter >= 0; counter--)
	{
		printf("%d\n", test[counter]);
	}

	int *p;
	p = test;			//now pointer p, points test[0]
	for (int i = 0; i < 50; i++)	//counter of for loop can be defined inside
	{
		printf("%d\n", *(p++)); //incrementing the value of pointer moves in the list
	}
	/*Since i defined inside for loop it wont work elsewhere*/
	/*Now pointer points to test[49]*/

	p = &test[5];			//now pointer p, points test[5]
	printf("\n%d\n", *p);

	/*Important type of array is char array or string*/
	/*"asd" this is a string contains, a as index 0, s as index 1, d as index 2*/

	char writing[50];
	printf("Write something shorter than 50\n");
	gets(writing);		//gets is specialized version of scanf to get only strings

	for (int i = 0; i < 50; i++)
	{
		if (writing[i] == NULL)		  //gets places NULl to the end of string if there is space left
		{
			puts("\nEnd of string!!!"); //Puts adds new line
			break;
		}
		else
			printf("%c", writing[i]);
	}
	printf("\n");		//print new line
	puts(writing);		//puts is specialized version of puts to show strings

	getch();
	return 0;
}