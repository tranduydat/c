/**
 * C.S.P0007
 * Remove unnecessary blank in a string 
 * 
 * Author: Tran Duy Dat (HE140517)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_LENGTH_STRING 200  // character unit

/*
 *  Checking validity of string str (user input)
 */
int checkValid(char *str, size_t *strLength) {
    // list of invalid 8 characters
    char checkStr[] = {'@', '#', '!', '[', ']', '{', '}', '(', ')'};

    *strLength = strlen(str);

    // if user entered nothing (just enter)
    if (*strLength == 1)
        return 0;

    // i for str, j for checkStr
    int i, j;
    // browsing all characters in str
    for (i = 0; i < *strLength - 1; i++)
        // browsing all characters in checkStr
        for (j = 0; j <= 8; j++)
            if (str[i] == checkStr[j])
                return 0;
    return 1;
}

/*
 *  Checking did the dynamic allocation succeed
 *  Unless showing error alert then exit program (code -2)
 */
void checkMemAllocation(char *str) {
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(-2);
    }
}

/*
 *  Prompting user to enter data to string str
 *  then check validity
 */
void getInput(char **str) {
    // storing the length of str
    size_t strLength;

    *str = (char *) malloc(INIT_LENGTH_STRING * sizeof (char));
    checkMemAllocation(*str);

    do {
        printf("Please enter a string: ");
        fflush(stdin);
        fgets(*str, INIT_LENGTH_STRING, stdin);

        /* checking both invalid characters in string and empty line
         * if entered string is invalid, then show error and redo */
        if (checkValid(*str, &strLength) == 0)
            printf("Invalid input. We don't allow enter special characters such as @, #, !, [, ], {, }, (, ) or leave an empty line\nPlease try again!\n\n");
    } while (checkValid(*str, &strLength) == 0);

    *str = (char *) realloc(*str, strLength * sizeof (char));
    checkMemAllocation(*str);
}

/*
 *  Remove all unnecessary blank in the string
 */
void removeBlankStr(char **str, char **trimStr) {
    // get the length of string str
    size_t strLength = strlen(*str);

    // init temporary string newStr to store raw one
    // char *newStr = (char *) malloc(strLength * sizeof (char));
    *trimStr = (char *) malloc(strLength * sizeof (char));
    //checkMemAllocation(newStr);
    checkMemAllocation(*trimStr);

    // i for str, j for trimStr
    int i = 0, j = 0;
    // finding and trimming unnecessary blank character
    while (*str[i] != '\0') {
        if (!(*str[i] == ' ' && *str[i + 1] == ' ')) {
            /*
                        newStr[j] = str[i];
             */
            *trimStr[j] = &(*str[i]);
            j++;
        }
        i++;
    }
    // ending trimmed string with NULL character
    /*
        newStr[j] = '\0';
     */
    *trimStr[j] = '\0';

    size_t trimStrLength = strlen(*trimStr);
    /*
        newStr = (char *) realloc(newStr, trimStrLength * sizeof (char));
        checkMemAllocation(newStr);
     */

    *trimStr = (char *) realloc(*trimStr, trimStrLength * sizeof (char));
    checkMemAllocation(*trimStr);

    // copying newStr to trimStr
    /*
        strcpy(*trimStr, newStr);
     */

    // free heap memory for newStr
    /*
        free(newStr);
     */
}

/*
 *  Printing trimString, which was removed unnecessary blank character
 */
void printResult(char *trimStr) {
    printf("The string after removing: %s", trimStr);
}

/*
 *  Asking user to rerun this program or not
 */
void askContinue() {
    char userChoice;

    printf("Do you wish to continue? Y/N ");
    fflush(stdin);
    scanf("%c", &userChoice);

    // if enter 'y' or 'Y', then continue
    // otherwise, exit
    if (userChoice == 'y' || userChoice == 'Y') {
        main();
    }
}

int main() {
    char *str; // string of user input
    char *trimStr; // string for storing removed blank

    // prompting user to enter a string, then check validity
    getInput(&str);

    // removing unnecessary blank in str, then pass it to trimStr
    removeBlankStr(&str, &trimStr);

    // printing removed blank string
    printResult(trimStr);

    // free heap memory
    free(trimStr);
    free(str);

    // asking user whether to rerun or not
    askContinue();

    return EXIT_SUCCESS;
}