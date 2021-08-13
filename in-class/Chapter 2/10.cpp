/*
 * Exercise 10 - Chapter 2
 * Description: To find the maximum value then print its position in an array
 * Author: Dat Tran
 * Last modified: 16th May, 2020
 */

#include <stdio.h>

// enter an array
void enterArray(float *a, int &sizeArray)
{
	int i;

	printf("How many elements do you want to put into this array?\nEnter n: ");
	scanf("%d", &sizeArray);

	for (i = 0; i < sizeArray; i++)
	{
		printf("Enter a[%d]: ", i);
		scanf("%f", &a[i]);
	}
}

// find the maximum value in an array
void findMax(float *a, int sizeArray)
{
	int i;
	float emax = a[0];

	for (i = 0; i < sizeArray; ++i)
		if (a[i] > emax)
			emax = a[i];

	printf("The maximum value in this array is: %0.2f\n", emax);
	printf("In the position:\n");
	for (i = 0; i < sizeArray; ++i)
		if (a[i] == emax)
			printf("%d%s", i, );
}

int main()
{
	float a[100];
	int sizeArray;

	enterArray(a, sizeArray);
	findMax(a, sizeArray);

	return 0;
}
