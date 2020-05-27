#include <stdio.h>
#include <stdlib.h>

/*
 * Function 1
 * Display the screen that prompts users
 * to enter the number of natural numbers.
 */
void getNumberElement(int *numberElement)
{
  do
  {
    printf("Enter a number of element n=");
    scanf("%d%*c", &(*numberElement));

    if (*numberElement > 10 || *numberElement < 1)
      printf("Invalid input. Number of elements must be in the range of 1 to 10\nPlease try again!\n\n");
  }
  while (*numberElement > 10 || *numberElement < 1);
}

/*
 * Function 2
 * Prompt users to input natural numbers
 */
void getValueElement(int *arr, int numberElement)
{
  int i;

  printf("Input elements:\n");

  for (i = 0; i < numberElement; i++)
  {
    printf("\tElement %d=", (i+1));
    scanf("%d%*c", &arr[i]);
  }
}

/*
 * Function 3
 * Sum of odd numbers
 */
long sumOddNumbers(int *arr, int numberElement)
{
  int i;
  long sumOddNums = 0;

  for (i = 0; i < numberElement; i++)
    if (arr[i] % 2 != 0)
      sumOddNums += arr[i];

  return sumOddNums;
}

/*
 * Function 4
 * Sum of even numbers
 */
long sumEvenNumbers(int *arr, int numberElement)
{
  int i;
  long sumEvenNums = 0;

  for (i = 0; i < numberElement; i++)
    if (arr[i] % 2 == 0)
      sumEvenNums += arr[i];

  return sumEvenNums;
}

/*
 * Function 5
 * Output sum of odd and even numbers to the screen
 */
void printSum(long sumEvenNums, long sumOddNums)
{
  printf("Sum of Even=%ld\n", sumEvenNums);
  printf("Sum of Odd=%ld", sumOddNums);
}

int main()
{
  int numberElement;

  printf("Sum Even Odd program\n");

  getNumberElement(&numberElement);

  int *arr = (int *)malloc(numberElement * sizeof(int));

  getValueElement(arr, numberElement);

  long sumEvenNum = sumEvenNumbers(arr, numberElement);
  long sumOddNum = sumOddNumbers(arr, numberElement);

  printSum(sumEvenNum, sumOddNum);

  free(arr);

  return 0;
}
