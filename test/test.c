#include <stdio.h>
#include <stdlib.h>

void enterArr(int *arr)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        printf("Enter element[%d] = ", i);
        scanf("%d%*c", &arr[i]);
    }
}

int main()
{
    int *arr = (int *)malloc(6 * sizeof(int));

    enterArr(arr);

    arr = (int *)realloc(arr, 5 * sizeof(int));

    int i;

    for (i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);
}
