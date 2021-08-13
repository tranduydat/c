/*
 * Description: Count zero digit in a number.
 * Author: Dat Tran
 * Last modified: April 16th, 2020
 */

#include <stdio.h>

int main()
{
	long long int nums, num, zeroDigit = 0;

	printf("Enter n: ");
	scanf("%lli", &nums);

	while (nums != 0)
	{
		num = nums % 10;
		if (num == 0)
			zeroDigit++;
		nums /= 10;
	}

	printf("We have %d zero digit(s)", zeroDigit);

	return 0;
}
