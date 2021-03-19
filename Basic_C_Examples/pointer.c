#include <stdio.h>	//this is the library for input and output functions and macros

/*Main is the most important function, that all C codes must have*/
/*It can take arguements and can return a value*/
/*Program starts inside the main function*/
int main()
{
	int var = 50;								//create integer variable
	int *p = &var;								//create pointer and point the "var" address

	printf("%d\n", *p);							//print pointer
	(*p)++;										//increment the value of p

	/*Note that *p++ will print the next value of pointer */

	printf("Value of pointer: %d\t", *p);		//print the value of pointer p
	printf("Value of variable: %d\n", var);		//print the value of variable
	
	int *q = p;									//create new pointer, equalt to p, 
												//means q now points to var

	printf("Value of pointer q: %d\n", *q);		//print the value of pointer q

	int *r;										//create pointer r
	r = p;										//equal pointer r to p
												//give the adrees that p holds to r
	printf("Value of pointer r: %d\n", *r);		//print the value of pointer r

	/* Note that "int *r" is creation not the value */
	/* "int *r = p" is same as "r = p" */

	(*r)++;										//increment the value of r
	printf("Value of pointer r: %d\n", *r);		//print the value of pointer r
	printf("Value of variable: %d\n", var);		//print the value of variable

	/*Get only the value of pointer to another pointer*/

	int var1;									//create new variable
	int *n = &var1;								//create pointer n
	*n = *p;									//assign the value of pointer p to pointer n also var1
	printf("Value of pointer n: %d\n", *n);		//print the value of variable
	(*n)++;										//increment the value of n
	printf("Value of pointer n: %d\n", *n);		//print the value of pointer n
	printf("Value of variable: %d\n", var);		//print the value of variable

	/*Pointer to a pointer variable*/
	int **pp = &p;								//create pointer to a pointer variable
	/*p points to var, pp points to p*/
	printf("Value of pointer to a pointer "
					"variable: %d\n", **pp);	//print the value of pointer to a pointer variable

	/*Note that **pp is definition */

	*n = 100;									//change value of pointer n also var1
	pp = &n;									//assign pp to n
	printf("Value of pointer to a pointer "
		"variable: %d\n", **pp);				//print the value of pointer to a pointer variable

	/*Pointer to a double pointer*/
	int ***ppp = &pp;
	/*p points to var, pp points to p, ppp points pp*/
	printf("Value of pointer to a double"
		"pointer: %d\n", ***ppp);				//print the value of pointer to a pointer variable

	*ppp = &p;
	printf("Value of pointer to a double"
		"pointer: %d\n", ***ppp);				//print the value of pointer to a pointer variable

	printf("Value of pointer to a pointer "
		"variable: %d\n", **pp);				//print the value of pointer to a pointer variable

	/*&&&ppp = var1 won't work*/

	/*Pointer to a pointer variable pp is also changed*/
	/*Actually *ppp is pp*/
	printf("\n\n\n");
	printf("Adress of pointer p: %d\n", &p);	//print adress of the pointer p
	printf("Value of pointer p: %d\n", p);		//print the pointer p

	printf("Adress of pointer to a pointer"		//print adress of the pointer to a pointer variable
		"variable: %d\n", &pp);

	printf("Value of pointer to a pointer"		//print the pointer pp
		"variable: %d\n", pp);

	printf("Pointed Value of pointer to a pointer"		//print value of the pointer to a pointer variable
		"variable: %d\n", *pp);

	printf("Address of pointer to a double"		//print adress of the pointer to a double pointer
		"pointer: %d\n", &ppp);

	printf("Value of pointer to a double"		//print the pointer ppp
		"pointer: %d\n", ppp);

	printf("Pointed Value of pointer to a double"		//print value of the pointer to a double pointer
		"pointer: %d\n", *ppp);

	printf("Double Pointed Value of value of pointer to"		//print value of value of the pointer to a double pointer
		"a pointer variable: %d\n", **ppp);

	/*Important things are & adress and * value operators*/

	getch();
	return 0;
}
