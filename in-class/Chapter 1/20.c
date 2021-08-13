/*
 * Description: Calculate the Power of a Number (!math.h)
 * Author: Dat Tran
 * Last modified: April 16th, 2020
 */
#include <stdio.h>

int pow(int base, int expo)
{
	long int result = 1, absExpo;

	if (expo < 0)
		absExpo = (-1)*(expo);
	else
		absExpo = expo;

	while (absExpo != 0)
	{
		result *= base;
		--absExpo;
	}

  	return result;
}

int main()
{
	int base, expo;

	printf("Enter x: ");
	scanf("%d", &base);
	printf("-------\nEnter y: ");
	scanf("%d", &expo);

	if (expo < 0)
		printf("-------\n%d^%d = 1/%d", base, expo, pow(base, expo));
	else
		printf("-------\n%d^%d = %d", base, expo, pow(base, expo));

	return 0;
}
