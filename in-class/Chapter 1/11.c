/*
 * Description: Check whether n is a prime number or not
 * Author: Dat Tran
 * Last modified: April 13th, 2020
 */

#include <stdio.h>
#include <math.h>

int isPrime(int num)
{
	int i;

	if (num < 2)
		return 0;
	else
		for (i = 2; i*i <= num; ++i)
			if (num % i == 0)
				return 0;

	return 1;
}

int main()
{
	int num;

	printf("Enter n: ");
	scanf("%d", &num);

	if (isPrime(num) == 1)
		printf("%d is a prime number.", num);
	else
		printf("%d is NOT a prime number.", num);

	return 0;
}
