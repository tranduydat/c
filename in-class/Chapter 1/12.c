/*
 * Description: Print 
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
		for (i = 2; i <= sqrt(num); ++i)
			if (num % i == 0)
				return 0;
	
	return 1;
}

int main()
{
	int n, m, count = 0;

	do
	{
		printf("Enter n: ");
		scanf("%d", &n);
		printf("Enter m: ");
		scanf("%d", &m);
		if (m <= n)
			printf("m should be larger than n. Wanna exit? Press Ctrl + C\n");
	}
	while (m <= n);

	while (n != m)
	{
		if (isPrime(n) == 1)
		{
			printf("%d ", n);
			++count;
		}
		++n;
	}

	if (count == 0)
		printf("No solution.");

	return 0;
}
