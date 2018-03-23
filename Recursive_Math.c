/* Recursive Factorial and Power Example 23.03.2018
*  Halil DURMUÞ ITU BLG221
*/
#include <stdio.h>
#include <stdlib.h>

int factorial(int value)
{
	int result;
	if (value == 1)
	{
		printf("Value is 1, recursion end, return 1 !!!\n");
		printf("-------------------------------\n");
		return 1;
	}

	printf("Before recursion value is %d\n", value);
	result = value * factorial(value - 1);
	printf("After recursion value is %d and result is %d\n", value, result);
	return result;
}

int exp(int value, int power)
{
	int result;
	if (power == 1)
	{
		printf("Power is 1, recursion end, return the value !!!\n");
		printf("-------------------------------\n");
		return value;
	}

	printf("Before recursion power is %d\n", value);
	result = value * exp(value, power - 1);
	printf("After recursion power is %d and result is %d\n", power, result);
	return result;
}

int main(void)
{
	int value = 6;
	int power = 6;
	printf("Factorial of %d is %d\n", value, factorial(value));
	printf("-------------------------------\n");
	printf("%d power of %d is %d\n", power, value, exp(value, power));

	getchar();
	return 0;
}