#include <stdio.h>							//this is the library for input and output functions and macros
#include <conio.h>
#include <math.h>							//mathematics library
#include <string.h>							//string operations library
#include "stdlib.h"							//standart definitions library

/*Include is preprocessor command to include libraries.*/
/*Libraries can be included both using <> or ""*/

#define COEFFCIENT 10						//define macro

/*Macros are not vairables, they are constant values. Used in complier and they cannot change in code*/

/*If functions are defined in main file they must be defined before main or defined*/

/*Main is the most important function, that all C codes must have*/
/*It can take arguements and can return a value*/
/*Program starts inside the main function*/
int main()
{
	/*Local variable definitions, these can only be used in main function*/
	int a = 5;								//create integer variable named a

	/*Integers are signed variables, to make it unsigned use "unsigned int"*/

	char b = 'a';							//create character variable named b
	long long l = 1e15;						//create long long integer variable named l
	float c = 5.12378;						//create float variable named c
	double d = -10.5468797;					//create double variable named d
	char string[] = "Hello World !!!\n";	//create a string
	
	/*Check for name conventions*/
	/*Variables must not be started with number, they are lower/upper case sensitive*/

	printf(string);							//print string		
	printf("You should test yourself\n\n");	//print pre-defined string

	/* '\n' is a character called newline, look at ASCII table*/

	printf("Integer is %d\n", a);			//print integer value
	printf("Char is %c\n\n", b);			//print character value

	/*Very Important!!! Characters are also integers, look at ASCII table*/
	/*Another thing is chars are defined by ' ' not " ", strings are defined as " "*/

	printf("Char is %c, integer "
		"value is %d\n\n", b, b);			//print char and integer value
	
	/*printf can print more variables read the documentation*/
	/*\n is also character look at ASCII table*/

	printf("Every compiler/CPU has its own vairable lengths !!!\n");
	printf("Default value of integer is %d\n"
		"Default value of char is %d\n"
		"Default value of long long is %d\n"
		"Default value of float is %d\n"
		"Default value of double is %d\n\n",
		sizeof(a), sizeof(b), sizeof(l), sizeof(c), sizeof(d));
	
	/*Function "sizeof" returns the size of the variable, it is standart C function*/

	printf("%d\n", l);						//print long long varaible as integer, overflows
	printf("%lld\n", l);					//it should be printed with ll

	/*Check the printf specifiers and flags*/

	printf("Float value is %f\n", c);
	printf("Only to floating point value is %.2f\n", c);

	printf("Double value is %f\n\n", d);

	/*Operators - Check online*/
	int var1 = 10;							//create variable named as var1 and give value 10
	int var2 = -20;							//create variable named as var2 and give value -20
	int var3;								//create variable named as var3 and don't give value
	var3 = 100;								//change value of var3
	int var4;								//create variable named as var4 and don't give value
	float var5;								//create float varaible named as var5
	float var6;								//create float varaible named as var6

	var4 = var1 + (2 * var2) - var3;		//mathematical operators are same with other languages
	printf("Value of var4: %d\n", var4);		
	printf("Modulo 3 of var2: %d\n", 
		(var2 + 70) % 3);					//mathematical operations can be done in function calls
	var3 = var4 / 46;						//result will be float
	printf("Value of var3: %d\n", var3);	//print value of var3 with floor

	var5 = var4 / 46;						
	printf("Value of var5: %f\n", var5);	//print value of var5 with floor

	/*The value of var5 is floored because the calculation is done in integer manner*/
	/*This issue is solved with TYPE CASTING, there are two solutions*/
	var5 = var4 / 46.0;						//this defines 46 as float
	var6 = (float)var4 / 46;				//this is type casting, now calculation will be in float manner
	printf("Value of var5: %f, Value of var6: %f", var5, var6);

	/*There are more operators check and test them*/

	getch();								//Standard function from stdio, wait for 
	return 0;
}
