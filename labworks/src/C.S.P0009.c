/*
 * Description: Look up the smallest element position in a real array
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define INIT_LENGTH_STRING 500 // character unit
#define INIT_SIZE_ARRAY 500

/*
 * Function 1
 * Enter a real array
 */

int isNumber(char *userInput)
{
  int strLength = strlen(userInput);
  int i;

  for (i = 0; i < strLength; i++)
    if (isdigit(userInput[i]) == 0)
      return 0;
  return 1;
}

void enterArr(int *arr, int *sizeOfArray)
{
    char *userInput = (char *)malloc(INIT_LENGTH_STRING * sizeof(char));

    if (*userInput == NULL)
    {
        printf("Memory allocation for userInput failed!\n");
        free(userInput);
        exit(-1);
    }

    // to check either is number or not
    do
    {
        printf("Please enter size of array: ");
        gets(userInput);

        if (isNumber(*sizeOfArray) == 0)
            printf("Invalid input! Just accept input is number, please try again!\n");
    }
    while (isNumber(*sizeOfArray) == 0);


    // convert string userInput to int
    *sizeOfArray = atoi(userInput);

    // free memory for string userInput
    free(userInput);

    int i;
    for (i = 0; i < *sizeOfArray; i++)
    {
        printf("Element[%d] = ", i);
        scanf("%d%*c", &arr[i]);
    }

    // return arr;
}

void findSmallestElement(int *arr, int sizeOfArray, int *minValue, int *minPosition)
{
    minValue = arr[0];

    int i;
    for (i = 1; i < sizeOfArray; i++)
        if (arr[i] < minValue)
        {
            *minValue = arr[i];
            *minPosition = i;
        }
}

void printResult(int minValue, int minPosition)
{
    printf("The smallest element: %d - Its position: %d\n", minValue, minPosition);
}

int main()
{
    int sizeOfArray, minValue, minPosition;
    int *arr = (int *)malloc(INIT_SIZE_ARRAY * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation for arr failed!\n");
        free(arr);
        exit(-1);
    }

    enterArr(arr, &sizeOfArray);

    arr = (int *)realloc(arr, sizeOfArray * sizeof(int));

    //findSmallestElement(arr, sizeOfArray, &minValue, &minPosition);
    //printResult(minValue, minPosition);

    // print all the elements in arr[]
    free(arr);

    return 0;
}
