/*
 * Description: Find the least common multiple between a and b
 * Author: Dat Tran
 * Last modified: April 13th, 2020
 */

#include <stdio.h>

// find gcd using Euclid's algorithm
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

int findLCM(int a, int b)
{
	
	if (a == b)
		return a;

	int a0 = a, b0 = b;
	while (a != b)
		if (a < b)
			a = a + a0;
		else
			b = b + b0;

	return a;
}

int main()
{
	int a, b;

	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);

	printf("The least common multiple between %d and %d is %d", a, b, findLCM(a, b));
	printf("\nThe least common multiple between %d and %d is %d", a, b, (a*b)/findGCD(a, b));
	return 0;
}