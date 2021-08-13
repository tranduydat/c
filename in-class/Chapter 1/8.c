/*
 * Description: Find the positive integer solutions of the equation ax + by = c
 * Author: Dat Tran
 * Last modified: April 12nd, 2020
 */
 
#include <stdio.h>

int main()
{
	float a, b, c;
	int i, j, count = 0;
	
	printf("Enter a: ");
	scanf("%f", &a);
	printf("Enter b: ");
	scanf("%f", &b);
	printf("Enter c: ");
	scanf("%f", &c);
	
	for (i = 0; i <= a*c; ++i)
		for (j = 0; j <= a*c; ++j)
			if ((a*i + b*j) == c)
			{
				count++;
				printf("\nx%d = %d\ny%d = %d\n", count, i, count, j);
			}
	
	if (count == 0)
		printf("No solution");
		
	return 0;
}
