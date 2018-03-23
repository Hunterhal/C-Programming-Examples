/* Recursive Print Example 23.03.2018
*  Halil DURMUÞ ITU BLG221
*/

#include <stdio.h>
#include <stdlib.h>

void iteration_print(int times)
{
	int i;
	for (i = 1; i <= times; i++)
		printf("Iteration print: %d\n", i);
}

void recursive_before_print(int times)
{
	if (times == 0)
		return;
	printf("Before recursion print: %d\n", times);
	recursive_before_print(times - 1);
}

void recursive_after_print(int times)
{
	if (times == 0)
		return;
	recursive_after_print(times - 1);
	printf("After recursion print: %d\n", times);
}

int main(void)
{
	int times = 5;
	printf("Iteration print %d times\n", times);
	iteration_print(times);
	printf("-------------------------------------\n");

	printf("Before recursion print %d times\n", times);
	recursive_before_print(times);
	printf("-------------------------------------\n");

	printf("After recursion print %d times\n", times);
	recursive_after_print(times);

	getchar();
	return 0;
}