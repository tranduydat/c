/*
 * Description: Check whether two numbers are relative prime or not
 * Author: Dat Tran
 * Last modified: April 14th, 2020
 */

#include <stdio.h>

int findGCD(int a, int b);

int main()
{
	int a, b;

	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);

	if (findGCD(a, b) == 1)
		printf("%d and %d are relative prime.\n", a, b);
	else
		printf("%d and %d are NOT relative prime.\n", a, b);

	return 0;
}

int findGCD(int a, int b)
{
	int temp;
	while (b != 0)
	{
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}
