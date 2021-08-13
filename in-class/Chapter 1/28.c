/*
 * Description: Simple numbers (under 10) to words converter
 * Author: Dat Tran
 * Last modified: April 17th, 2020
 */

#include <stdio.h>

int main()
{
	short num;
	printf("Enter number: ");
	scanf("%d", &num);
	puts("---");

	switch (num)
	{
		case 0:
			puts("Zero");
			break;
		case 1:
			puts("One");
			break;
		case 2:
			puts("Two");
			break;
		case 3:
			puts("Three");
			break;
		case 4:
			puts("Four");
			break;
		case 5:
			puts("Five");
			break;
		case 6:
			puts("Six");
			break;
		case 7:
			puts("Seven");
			break;
		case 8:
			puts("Eight");
			break;
		case 9:
			puts("Nine");
			break;
		default:
			puts("Please try again!");
	}
	return 0;
}
