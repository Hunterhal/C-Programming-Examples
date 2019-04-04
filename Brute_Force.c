/* Brute Force Example 11.05.2018
*  Halil DURMUÞ ITU BLG221
*  Code is taken from the link, for the lecture
*  https://www.geeksforgeeks.org/radix-sort/
*/
#include "stdio.h"

int find_minimum(int arr[], int n)
{
	int min = arr[0];
	int minIndex = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

void brute_force_sort(int arr[], int n)
{
	int newArray[8];
	int minIndex = 0;
	for (int i = 0; i < n; i++)
	{
		newArray[i] = arr[find_minimum(arr, n)];
		arr++;
		n--;
		printf("%d", newArray[i]);
	}
}

// Driver program to test above functions
int main()
{
	int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int n = sizeof(arr) / sizeof(arr[0]);
	brute_force_sort(arr, n);
	return 0;
}
