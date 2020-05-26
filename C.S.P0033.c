/**
 * Assignment: C.S.P0033
 * Description: Sum of decimal number
 * Expected LOC: 26
 * Status: Doing
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Step 1
 * ------
 * 	Display a screen to prompt
 * 	users to input the number of decimals
 * 	called n, that will be stored in an array
 */
void getNumberElement(int *inputArr, int *lengthArr)
{
  printf("Dynamic memory allocation\n\tNumber of element s = ");
  scanf("%d", &(*lengthArr));

  inputArr = (int *)malloc(*lengthArr * sizeof(int));
}

/**
 * Step 2
 * ------
 * 	Prompt users to input a number decimals
 */
void getEachElementValue(int *inputArr, int lengthArr)
{
  int i;
  
  for (i = 0; i < lengthArr; i++)
  {
    printf("\tEnter an integer: ");
    scanf("%d", &inputArr[i]);
  }
}

/**
 * Function 3
 * Sum of all inputted decimals
 */
void countSumAll(int *arr, int lengthArr)
{
  int i, temp, remainder;
  long int sum = 0;

  // browsing all the digits of each element and counting the sum of those
  for (i = 0; i < lengthArr; i++)
  {
    // set effective element to process on
    temp = arr[i];

    while (temp != 0)
    {
      remainder = temp % 10;
      sum = sum + remainder;
      temp = temp / 10;
    }
  }
}

/**
 * Function 4
 * Output sum of inputted decimals
 * After completing Function 4, the program should ask users to
 * input any key to repeat the Function 1
 */
void printSum(int *arr, int lengthArr)
{
  system("pause");
  getchar();
}

int main()
{
  int *arr;
  int lengthArr;

  getNumberElement(arr, &lengthArr);
  getEachElementValue(arr, lengthArr);
  countSumAll(arr, lengthArr);

  free(arr);
  return 0;
}
