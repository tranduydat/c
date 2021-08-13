/*
 * Exercise 13 - Chapter 2
 * Description: Finding the largest negative number in this array
 * Author: Dat Tran
 * Last modified: 17th May, 2020
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	float *pa, emin = 1;
	short sizeArray;
	int i;

	printf("How many elements do you want to put in this array?\n> ");
	scanf("%hd", &sizeArray);

	pa = (float *)malloc(sizeArray * sizeof(float));

	for (i = 0; i < sizeArray; ++i)
	{
		printf("Enter a[%d] = ", i);
		scanf("%f", &pa[i]);

		if (pa[i] < 0)
			if (pa[i] < emin)
				emin = pa[i];
	}

	if (emin != 1)
		printf("\nThe largest negative number in this array = %0.2f\n", emin);
	else
		printf("\nWe can't find any negative number in this array!");

	free(pa);
	return 0;
}
