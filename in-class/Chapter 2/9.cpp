/*
 * Exercise 9 - Chapter 2
 * Description: Counting the average of all the negative numbers in an array
 * Author: Dat Tran
 * Last modified: 16th May, 2020
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

float avgNegativeNums(float *arr, int n)
{
    float sumNegativeNums = 0.0;
    unsigned int count = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] < 0)
        {
            sumNegativeNums += arr[i];
            ++count;
        }

    return (float)sumNegativeNums / count;
}
int main()
{
    // init array
    float arr[100];

    int n;

    enterArray(arr, n);
    
    printf("The array which you entered:\n");
    showArray(arr, n);

    printf("The average of negative numbers in this array is: %0.4f\n", avgNegativeNums(arr, n));

    return 0;
}
