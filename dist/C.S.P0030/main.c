/*
 * Assignment:      C.S.P0030
 * Requirement:     Addition of odd/even numbers.
 * Author:          Tran Duy Dat (HE140517)
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN_ELEMENT 1   /* Minium number of elements in an array required */
#define MAX_ELEMENT 10  /* Maximum number of elements in an array required */
#define MIN_VALUE 1     /* Minium value to be accepted in each element value (natural numbers from 1) */

/*
 * Function 1
 * Prompting user to enter the number of elements in array
 */
void getNumElements(size_t *numElements) {
    short isValid;      /* variable to store the return of scanf() */

    printf("Sum Even Odd program\n");

    /* get and check validity of the number of elements from user input */
    while (1) {
        printf("Enter a number of element n=");
        fflush(stdin);
        isValid = scanf("%zu", numElements);

        /* to check input, which should be a natural number
         * less than MAX_ELEMENT and larger than MIN_ELEMENT */
        if (isValid != 1 || *numElements > MAX_ELEMENT || *numElements < MIN_ELEMENT)
            printf("\nInvalid input!\n- This value should be a natural number.\n- The number must be in the range from %d to %d\n\n", MIN_ELEMENT, MAX_ELEMENT);
        else
            break;
    }
}

/*
 * Function 2
 * Prompting user to enter each element value
 */
int* getElementVal(size_t numElements) {
    short isValid;      /* variable to store the return of scanf() */
    int i;              /* number for the index of array arr */

    /* memory allocation for arr, with the length equal
     * to the number of elements (numElements) */
    int *arr = (int *) malloc(sizeof (int) * numElements);
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed for arr in getElementVal()\n");
        exit(-2);
    }

    printf("Input elements:\n");
    /* get and store all the entered number from user */
    for (i = 0; i < numElements; i++) {
        while (1) {
            printf("\tElement %d=", i + 1);
            fflush(stdin);
            isValid = scanf("%d", (arr + i));

            /* if an element either is NOT a number or a negative number
             * then show alert and force user to re-enter this element */
            if (isValid != 1 || arr[i] < MIN_VALUE)
                printf("\tInvalid input!\n\t- Input should be a natural number. Please try again!\n\n");
            else
                break;
        }
    }

    return arr;
}

/*
 * Function 3
 * Sum all even and odd numbers in array
 */
void sumOfElements(int *arr, size_t numElements, unsigned int *sumEven, unsigned int *sumOdd) {
    int i;
    /* browsing through all the elements in array arr */
    for (i = 0; i < numElements; i++) {
        if (arr[i] % 2 == 0)
            *sumEven += arr[i];
        else
            *sumOdd += arr[i];
    }
}

/*
 * Function 4
 * Printing out sum of all even and odd numbers in array to the console
 */
void printResult(unsigned int sumEven, unsigned int sumOdd) {
    printf("Sum of Even=%u\n", sumEven);
    printf("Sum of Odd=%u\n\n", sumOdd);
}

int main() {
    size_t numElements;         /* size of array entered from user input */
    int *arr = NULL;            /* array of numbers from user input */
    unsigned int sumEven = 0;   /* number of sum all EVEN numbers */
    unsigned int sumOdd = 0;    /* number of sum of all ODD numbers */

    /* prompting user to enter the number of elements in array */
    getNumElements(&numElements);

    /* to prompt user to enter the value of each element in array */
    arr = getElementVal(numElements);

    /* to sum all the value either even or odd elements in array */
    sumOfElements(arr, numElements, &sumEven, &sumOdd);

    /* printing the sum of */
    printResult(sumEven, sumOdd);

    /* free heap memory for arr */
    free(arr);

    return EXIT_SUCCESS;
}