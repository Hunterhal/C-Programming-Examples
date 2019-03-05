#include <stdio.h>					//this is the library for input and output functions and macros

#include <math.h>					//mathematics library
#include <string.h>					//string operations library
#include "stdlib.h"					//standart definitions library

/*Structs can have multiple types of variables that hold information*/
//struct type
struct personal_info {
	int age;		//integer
	char *name;		//char pointer for strings
	float height;	//float variable
	char gender;	//char variable
};

/*
This function prints structs
*/
void struct_print(struct personal_info p)
{
	printf("%d, %s, %f\n", p.age, p.name, p.height);
}

/*Main is the most important function, that all C codes must have*/
/*It can take arguements and can return a value*/
/*Program starts inside the main function*/
int main()
{
	struct personal_info p1;	//create struct type variable
	struct personal_info p2;	//create struct type variable
	struct personal_info p3;	//create struct type variable

	p1.age = 29;
	p1.name = "Halil";
	p1.height = 1.80;

	p2.age = 30;
	p2.name = "Gulsum";
	p2.height = 1.55;

	p3.age = 31;
	p3.name = "Neslihan";
	p3.height = 1.70;

	struct_print(p1);
	struct_print(p2);
	struct_print(p3);

	struct personal_info p4;

	p4.age = "halil";
	p4.name = "ASD";
	p4.height = 1.589;
	struct_print(p4);


	getch();
	return 0;
}