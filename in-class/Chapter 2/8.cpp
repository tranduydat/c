gut

#include <stdio.h>

void enterArray(float *a, int &n)
{
	printf("How many elements do you want to put into this array?\nEnter n: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Enter a[%d]: ", i);
		scanf("%f", &a[i]);
	}
}

void showArray(float *arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("arr[%d] = %.2f\n", i, arr[i]);
}

// Bubble sort
void sortDesc(float *arr, int n)
{
	float temp = arr[0];

	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
}

bool isNumDupl(float *arr, int n, float &num)
{
	for (int i = 0; i < n; i++)
		if (num == arr[i])
			return true;
	return false;
}

int main()
{
	// init array
	float arr[100];

	// the numbers of elements
	int n;

	float x;

	enterArray(arr, n);
	showArray(arr, n);

	printf("\nEnter x: ");
	scanf("%f", &x);

	// a
	sortDesc(arr, n);
	puts("\nThe sorted array in descending order is: ");
	showArray(arr, n);

	// b
	if (isNumDupl(arr, n, x))
		printf("\nHaving the element equals to %0.2f in this array\n", x);
	else
	{
		arr[n] = x;
		n++;

		sortDesc(arr, n);

		printf("\n\nHaving not the element equals to %0.2f in this array.\nThen the element = %0.2f has been added!\nUpdated array (in descending order):\n", x, x);
		showArray(arr, n);
	}

	return 0;
}
