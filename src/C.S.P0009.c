/*
 * Description: Look up the smallest element position in a real array
 */

#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE_ARRAY 500

/*
 * Function 1
 * enter a real array
 */
void enterArr(int **arr)
{
  int i, sizeOfArray;

  printf("Please enter size of array: ");
  scanf("%d", &sizeOfArray);

  *arr = realloc(*arr, sizeOfArray * sizeof(int));

  for (i = 0; i < sizeOfArray; i++)
  {
    printf("Element[%d] = ", i);
    scanf("%d", &(*arr[i]));
    getchar();
  }

  return arr;
}

int main()
{
  int *arr = (int *)malloc(10 * sizeof(int));

  enterArr(&arr);

  free(arr);
}
