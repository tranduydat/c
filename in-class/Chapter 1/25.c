/*
 * Description: Count the appearance of each digit (from 0 - 9) in a number
 * Author: Dat Tran
 * Last modified: April 26th, 2020
 */
#include <stdio.h>

int main()
{
	long long int nums;
	long int num;
	unsigned int num0 = 0, num1 = 0, num2 = 0, num3 = 0, num4 = 0, num5 = 0, num6 = 0, num7 = 0, num8 = 0, num9 = 0;

	printf("Enter n: ");
	scanf("%lli", &nums);
	puts("---");

	while (nums != 0)
	{
		num = nums % 10;
		switch (num)
		{
			case 0:
				num0++;
				break;
			case 1:
				num1++;
				break;
			case 2:
				num2++;
				break;
			case 3:
				num3++;
				break;
			case 4:
				num4++;
				break;
			case 5:
				num5++;
				break;
			case 6:
				num6++;
				break;
			case 7:
				num7++;
				break;
			case 8:
				num8++;
				break;
			case 9:
				num9++;
				break;
		}
		nums /= 10;
	}

	printf("---\nWe have:\n %d 0's\n %d 1's\n %d 2's\n %d 3's\n %d 4's\n %d 5's\n %d 6's\n %d 7's\n %d 8's\n %d 9's", num0, num1, num2, num3, num4, num5, num6, num7, num8, num9);

	return 0;
}
