#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INIT_SIZE_ARRAY 64
#define INIT_LENGTH_STRING 100
#define EXIT_FAIL_DYNAMIC_ALLOCATION -2

int isNumber(char *userInput);
void getUserInput(unsigned long *decimalNum);
void reverseArr(int *binaryArr, int binaryArrSize);
int* convertDecimalBinary(unsigned long decimalNum, int *binaryArrSize);
void printResult(int *binaryArr, int binaryArrSize);

int main() {
    int binaryArrSize;
    short isContinue;
    unsigned long decimalNum;

    int *binaryArr = (int *) malloc(INIT_SIZE_ARRAY * sizeof (int));

    if (binaryArr == NULL) {
        printf("Memory allocation for binaryArr in main()\n");
        free(binaryArr);
        exit(EXIT_FAIL_DYNAMIC_ALLOCATION);
    }

    do {
        isContinue = 0;

        getUserInput(&decimalNum);

        binaryArr = convertDecimalBinary(decimalNum, &binaryArrSize);

        binaryArr = (int *) realloc(binaryArr, binaryArrSize * sizeof (int));

        printResult(binaryArr, binaryArrSize);

        printf("Press any key to do another conversion.");
        isContinue = getchar();
        printf("\n");

        free(binaryArr);
    } while (isContinue != 0);

    return 0;
}

/*
 * Function 1
 * Display a screen to prompt user to input a positive decimal number
 */
int isNumber(char *userInput) {
    int strLength = strlen(userInput);
    int i;

    // check all the element in string userInput
    for (i = 0; i < strLength; i++)
        // if any non-numeric character was found, return 0
        if (isdigit(userInput[i]) == 0)
            return 0;
    return 1;
}

void getUserInput(unsigned long *decimalNum) {
    char *userInput = (char *) malloc(INIT_LENGTH_STRING * sizeof (char));

    if (userInput == NULL) {
        printf("Memory allocation failed for userInput string\n");
        free(userInput);
        exit(EXIT_FAIL_DYNAMIC_ALLOCATION);
    }

    do {
        printf("Convert Decimal to Binary program\n");
        printf("\tEnter a positive number: ");
        gets(userInput);

        if (isNumber(userInput) == 0)
            printf("\nInvalid input! Just accept input is positive decimal number\n\n");
        else
            *decimalNum = atoi(userInput);
    } while (isNumber(userInput) == 0);

    // free memory for userInput string
    free(userInput);
}

/*
 * Function 2
 * The program converts the inputted decimal to corresponding binary
 * and returns an array containing those converted bits from left to right.
 */
void reverseArr(int *binaryArr, int binaryArrSize) {
    int temp, i;

    for (i = 0; i < binaryArrSize / 2; i++) {
        temp = binaryArr[i];
        binaryArr[i] = binaryArr[binaryArrSize - 1 - i];
        binaryArr[binaryArrSize - 1 - i] = temp;
    }
}

int* convertDecimalBinary(unsigned long decimalNum, int *binaryArrSize) {
    int remainder;

    int *binaryArr = (int *) malloc(INIT_SIZE_ARRAY * sizeof (int));

    if (binaryArr == NULL) {
        printf("Memory allocation failed for binaryArr\n");
        free(binaryArr);
        exit(EXIT_FAIL_DYNAMIC_ALLOCATION);
    }

    int i = 0;
    while (decimalNum != 0) {
        remainder = decimalNum % 2;
        binaryArr[i] = remainder;
        decimalNum = decimalNum / 2;
        i++;
    }

    // get the size of binaryArr[]
    *binaryArrSize = i;

    binaryArr = (int *) realloc(binaryArr, *binaryArrSize * sizeof (int));

    if (binaryArr == NULL) {
        printf("Memory reallocation failed for binaryArr\n");
        free(binaryArr);
        exit(EXIT_FAIL_DYNAMIC_ALLOCATION);
    }

    // reverse array
    reverseArr(binaryArr, *binaryArrSize);

    return binaryArr;
}

/*
 * Function 3
 * Output bits stored in the array to the screen.
 */
void printResult(int *binaryArr, int binaryArrSize) {
    printf("\tBinary number: ");

    int i;
    for (i = 0; i < binaryArrSize; i++)
        printf("%d", binaryArr[i]);
    printf("\n");
}
