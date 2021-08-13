/*
 * Assignment:  C.S.P0031
 * Requirement: Convert decimal to binary
 * Author:      Tran Duy Dat (HE140517)
 */

#include <stdio.h>
#include <stdlib.h>

#define INIT_LENGTH_ARRAY 64

/*
 *  Function 1
 *  Display a screen to prompt users to input a positive decimal number.
 */
void promptInput(int *decimalNum) {
    short isValid;        /* number for storing returning of scanf() */
    char enterChar;

    printf("Convert Decimal to Binary program\n");
    while (1) {
        printf("\tEnter a positive number: ");
        fflush(stdin);
        isValid = scanf("%d%c", decimalNum, &enterChar);

        if (isValid != 2 || enterChar != '\n' || *decimalNum < 0)
            printf("\tInvalid input. Just accept input is decimal number only!\n\n");
        else
            break;
    }
}

/*
 *  Function to reverse an array from start to end
 */
void reverseArr(int *binaryArr, size_t arrayLength) {
    int temp, i;

    for (i = 0; i < arrayLength / 2; i++) {
        temp = binaryArr[i];
        binaryArr[i] = binaryArr[arrayLength - 1 - i];
        binaryArr[arrayLength - 1 - i] = temp;
    }
}

/*
 *  Function 2
 *  The function converts the inputted decimal to corresponding binary
 *  and returns an array containing those converted bits from left to right
 */

int* convertDecBin(int decimalNum, size_t *arrayLength) {
    int *binaryArr = (int *) malloc(INIT_LENGTH_ARRAY * sizeof (int));
    if (binaryArr == NULL) {
        fprintf(stderr, "Memory allocation failed for binaryArr in convertDecBin()\n");
        exit(-2);
    }
    
    /* convert decimal number to corresponding binary format
     * in reversed order */
    int i = 0;           /* index of binaryArr */
    int remainder;
    while (decimalNum != 0) {
        remainder = decimalNum % 2;
        binaryArr[i] = remainder;
        decimalNum = decimalNum / 2;
        i++;
    }

    /* get the size of binaryArr */
    *arrayLength = i;

    binaryArr = (int *) realloc(binaryArr, *arrayLength * sizeof (int));
    if (binaryArr == NULL) {
        fprintf(stderr, "Memory reallocation failed for binaryArr in convertDecBin()\n");
        exit(-2);
    }

    /* reverse binaryArr to obtain the correct bits order */
    reverseArr(binaryArr, *arrayLength);

    return binaryArr;
}

/*
 *  Function 3
 *  Output bits stored in binaryArr to the screen
 */
void displayResult(int *binaryArr, size_t arrayLength) {
    printf("\tBinary number: ");

    int i;
    for (i = 0; i < arrayLength; i++)
        printf("%d", binaryArr[i]);
    printf("\n");
}

/*
 *  Function 4
 *  Ask user either to rerun program or not
 */
void askContinue() {
    printf("Press any key to do another conversion.");

    char isContinue = getchar();

    if (!isContinue)
        exit(0);
    else {
        fflush(stdin);
        fflush(stdout);
        printf("\n");
        main();
    }
}

int main() {
    int decimalNum;         /* decimal number from user input */
    int *binaryArr = NULL;  /* array of decimal number to corresponding binary */
    size_t arrayLength = 0; /* the length of binary array*/

    /* prompt users to input a positive decimal number */
    promptInput(&decimalNum);

    /* convert decimal to binary */
    binaryArr = convertDecBin(decimalNum, &arrayLength);

    /* display converted decimal num to binary to the console */
    displayResult(binaryArr, arrayLength);

    /* free heap memory for binaryArr */
    free(binaryArr);

    /* ask user either to continue or not */
    askContinue();

    return EXIT_SUCCESS;
}