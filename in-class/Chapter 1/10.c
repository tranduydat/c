/*
 * Author: Dat Tran
 * Description: Printing the multiplication table to the screen
 * Date: April 13th, 2020
 */

#include <stdio.h>

int main()
{
	unsigned short i, j;
	
	puts("Program: Printing the multiplication table to the screen.\n---");
	
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
		{
			printf("%d x %d = %d\n", i, j, i*j);
			
			if (j == 9 && i != 9)
				puts("---");
		}
	
	return 0;
}
