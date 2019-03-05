#include <stdio.h>					//this is the library for input and output functions and macros

#include <math.h>					//mathematics library
#include <string.h>					//string operations library
#include "stdlib.h"					//standart definitions library

#include <custom.h>

/*Include is preprocessor command to include libraries.*/
/*Libraries can be included both using <> or ""*/

#define COEFFCIENT 10						//define macro

/*Macros are not vairables, they are constant values. Used in complier and they cannot change in code*/

/*If functions are defined in main file they must be defined before main or defined*/

/*
This funtcion multiplies the input with pre defined coefficient
in:  int value
out:
*/
int multiply_with_coef_v1(int value)
{
	int result;
	result = value * COEFFCIENT;
	return result;
}

/*
This is shortened version of multiply function
*/
int multiply_with_coef_v2(int value)
{
	int result = value * COEFFCIENT;
	return result;
}

int multiply_with_coef_v3(int value);

/*This is global variable it can be reached anywhere inside this code file*/
int global_variable = 20;

/*
This function changes the global variable
*/
void change_global(int global_value)
{
	global_variable = global_value;
}

/*Main is the most important function, that all C codes must have*/
/*It can take arguements and can return a value*/
/*Program starts inside the main function*/
int main()
{
	/*Functions are used for repeating codes, instead repeating the code, mini code blocks are used*/
	int mul1 = 20;
	int result;

	result = multiply_with_coef_v1(mul1);	//send mul1 to function and assign return to result

	printf("Multiplication of %d with "
		"%d equals to %d\n", mul1, 
		COEFFCIENT, result);				//print result

	/*Functions have local variables, that cannot be changed by other functions*/
	/*But global variables can be manipulated everywhere*/

	printf("Global variable is %d\n", 
		global_variable);					//print global variable

	change_global(mul1 * 100);				//this function changes the value of global variable

	printf("Global variable is %d\n",
		global_variable);					//print global variable

	/*Note that this function didn't return anything, because it has void return*/

	multiply_with_coef_v3(450);				//for this function returning value is not assigned

	/*Functions can be called from other source codes and libraries*/
	/*Inside the custom.h library there is function called calculate free fall time*/

	float time1, height = 10;		//multiple same type vairables can be defined in same line

	time1 = calculate_free_fall_time(height);

	printf("Free fall time from height "
		"%f is %f seconds\n", time1, height);

	printf("Free fall time from height "
		"%f is %f seconds\n", 5.0, calculate_free_fall_time(5.0));

	/*Functions can be called in paranthesis*/

	getch();
	return 0;
}

/*
Version three of multiply function
*/
int multiply_with_coef_v3(int value)
{
	return value * COEFFCIENT;
}