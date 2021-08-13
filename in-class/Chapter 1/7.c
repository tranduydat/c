/*
 * Description: Count the sum of 1/i (i = 1, i <= n)
 * Author: Dat Tran
 * Last modified: April 12nd, 2020
 */
#include <stdio.h>

int main()
{
	double sum = 0;
	int i = 0, n;

	do
	{
		printf("Enter n: ");
		scanf("%d", &n);
		
		if (n <= 0)
			printf("n must be greater than 0! If you want to exit, press Ctrl + C\n");
	}
	while (n <= 0);
	
	for (i = 1; i <= n; ++i)
		sum = sum + 1.0/i;

	printf("Sum = %0.3lf\n", sum);
	
	return 0;
}
