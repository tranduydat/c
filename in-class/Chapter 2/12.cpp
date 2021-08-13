/*
 * Exercise 12 - Chapter 2
 * Description: Finding and printing the 2th maximum value in an array
 * Author: Dat Tran
 * Last modified: 17th May, 2020
 */

#include <stdio.h>

void enterArray(float *arr, int &n)
{
	printf("How many elements do you want to put into this array?\nEnter n: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter a[%d]: ", i);
		scanf("%f", &arr[i]);
	}
}

void showArray(float *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("arr[%d] = %.2f\n", i, arr[i]);
}

void delPos(float *arr, int &n, int position)
{
	for (int i = position; i < n; i++)
		arr[i] = arr[i + 1];
	n--;
}

void checkDupl(float *arr, int &n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] == arr[j])
				delPos(arr, n, j);
}

float findSecondMax(float *arr, int &n)
{
	float temp = arr[0];

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[j] > arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}

	// check duplication value
	checkDupl(arr, n);

	return arr[1];
}

int main()
{
	// init array
	float arr[100];

	int n;

	enterArray(arr, n);
	printf("\nThe array which you entered: \n");
	showArray(arr, n);

	printf("\nThe second max value is %.2f\n", findSecondMax(arr, n));

	printf("Updated array:\n");
	showArray(arr, n);

	return 0;
}
