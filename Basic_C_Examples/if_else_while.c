#include <stdio.h>					//this is the library for input and output functions and macros

/*Most important thing to keep in mind if, while and for are runs the code inside {}, if () is true*/

/*Main is the most important function, that all C codes must have*/
/*It can take arguements and can return a value*/
/*Program starts inside the main function*/
int main()
{
	int var = 1;	//variable needs initial value or use do - while statement

	/*while is used for loop, code inside the while work while () is true*/
	while (var != 0)	//while the var is not equal to 0 run the following code
	{
		printf("Press: 0 out, 1 print Name, 2 print Age, otherwise Height\n");
		scanf_s("%d", &var); //Scanf is used to get input from keyboard, keep in mind & operator
		
		if (var == 0)
			printf("Loop is broken\n"); //Since only one line code follows if no need for {}

		else if (var == 1)
		{
			printf("Halil\n");
		}
		else if (var == 2)
			printf("29\n");
		else
		{
			printf("1.80\n");
		}
	}

	/*Another type is infinite loop, break can be used to get out of the loop*/
	while (1)	//run in infinite loop
	{
		printf("Guess the Number");
		scanf_s("%d", &var);

		if (var > 5)
			printf("Lower\n");
		else if (var < 5)
			printf("Higher\n");
		else
		{
			printf("Correct\n");
			break;
		}
	}

	/*do-while runs first then checks the while*/
	int down_counter = 20;
	do 
	{
		printf("Down Counter is %d\n", down_counter);
		down_counter--;									//down_counter = down_counter - 1
	} while (down_counter % 10 != 0);

	/*Note that initially while statement is false, regular while statement wouldn't enter {}*/

	/*if-else statements can be built with only if statements*/
	/*But if - else if - else statements goes to correct place in one step*/
	while (1)
	{
		printf("Guess the Number");
		scanf_s("%d", &var);

		if (var > 10)
		{
			printf("Higher than 10\n");
		}
		if (var > 20)		//After first step this if is checked
		{
			printf("Higher than 20\n");
		}
		if (var == 30)		//Then this if checked
		{
			printf("Correct\n");
			break;
		}
		else				//This else only connected to if(var == 30)
		{
			printf("Wrong !!!\n");
		}
	}

	/*Since if else while work in boolean algebra (&& and), (|| or) and (! not) can be used */
	int var1, var2;

	while (1)
	{
		printf("Enter var1 and var2: ");
		scanf_s("%d%d", &var1, &var2);

		if ((var1 == 1) && (var2 == 1))
		{
			printf("Both one\n");
		}
		if (!var1)
		{
			printf("Var1 is zero\n");
		}
		if ((var1 == 0) || (var2 == 0))
		{
			printf("At least one of them one\n");
		}

	}
	/*Last code will run infinitel, since no out command is given*/
	/*This is one of the most possible logical error*/

	getch();
	return 0;
}