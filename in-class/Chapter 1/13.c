/*
 * Description: Print the list of prime numbers from 2 up to n
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
	int limit, i = 1, count = 0;
	
	printf("How many prime numbers do you want to print out?\n> ");
	scanf("%d", &limit);
	
	while (count != limit)
	{
		++i;
		if (isPrime(i) == 1)
		{
			printf("%d ", i);
			++count;
		}
	}
	
	if (count == 0)
		printf("No solution.");
		
	return 0;
}
