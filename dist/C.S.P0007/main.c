/**
 * C.S.P0007
 * Remove unnecessary blank in a string 
 * 
 * Author: Tran Duy Dat (HE140517)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_LENGTH_STRING 200

/*
 * Check valid user input
 */
int checkValid(char *str, size_t *strLength) {
    // list of invalid characters
    char checkStr[] = {'@', '#', '!', '[', ']', '{', '}', '(', ')'};

    // i for str, j for checkStr
    int i, j;

    *strLength = strlen(str);
    
    // if user entered nothing (just enter)
    if (*strLength == 1)
        return 0;
    
    // browsing all characters in str
    for (i = 0; i < *strLength - 1; i++)
        // browsing all characters in checkStr
        for (j = 0; j <= 8; j++)
            if (str[i] == checkStr[j])
                return 0;
    return 1;
}

void checkMemAllocation(char *str) {
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(-2);
    }
}

/*
 * Enter an string
 */
void getInput(char **str) {
    // storing the length of str
    size_t strLength;

    *str = (char *) malloc(INIT_LENGTH_STRING * sizeof (char));
    checkMemAllocation(*str);

    // verifying input
    do {
        printf("Please enter a string: ");
        fflush(stdin);
        fgets(*str, INIT_LENGTH_STRING, stdin);

        // check special characters and empty line
        if (checkValid(*str, &strLength) == 0)
            printf("Invalid input. We don't allow enter special characters such as @, #, !, [, ], {, }, (, ) or leave an empty line\nPlease try again!\n\n");
    } while (checkValid(*str, &strLength) == 0);

    *str = (char *) realloc(*str, strLength * sizeof (char));
    checkMemAllocation(*str);
}

/*
 * Remove all unnecessary blank in the string 
 */
void removeBlankStr(char *str, char **trimStr) {
    size_t strLength = strlen(str);

    char *newStr = (char *) malloc(strLength * sizeof (char));
    checkMemAllocation(newStr);

    // i for str, j for trimStr
    int i = 0, j = 0;
    // finding and trimming unnecessary blank character
    while (str[i] != '\0') {
        if (!(str[i] == ' ' && str[i + 1] == ' ')) {
            newStr[j] = str[i];
            j++;
        }
        i++;
    }
    // ending trimmed string with NULL character
    newStr[j] = '\0';

    size_t trimStrLength = strlen(newStr);
    newStr = (char *) realloc(newStr, trimStrLength * sizeof (char));
    checkMemAllocation(newStr);

    *trimStr = (char *) malloc(trimStrLength * sizeof (char));

    // copying newStr -> trimStr
    strcpy(*trimStr, newStr);

    free(newStr);
}

void printResult(char *trimStr) {
    printf("The string after removing: %s", trimStr);
}

int askContinue(short *isContinue) {
    char userChoice;

    printf("Do you wish to continue? Y/N ");
    fflush(stdin);
    scanf("%c", &userChoice);

    // if press 'y' or 'Y', then continue
    if (userChoice == 'y' || userChoice == 'Y')
        *isContinue = 1;
        // otherwise, exit
    else
        *isContinue = 0;
}

int main() {
    char *str;
    char *trimStr;
    short isContinue;

    do {
        getInput(&str);
        removeBlankStr(str, &trimStr);
        printResult(trimStr);
        askContinue(&isContinue);

        free(trimStr);
        free(str);
    } while (isContinue == 1);

    return EXIT_SUCCESS;
}