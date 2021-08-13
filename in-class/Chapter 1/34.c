/*
 * Description: Simple Fibonacci calculator
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// A. Find Nth Fibonacci number
int fiboN(int n)
{
  	double phi = (1 + sqrt(5)) / 2;

  	return round(pow(phi, n) / sqrt(5));
}

// B. Find a Fibonacci number under M
int fiboLessM(int m)
{
	unsigned long long int prevN = 1, nextN = 1, currN = 0;

	while (currN <= m)
	{
		currN = prevN + nextN;

		if (currN >= m)
			break;

		prevN = nextN;
		nextN = currN;
	}

	return nextN;
}

// C. Calculating the sum of M first Fibonacci number(s)
int sumFibo(int m)
{
	unsigned long long int prevN = 1, nextN = 1, currN = 0, sum = 2;
	unsigned int index = 3;

	if (m == 1)
		return 1;
	else if (m == 2)
		return 2;

	while (index <= m)
	{
		currN = prevN + nextN;
		sum = sum + currN;
		prevN = nextN;
		nextN = currN;
		index++;
	}

	return sum;
}

// D. Check whether N is a fibonacci number or not?
bool isFibo(int n)
{
	unsigned long long int prevN = 1, nextN = 1, currN = 0;

	if (n == 1)
		return true;

	while (currN <= n)
	{
		currN = prevN + nextN;

		if (currN == n)
			return true;

		prevN = nextN;
		nextN = currN;
	}

	return false;
}

// E. Enter a number n and analyze n into the sum of the different Fibonacci numbers
void analFibo(int n)
{
	unsigned long long int prevN = 1, nextN = 1, currN = 0;

	if (isFibo(n))
		while (currN <= n)
		{
			currN = prevN + nextN;
			printf("%lld %c ", prevN, nextN >= n ? ' ' : '+');
			prevN = nextN;
			nextN = currN;
		}
	else
		printf("%d is not a Fibonacci number. Please try again!", n);

}

int main()
{
	short userChoice;
	unsigned int n, m;

	printf("SIMPLE FIBONACCI CALCULATOR (Ex.34 by Dat Tran)\n------\n1. Find Nth Fibonacci number\n2. Find a Fibonacci number under M\n3. Calculating the sum of M first Fibonacci number(s).\n4. Check whether N is a fibonacci number or not?\n5. Enter a number n and analyze n into the sum of the different Fibonacci numbers.\n------\nEnter your choice> ");
	scanf("%d", &userChoice);
	puts("\n------");

	system("cls");

	switch(userChoice)
	{
		case 1:
		case 4:
		case 5:
			printf("Enter n: ");
			scanf("%d", &n);

			if (userChoice == 1)
				printf("------\n1. Find Nth Fibonacci number\nThe result is> %ld", fiboN(n));
			else if (userChoice == 4)
				printf("------\n4. Check whether %d is a fibonacci number or not?\nThe answer is> %s", n, isFibo(n) ? "Yep!" : "Nope!");
			else if (userChoice == 5)
			{
				printf("------\n5. Analyze %d into the sum of the different Fibonacci numbers\nThe result is> %d = ", n, n);
				analFibo(n);
			}
			break;
		case 2:
		case 3:
			printf("Enter m: ");
			scanf("%d", &m);

			if (userChoice == 2)
				printf("------\n2. Find a Fibonacci number under %d\nThe result is> %lld", m, fiboLessM(m));
			else if (userChoice == 3)
				printf("------\n3. Calculating the sum of %d first Fibonacci number(s).\nThe result is> %lld", m, sumFibo(m));
			break;
		default:
			puts("Error (>_<), Invalid input!");
	}

	return 0;
}
