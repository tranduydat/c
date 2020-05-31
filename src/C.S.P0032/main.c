/* 
 * File:   main.c
 * Author: trduy
 *
 * Created on May 31, 2020, 7:14 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INIT_LENGTH_STRING 500

/*
 * Function 1
 * Display a screen to prompt users to input a natural number
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

void getUserInput() {
    char *userInput = (char *) malloc(INIT_LENGTH_STRING * sizeof (char));

    if (userInput == NULL) {
        printf("Memory allocation for userInput failed!\n");
        free(userInput);
        exit(-1);
    }

    // to check either is number or not
    do {
        printf("Please enter size of array: ");
        gets(userInput);

        if (isNumber(userInput) == 1)
            // convert string userInput to int
            *sizeOfArray = atoi(userInput);

        if (isNumber(userInput) == 0 || *sizeOfArray <= 0)
            printf("Invalid input! Just accept input is number and its value should be larger than zero, please try again!\n\n");
    } while (isNumber(userInput) == 0 || *sizeOfArray <= 0);

    // free memory for string userInput
    free(userInput);
}

/*
 * Function 2
 * Calculate sum ò digits in the decimal number
 */
void calcSumDigits()
int main(int argc, char** argv) {
    unsigned int inputNum;

    printf("Sum Digit Program\n");

    getUserInput();

    return (EXIT_SUCCESS);
}

