/*
 * Description: Find the great common divisor between a and b
 * Author: Dat Tran (HE140517)
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

int main()
{
	int a, b;

	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);

	printf("The great common divisor between %d and %d is %d", a, b, findGCD(a, b));

	return 0;
}